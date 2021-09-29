n = int(input('nを入力:'))

list_prime = [i for i in ([2] + list(range(3, n, 2))) if len([1 for j in range(3, round(i ** 0.5) + 1, 2) if i % j == 0]) == 0]

print(list_prime)