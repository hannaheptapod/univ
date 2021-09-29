class SizeNotMatchError(Exception):
    pass

class Vector:
    def __init__(self, *args):
        self.v = list(args)

    def __str__(self):
        return str(tuple(self.v))

    def __add__(self, other):
        if len(self.v) != len(other.v):
            raise SizeNotMatchError
        else:
            self.v = [a + b for a, b in zip(self.v, other.v)]
            return self

    def __sub__(self, other):
        if len(self.v) != len(other.v):
            raise SizeNotMatchError
        else:
            self.v = [a - b for a, b in zip(self.v, other.v)]
            return self

    def __mul__(self, n):
        self.v = [a * n for a in self.v]
        return self

    def __truediv__(self, n):
        self.v = [a / n for a in self.v]
        return self

    def dot(self, other):
        if len(self.v) != len(other.v):
            raise SizeNotMatchError
        else:
            d = sum([a * b for a, b in zip(self.v, other.v)])
            return d

    def __abs__(self):
        sum_square = 0
        for a in self.v:
            sum_square += a ** 2
        return sum_square ** 0.5

    __radd__, __rsub__, __rmul__ = __add__, __sub__, __mul__
n = 5
a, b, c = [Vector(1, 2, 3, 4, 5), Vector(1, 0, -1, 0, 1), Vector(-1, -1, -1, 2, 3)]
print('a, b, c = ', a, b, c)
print('a + b - c = ', a + b - c)
print('a * b.dot(c) = ', a * b.dot(c))
print('a / abs(b - c) = ', a / abs(b - c))