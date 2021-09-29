import decimal, time
# nを入力
n = int(input('nを入力:'))
t0 = time.time()
# decimalの有効桁数を指定
decimal.getcontext().prec = n
# 大きな値をとるa, piをdecimal型で宣言
a, pi = decimal.Decimal(1), decimal.Decimal(0)

# 級数を計算
for i in range(0, round(n * 1.7)):
    j = decimal.Decimal(i)
    pi += 3*a * 16**(-j) / (2*j + 1)
    a = 2*a * (2 - 1/(j + 1))

# 10^n-1乗して整数化したものを出力
print(int(10**(n - 1) * pi))    
t1 = time.time()
print('実行時間[s] = {}[s]'.format(t1 - t0))