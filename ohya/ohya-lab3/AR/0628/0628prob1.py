from math import factorial
n = int(input('nを入力:'))
for i in range(n):
    # パスカルの三角形には各nに対する二項係数が現れる
    combi_list = [(factorial(i) // (factorial(i - r) * factorial(r))) for r in range(i + 1)]
    combi_string = [str(combi_list[j]) for j in range(i + 1)]
    print(' '.join(combi_string).center(5 * n))