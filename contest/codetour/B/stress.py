import random
import sol
import brute

def generate():
    n = random.randint(2, 6)
    arr = [random.randint(1, 20) for _ in range(n)]
    return n, arr

for i in range(1000):
    n, arr = generate()
    r1 = sol.solve(n, arr)
    r2 = brute.solve(n, arr)
    if r1 != r2:
        print("FAIL:", n, arr, "sol:", r1, "brute:", r2)
        break
else:
    print("OK")