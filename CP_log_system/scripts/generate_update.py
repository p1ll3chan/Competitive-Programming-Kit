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

os.chdir(ROOT)

# --------------------------------------------------
# GET CHANGED FILES FROM LAST COMMIT
# --------------------------------------------------

try:
    result = subprocess.check_output(
        ["git", "diff", "--name-only", "HEAD~1", "HEAD"]
    ).decode()
except:
    print("No previous commit found.")
    exit()

files = [
    f for f in result.splitlines()
    if f.endswith(".cpp")
]

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

        problem_match = re.search(
            r"Problem:\s*(.*?)\n",
            content,
            re.MULTILINE
        )

        problem = (
            problem_match.group(1).strip()
            if problem_match else os.path.basename(file)
        )

        # -----------------------------
        # FINAL LEARNING
        # -----------------------------

        learning_match = re.search(
            r"Final Learning:\s*(.*?)\n",
            content,
            re.MULTILINE
        )

        learning = (
            learning_match.group(1).strip()
            if learning_match else "No final learning written."
        )

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

logs_dir = os.path.join(ROOT, "logs")
os.makedirs(logs_dir, exist_ok=True)

output_file = os.path.join(logs_dir, "today_update.txt")

with open(output_file, "w", encoding="utf-8") as f:
    f.write(message)

# --------------------------------------------------
# COPY TO CLIPBOARD
# --------------------------------------------------

escaped = message.replace('"', '\\"')
os.system(f'echo "{escaped}" | xclip -selection clipboard')

# --------------------------------------------------
# TERMINAL OUTPUT
# --------------------------------------------------

print("\n" + "=" * 60)
print(message)
print("=" * 60)

print(f"\nSaved to: {output_file}")
print("Copied to clipboard.")


