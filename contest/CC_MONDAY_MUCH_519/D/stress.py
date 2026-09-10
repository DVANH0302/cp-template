import random
import sol
import brute

def generate():
    n = random.randint(2, 10)
    arr = [random.randint(1, 20) for _ in range(n)]
    q = random.randint(2, 10)
    queries = []

    for _ in range(q):
        q1, q2 = random.randint(1, n), random.randint(1,n)
        l, r = min(q1, q2), max(q1,q2)
        queries.append((l,r))        
    return n, q, arr, queries

for i in range(1000):
    n,q,arr, queries = generate()
    F = sol.precompute(max(arr))
    r1 = sol.solve(n,q,arr,queries, F)
    r2 = brute.solve(n,q,arr,queries, F)
    if r1 != r2:
        print("FAIL:", n, arr, "sol:", r1, "brute:", r2)
        break
else:
    print("OK")