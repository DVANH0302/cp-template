from scipy.optimize import linprog

# Variables: g1a, g1b, g2a, g2b, theta2, theta3
# PG1 = 20 + g1a + g1b
# PG2 = 10 + g2a + g2b

c = [9.6, 11.2, 8.65, 10.75, 0, 0]
base_cost = 268 + 193

# Power balance equations
A_eq = [
    [1, 1, 0, 0, 5, 2.5],
    [0, 0, 1, 1, -9, 4],
    [0, 0, 0, 0, 4, -6.5]
]

b_eq = [-20, -10, 120]

# -17.5 <= theta2 - theta3 <= 17.5
A_ub = [
    [0, 0, 0, 0, 1, -1],
    [0, 0, 0, 0, -1, 1]
]

b_ub = [17.5, 17.5]

bounds = [
    (0, 40),   # g1a
    (0, 40),   # g1b
    (0, 35),   # g2a
    (0, 35),   # g2b
    (-16, 16), # theta2
    (-24, 24)  # theta3
]

result = linprog(
    c,
    A_eq=A_eq,
    b_eq=b_eq,
    A_ub=A_ub,
    b_ub=b_ub,
    bounds=bounds,
    method="highs"
)

if result.success:
    g1a, g1b, g2a, g2b, theta2, theta3 = result.x

    PG1 = 20 + g1a + g1b
    PG2 = 10 + g2a + g2b
    cost = result.fun + base_cost

    P12 = -5 * theta2
    P13 = -2.5 * theta3
    P23 = 4 * (theta2 - theta3)

    print("Optimal solution:")
    print(f"theta2 = {theta2:.4f}")
    print(f"theta3 = {theta3:.4f}")
    print(f"PG1 = {PG1:.4f} MW")
    print(f"PG2 = {PG2:.4f} MW")
    print(f"Total generation = {PG1 + PG2:.4f} MW")
    print(f"P12 = {P12:.4f} MW")
    print(f"P13 = {P13:.4f} MW")
    print(f"P23 = {P23:.4f} MW")
    print(f"Minimum cost = {cost:.4f}")
else:
    print("No solution found.")