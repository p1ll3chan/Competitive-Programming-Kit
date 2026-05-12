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

        # -----------------------------
        # PROBLEM
        # -----------------------------

        problem = extract_problem(content) or os.path.basename(file)

        # -----------------------------
        # FINAL LEARNING
        # -----------------------------

        learning = extract_final_learning(content) or "No final learning written."

        updates.append((problem, learning))

    except Exception as e:
        print(f"Error reading {file}: {e}")

# --------------------------------------------------
# BUILD MESSAGE
# --------------------------------------------------

now = datetime.now()

date_string = now.strftime("%d %b %Y")

message = f"""🔥 CP Daily Update

📅 {date_string}
⏱ Hours: ___

✅ Problems Solved: {len(updates)}

"""

for i, (problem, learning) in enumerate(updates, start=1):

    message += f"{i}. {problem}\n"
    message += f"→ {learning}\n\n"

message += "🚀 Git Push Completed"

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
