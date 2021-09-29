class SizeNotMatchError(Exception):
    pass

class Vector:
    def __init__(self, *args):
        self.v = args

    def __str__(self):
        return str(self.v)

    def __add__(self, other):
        try:
            if len(self.v) != len(other.v):
                raise SizeNotMatchError
        except Exception as e:
            return type(e)
        else:
            return Vector(*tuple(a + b for a, b in zip(self.v, other.v)))

    def __sub__(self, other):
        try:
            if len(self.v) != len(other.v):
                raise SizeNotMatchError
        except Exception as e:
            return type(e)
        else:
            return Vector(*tuple(a - b for a, b in zip(self.v, other.v)))

    def __mul__(self, n):
        return Vector(*tuple(arg * n for arg in self.v))

    __radd__ = __add__
    __rsub__ = __sub__
    __rmul__ = __mul__

    def __truediv__(self, n):
        return Vector(*tuple(arg / n for arg in self.v))

    def dot(self, other):
        try:
            if len(self.v) != len(other.v):
                raise SizeNotMatchError
            else:
                dot = 0
                for a, b in zip(self.v, other.v):
                    dot += a * b
        except Exception as e:
            return type(e)
        else:
            return dot

    def __abs__(self):
        sum_square = 0
        for a in self.v:
            sum_square += a ** 2
        return sum_square ** 0.5

a_in, b_in, c_in = (
    tuple(map(int, input(f'{v}を入力:').split()))
    for v in ('a', 'b', 'c')
)
a, b, c = Vector(*a_in), Vector(*b_in), Vector(*c_in)
print(a, b, c)
print(a + b)
print(a - c)
print(a * 2)
print(a / 3)
print(2*a + b/4 - c)
print(a.dot(b))
print(abs(a))