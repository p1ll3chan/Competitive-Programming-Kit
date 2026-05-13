# CP Update Automation Setup

## 1. Create Python Generator

#File:

#```bash
#/home/p1ll3chan/Documents/Code_2025/CP_Practice/Competitive-Programming-Kit/scripts/generate_update.py
#```

#---

## Python Script

#```python
import os
import re
import subprocess
import json
import urllib.request
import urllib.error
from datetime import datetime

ROOT = "/home/p1ll3chan/Documents/Code_2025/CP_Practice/Competitive-Programming-Kit"
LOGS_DIR = os.path.join(ROOT, "CP_log_system", "logs")
HEADINGS = [
    "Problem",
    "My Intuition",
    "Approach 1",
    "Why Failed",
    "Approach 2",
    "Example Process",
    "Final Learning",
]
SECTION_BOUNDARY_RE = re.compile(
    r"^\s*(?:(?:" + "|".join(re.escape(h) for h in HEADINGS) + r")\s*:|\*/)",
    re.MULTILINE,
)
OLLAMA_URL = "http://127.0.0.1:11434/api/generate"
OLLAMA_MODEL = "qwen2.5-coder:7b"
OLLAMA_TIMEOUT_SECONDS = 10

os.chdir(ROOT)

# --------------------------------------------------
# GET CHANGED FILES FROM LAST COMMIT
# --------------------------------------------------

try:
    result = subprocess.check_output(
        ["git", "show", "--pretty=format:", "--name-only", "HEAD"],
        text=True,
    )
except subprocess.CalledProcessError:
    print("No previous commit found.")
    result = ""

files = [
    f.strip() for f in result.splitlines()
    if f.strip().endswith(".cpp")
    and "/logs/" not in f"/{f.strip()}"
    and "__pycache__" not in f.strip()
    and "/scripts/" not in f"/{f.strip()}"
]

print("Detected cpp files:", files)


def extract_structured_top_comment(content):
    top_window = content[:8000]
    for match in re.finditer(r"/\*(.*?)\*/", top_window, re.DOTALL):
        block = match.group(1)
        has_problem = re.search(r"^\s*Problem\s*:", block, re.MULTILINE)
        has_learning = re.search(r"^\s*Final Learning\s*:", block, re.MULTILINE)
        if has_problem or has_learning:
            return block
    return None


def extract_section_block(content, label):
    match = re.search(
        rf"^\s*{re.escape(label)}\s*:\s*(.*)$",
        content,
        re.MULTILINE,
    )
    if not match:
        return None

    inline = match.group(1).rstrip()
    rest = content[match.end():]
    boundary = SECTION_BOUNDARY_RE.search(rest)
    block = rest[:boundary.start()] if boundary else rest

    combined = f"{inline}\n{block}" if inline else block
    return combined.strip("\n")


def extract_problem(content):
    block = extract_section_block(content, "Problem")
    if not block:
        return None
    for line in block.splitlines():
        text = line.strip()
        if text:
            return text
    return None


def extract_final_learning(content):
    block = extract_section_block(content, "Final Learning")
    if block is None:
        return None

    lines = block.splitlines()
    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and not lines[-1].strip():
        lines.pop()

    if not lines:
        return None

    return "\n".join(line.rstrip() for line in lines).strip()


def summarize_learning_with_ollama(learning_text):
    if not learning_text:
        return learning_text

    prompt = (
        "Rewrite this competitive programming learning into exactly one concise "
        "WhatsApp-style sentence under 15 words. Keep technical meaning intact. "
        "No bullet points. No quotes. No markdown.\n\n"
        f"Learning: {learning_text}\n\n"
        "Output only the sentence."
    )

    payload = {
        "model": OLLAMA_MODEL,
        "prompt": prompt,
        "stream": False,
    }

    try:
        req = urllib.request.Request(
            OLLAMA_URL,
            data=json.dumps(payload).encode("utf-8"),
            headers={"Content-Type": "application/json"},
            method="POST",
        )
        with urllib.request.urlopen(req, timeout=OLLAMA_TIMEOUT_SECONDS) as response:
            data = json.loads(response.read().decode("utf-8"))

        summary = (data.get("response") or "").strip()
        summary = re.sub(r"[\r\n]+", " ", summary)
        summary = summary.replace('"', "").replace("'", "")
        summary = re.sub(r"^\s*[-*•]+\s*", "", summary)
        summary = re.sub(r"\s+", " ", summary).strip()
        words = summary.split()
        if len(words) > 15:
            summary = " ".join(words[:15]).rstrip(".,;:") + "."
        if not summary or not re.search(r"[A-Za-z0-9]", summary):
            return learning_text
        return summary
    except Exception:
        return learning_text

# --------------------------------------------------
# EXTRACT DATA
# --------------------------------------------------

updates = []

for file in files:

    full_path = os.path.join(ROOT, file)

    if not os.path.exists(full_path):
        continue

    try:
        with open(full_path, "r", encoding="utf-8") as f:
            content = f.read()
        structured_block = extract_structured_top_comment(content)

        # -----------------------------
        # PROBLEM
        # -----------------------------

        problem = (
            extract_problem(structured_block) if structured_block else None
        ) or os.path.basename(file)

        # -----------------------------
        # FINAL LEARNING
        # -----------------------------

        learning = (
            extract_final_learning(structured_block) if structured_block else None
        ) or "No final learning written."
        summarized_learning = summarize_learning_with_ollama(learning)
        print(f"LLM Summary: {summarized_learning}")

        updates.append((problem, summarized_learning))

    except Exception as e:
        print(f"Error reading {file}: {e}")

# --------------------------------------------------
# BUILD MESSAGE
# --------------------------------------------------

now = datetime.now()

date_string = now.strftime("%d %b %Y")

message = f"""
Namah Shivaya Sir,
CP Daily Update

{date_string}
Hours: ___

Problems Solved: {len(updates)}

"""

for i, (problem, learning) in enumerate(updates, start=1):

    message += f"{i}. {problem}\n"
    message += f"→ {learning}\n\n"

message += ""

# --------------------------------------------------
# SAVE TO FILE
# --------------------------------------------------

os.makedirs(LOGS_DIR, exist_ok=True)

output_file = os.path.join(LOGS_DIR, "today_update.txt")

with open(output_file, "w", encoding="utf-8") as f:
    f.write(message)

# --------------------------------------------------
# COPY TO CLIPBOARD
# --------------------------------------------------

clipboard_ok = False
try:
    subprocess.run(
        ["xclip", "-selection", "clipboard"],
        input=message,
        text=True,
        check=True,
    )
    clipboard_ok = True
except FileNotFoundError:
    print("xclip not found. Skipping clipboard copy.")
except subprocess.CalledProcessError:
    print("Clipboard copy failed. Skipping.")

# --------------------------------------------------
# TERMINAL OUTPUT
# --------------------------------------------------

print("\n" + "=" * 60)
print(message)
print("=" * 60)

print(f"\nSaved to: {output_file}")
if clipboard_ok:
    print("Copied to clipboard.")
else:
    print("Clipboard copy skipped.")
