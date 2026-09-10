import sys
input = sys.stdin.readline

# --- single integer ---
n = int(input())

# --- multiple integers on one line ---
n, m = map(int, input().split())

# --- array of integers ---
arr = list(map(int, input().split()))

# --- array of integers, size given first ---
n = int(input())
arr = list(map(int, input().split()))

# --- multiple test cases ---
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    solve(n, arr)

# --- N lines each with an integer ---
n = int(input())
vals = [int(input()) for _ in range(n)]

# --- N lines each with a list of integers (grid/matrix of numbers) ---
n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# --- N lines each a string (grid of characters, e.g. maze) ---
n, m = map(int, input().split())
grid = [input().strip() for _ in range(n)]

# --- single string ---
s = input().strip()

# --- multiple strings on one line ---
words = input().split()

# --- mixed types on one line ---
n, s = input().split()
n = int(n)