from calculus import *

def func(x):
    return np.cos(x)

f = Calculus(func)

diff = f.differential(1)
intg = f.integral(0, 1)
print(diff, intg)
f.show(-np.pi, np.pi, mode='fid')