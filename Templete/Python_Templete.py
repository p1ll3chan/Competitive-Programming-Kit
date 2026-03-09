# -------------------- Imports --------------------
import sys
from collections import deque, Counter
from bisect import bisect_left, bisect_right
from itertools import accumulate
from math import gcd, isqrt
input = sys.stdin.readline

# -------------------- Utility Functions --------------------

# Sum of 1..n
def sumN(n: int) -> int:
    return n * (n + 1) // 2

# Check power of 2
def power_2(n: int) -> bool:
    return n != 0 and (n & (n - 1)) == 0

# Count digit frequency of a number
def countDigits(n: int) -> list[int]:
    cnt = [0] * 10
    while n > 0:
        cnt[n % 10] += 1
        n //= 10
    return cnt

# Find MEX
def findMEX(v: list[int]) -> int:
    s = set(x for x in v if x >= 0)
    mex = 0
    while mex in s:
        mex += 1
    return mex

# Most frequent element
def mostFrequentElement(v: list[int]) -> int:
    if not v: return None
    freq = Counter(v)
    return max(freq, key=freq.get)

# Check if all elements equal
def allEqual(v: list[int]) -> bool:
    return all(x == v[0] for x in v)

# -------------------- STL Quick Utils --------------------

# Remove duplicates from sorted list
def uniq_sorted(v: list[int]) -> list[int]:
    return sorted(set(v))

# Check existence in sorted list
def exists_sorted(v: list[int], x) -> bool:
    i = bisect_left(v, x)
    return i < len(v) and v[i] == x

# Remove all occurrences of val
def erase_value(v: list[int], val) -> list[int]:
    return [x for x in v if x != val]

# Merge two lists
def merge_append(a: list[int], b: list[int]) -> list[int]:
    return a + b

# Merge two sorted lists
def merge_sorted(a: list[int], b: list[int]) -> list[int]:
    c = []
    i = j = 0
    while i < len(a) and j < len(b):
        if a[i] < b[j]:
            c.append(a[i]); i += 1
        else:
            c.append(b[j]); j += 1
    c.extend(a[i:]); c.extend(b[j:])
    return c

# Upper and lower indices
def upper_idx(v: list[int], x: int) -> int:
    return bisect_right(v, x)

def lower_idx(v: list[int], x: int) -> int:
    return bisect_left(v, x)

# Prefix sum
def prefix_sum(v: list[int]) -> list[int]:
    return list(accumulate(v))

# Frequency map
def freq_map(v: list[int]) -> dict:
    return dict(Counter(v))

# Most frequent element with count
def most_frequent_unordered(v: list[int]) -> tuple:
    c = Counter(v)
    val, cnt = c.most_common(1)[0]
    return val, cnt

# Coordinate compression
def compress(a: list[int]) -> list[int]:
    b = sorted(set(a))
    return [bisect_left(b, x) for x in a]

# -------------------- BFS / DFS --------------------

def BFS(src: int, g: list[list[int]]) -> list[int]:
    n = len(g)
    dist = [-1] * n
    q = deque([src])
    dist[src] = 0
    while q:
        u = q.popleft()
        for v in g[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist

def MultiBFS(sources: list[int], g: list[list[int]]) -> list[int]:
    n = len(g)
    dist = [-1] * n
    q = deque()
    for s in sources:
        dist[s] = 0
        q.append(s)
    while q:
        u = q.popleft()
        for v in g[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist

def DFS(u: int, g: list[list[int]], vis: list[int]):
    vis[u] = 1
    for v in g[u]:
        if not vis[v]:
            DFS(v, g, vis)

def DFS_collect(u: int, g: list[list[int]], vis: list[int], comp: list[int]):
    vis[u] = 1
    comp.append(u)
    for v in g[u]:
        if not vis[v]:
            DFS_collect(v, g, vis, comp)

# -------------------- DSU --------------------
class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def unite(self, a, b) -> bool:
        a = self.find(a)
        b = self.find(b)
        if a == b:
            return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.p[b] = a
        self.sz[a] += self.sz[b]
        return True

    def size(self, x):
        return self.sz[self.find(x)]

# -------------------- Solve / Main --------------------
def solve():
    n = int(input())
    print(n)
def test():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    # For single testcase
    solve()
    # For multiple testcases:
    # test()
