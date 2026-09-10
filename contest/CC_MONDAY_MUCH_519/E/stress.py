import random
import sol
import brute

def generate():
    n = random.randint(2, 6)
    k = random.randint(1,20)
    arr = [random.randint(1, 20) for _ in range(n)]
    return n, k, arr

for i in range(1000):
    n, k, arr = generate()
    r1 = sol.solve(n, k, arr[:])
    r2 = brute.solve(n, k, arr[:])
    if r1 != r2:
        print("FAIL:", n,k, arr, "sol:", r1, "brute:", r2)
        break
else:
    print("OK")