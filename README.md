# Competitive Programming Kit

A personal competitive-programming and DSA archive maintained by **p1ll3chan**. It combines contest solutions, reusable templates, custom helpers, topic practice, problem patterns, and contest logs for self-paced revision.

Languages: **C++ 98.6%**, **Python 1.4%**

## Start Here

- **Preparing for contests:** begin with [`Templete`](./Templete), then use [`custom_function`](./custom_function).
- **Learning a DSA topic:** start in [`DSA_Box`](./DSA_Box) and [`DSA_Pattern`](./DSA_Pattern).
- **Practicing math:** explore [`Math`](./Math).
- **Following a structured problem sheet:** use [`Striver_Sheet`](./Striver_Sheet) and [`ICPC_Assult_U_Sheeet`](./ICPC_Assult_U_Sheeet).
- **Solving judge-specific problems:** browse [`Codeforces`](./Codeforces), [`Codechef`](./Codechef), [`Atcoder`](./Atcoder), or [`Jet-Brains-Camp`](./Jet-Brains-Camp).
- **Reviewing competitive systems and notes:** see [`CP_log_system`](./CP_log_system), [`ATF`](./ATF), and [`logs`](./logs).

## How to Study This Repository

1. Read the problem once and attempt it independently.
2. Review the implementation in the matching platform or topic folder.
3. Identify the core idea: arrays, strings, hashing, greedy, math, or another pattern.
4. Rewrite the solution from memory rather than copying it verbatim.
5. Compare alternate approaches and record a mistake or insight in [`logs`](./logs).
6. Return to rated or contest folders to practice the same idea under time pressure.

## Repository Map

| Folder | What is stored here | Where to start |
|---|---|---|
| [`Templete`](./Templete) | C++ and Python contest templates plus test templates | Open `ICPC_Templete.cpp` for the main C++ setup; use `Python_Templete.py` for Python contests |
| [`custom_function`](./custom_function) | Reusable conversions, frequency functions, permutations, and input helpers | Study `datatype_convert.cpp`, `freq_count_fun.cpp`, `permutation_generator.cpp`, and `size_less_input.cpp` |
| [`DSA_Box`](./DSA_Box) | Direct DSA problem implementations grouped by core data type | Begin with `ARRAY/` for indexing and extractions; continue with `STRING/` |
| [`DSA_Pattern`](./DSA_Pattern) | Pattern-based practice and LeetCode-style notes | Explore `DSA_Leetcode/Hashing/` and use `Welcome.md` as the starting point |
| [`Math`](./Math) | Number-theory and arithmetic implementations | Start with `Sieve, Prime Factorization and Divisors/` before expanding to other topics |
| [`Striver_Sheet`](./Striver_Sheet) | Selected problem solutions associated with a structured DSA sheet | Review `Next Permutation`, `Sort Colors`, `Kadane's Algorithm`, and the Pascal/stock/matrix problems |
| [`ICPC_Assult_U_Sheeet`](./ICPC_Assult_U_Sheeet) | ICPC-oriented problem practice from a study sheet | Use as contest-preparation practice after core templates and helpers are familiar |
| [`Jet-Brains-Camp`](./Jet-Brains-Camp) | Exercises and contest problems from JetBrains Camp practice | Study camp problems by topic and compare them with the reusable kit |
| [`Codeforces`](./Codeforces) | Codeforces contest solutions and difficulty-rated problem sets | Beginners should follow `800-rated`, `900-Rated`, `1100-rated`, and `1200-rated`; contest folders show problem-set practice |
| [`Codechef`](./Codechef) | CodeChef Starter and ICPC-prelim problem solutions | Use the `STARTER_*` folders for timed practice and `ICPC_Prelims_26/` for team-contest preparation |
| [`Atcoder`](./Atcoder) | AtCoder Beginner Contest and daily-training solutions | Start with `Atcoder_Easy_100`, then continue through ABC contests and medium sets |
| [`CP_log_system`](./CP_log_system) | Program or data used to organize competitive-programming progress | Check this folder to understand progress tracking and repeated-practice planning |
| [`ATF`](./ATF) | Algorithm-training and contest-material area | Use it as an additional topic or practice archive |
| [`logs`](./logs) | Personal progress and problem-solving logs | Read before a practice session to identify weak topics and repeat earlier mistakes |
| [`test_cases_gen`](./test_cases_gen) | Tools or examples for test-case generation | Use it to build stress tests and verify solutions against brute-force implementations |
| [`temp.cpp`](./temp.cpp) | Scratchpad or combined competitive-programming template | Copy code cautiously: prefer the maintained files in `Templete/` and `custom_function/` |

## DSA Learning Paths

### Arrays

Use [`DSA_Box/ARRAY`](./DSA_Box/ARRAY) for array fundamentals. Current examples include:

- **Majority Element:** frequency thresholding and voting ideas
- **First Missing Positive:** indexing as a lookup structure
- **Product of Array Except Self:** prefix/suffix product techniques

Next, apply these ideas in rated Codeforces problem folders and contest solutions.

### Strings and Character Processing

Use [`DSA_Box/STRING`](./DSA_Box/STRING) and [`custom_function`](./custom_function) for string-heavy problems.

- Study subsequence checks and two-pointer reasoning.
- Reuse string conversions and permutation generators when the problem asks for generated results.
- Use [`Templete/Python_Templete.py`](./Templete/Python_Templete.py) for Python implementations.

### Permutations and Counting

Open [`custom_function/permutation_generator.cpp`](./custom_function/permutation_generator.cpp) for permutations and [`custom_function/freq_count_fun.cpp`](./custom_function/freq_count_fun.cpp) for frequency and counting helpers.

Understand the purpose of each helper before copying it:

- **Permutation generation:** enumerate all arrangements or derive the next arrangement.
- **Frequency counting:** identify repeated values or the most common element.
- **Counting helpers:** answer range and occurrence questions efficiently.

### Math and Number Theory

Enter [`Math/Sieve, Prime Factorization and Divisors`](./Math/Sieve,%20Prime%20Factorization%20and%20Divisors) to study:

- Prime counting with a sieve
- Almost-prime reasoning
- The nth prime
- Generating and printing prime sets

Before implementation, make sure you understand time complexity, memory use, and the difference between sieve construction and divisor traversal.

### Pattern Practice

[`DSA_Pattern/DSA_Leetcode`](./DSA_Pattern/DSA_Leetcode) organizes problems by approach instead of by judge. The `Hashing` section is the first topic to review; use the remaining pattern folders as they are added.

## Judge-Specific Practice

### Codeforces

Use [`Codeforces/800-rated`](./Codeforces/800-rated) through [`Codeforces/1200-rated`](./Codeforces/1200-rated) as a progression of difficulty. The dedicated contest folders are best used for mixed sets and virtual participation:

1. Solve the contest set under a timer.
2. Separate solved, almost-solved, and unseen problems.
3. Revisit missed problems after studying the relevant folder.
4. Record pattern and mistake categories in [`logs`](./logs).

### AtCoder

[`Atcoder/Atcoder_Easy_100`](./Atcoder/Atcoder_Easy_100) is suited to foundations, while `Atcoder_Medium_100` provides the next step. ABC folders such as `ABC454`–`ABC484` preserve practice from individual contests.

### CodeChef

`STARTER_*` folders contain repeated short-contest practice. `ICPC_Prelims_26/` should be used for longer, team-style problem solving and implementation discipline.

## Contest Workflow

### Before the contest

- Open [`Templete/ICPC_Templete.cpp`](./Templete/ICPC_Templete.cpp).
- Verify fast input/output and language-standard compatibility.
- Remove unused code for cleaner submissions.
- Keep frequently used conversions and frequency helpers nearby.

### During the contest

- Classify each problem by known topic or pattern.
- For arrays, strings, and counting, check constraints before choosing a time complexity.
- For math problems, inspect [`Math`](./Math) only after attempting a derivation yourself.
- For implementation-heavy problems, use test-case generation and stress-testing tools.

### After the contest

- Review solved problems by platform folder.
- For unresolved problems, rewrite the solution after understanding the main invariant or formula.
- Add useful findings to [`logs`](./logs), and promote reusable code into [`custom_function`](./custom_function) or [`Templete`](./Templete).

## Coding Profiles

| Platform | Profile |
|---|---|
| Codeforces | [p1ll3chan](https://codeforces.com/profile/p1ll3chan) |
| CodeChef | [starlord_arp68](https://www.codechef.com/users/starlord_arp68) |
| AtCoder | [p1ll3chan](https://atcoder.jp/users/p1ll3chan) |

## Quick Setup

```bash
git clone https://github.com/p1ll3chan/Competitive-Programming-Kit.git
cd Competitive-Programming-Kit
```

Open a solution with your preferred editor and compile C++ code with:

```bash
g++ -std=c++17 -O2 -Wall solution.cpp -o solution
./solution
``` 
