# decimalを使用して精度を出す
from decimal import Decimal, getcontext
n, e = int(input('nを入力:')), Decimal(0)
getcontext().prec = n
for i in range(n):
    s = 1
    for j in range(i):
        s *= j + 1
    e += Decimal(1) / Decimal(s)
print(e)