import random
import sol
import brute

def generate():
    x = random.randint(0, 16)
    y = random.randint(0, 16)
    return x, y

for i in range(1000):
    x, y = generate()
    r1 = sol.solve(x, y)
    r2 = brute.solve(x, y)
    if r1 != r2:
        print("FAIL:", x, y, "sol:", r1, "brute:", r2)
        break
else:
    print("OK")