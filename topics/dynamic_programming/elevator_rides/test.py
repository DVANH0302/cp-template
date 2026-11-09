import gurobipy as gp
from gurobipy import GRB

USE_BATTERY = True   # set to False to solve without the BESS

E = [2.8, 3.4, 5.8]
h = [3, 2, 2]
g = [3.8, 10.8, 13.5, 4.0, 6.9]
rho = [0.2, 0.35, 0.7, 0.9, 0.18]
E_max = 9.5
M = sum(g)

I = range(3)
T = range(5)

model = gp.Model("HEMS")

x = model.addVars(3, 5, vtype=GRB.BINARY)         # appliance i on in hour t
s = model.addVars(5, lb=0, ub=E_max)              # energy sold
big = M if USE_BATTERY else 0
c = model.addVars(5, lb=0, ub=big)                # charge
d = model.addVars(5, lb=0, ub=big)                # discharge
b = model.addVars(5, lb=0)                        # BESS level
u = model.addVars(5, vtype=GRB.BINARY)            # 1 = charging, 0 = discharging

for i in I:
    model.addConstr(gp.quicksum(x[i, t] for t in T) == h[i])

for t in T:
    model.addConstr(g[t] + d[t] == gp.quicksum(E[i] * x[i, t] for i in I) + c[t] + s[t])
    prev = b[t - 1] if t > 0 else 0
    model.addConstr(b[t] == prev + c[t] - d[t])
    model.addConstr(c[t] <= M * u[t])
    model.addConstr(d[t] <= M * (1 - u[t]))

model.setObjective(gp.quicksum(rho[t] * s[t] for t in T), GRB.MAXIMIZE)
model.optimize()

print("Profit:", round(model.ObjVal, 2))
for i in I:
    print("Appliance", i + 1, "hours:", [t + 1 for t in T if x[i, t].X > 0.5])
print("Sold:     ", [round(s[t].X, 2) for t in T])
print("Charge:   ", [round(c[t].X, 2) for t in T])
print("Discharge:", [round(d[t].X, 2) for t in T])
print("BESS level:", [round(b[t].X, 2) for t in T])