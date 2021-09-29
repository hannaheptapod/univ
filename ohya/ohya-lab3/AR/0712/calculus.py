import matplotlib.pyplot as plt
from scipy.misc import derivative
from scipy import integrate
import numpy as np

class Calculus():
    def __init__(self, func):
        self.func = func

    def differential(self, x):
        # 定微分
        return derivative(self.func, x, dx=1e-6)

    def integral(self, x0, x1):
        # 定積分
        return integrate.quad(self.func, x0, x1)[0]

    def show(self, x0, x1, mode='fid', c=0):
        x = np.arange(x0, x1, 0.1)
        yf = self.func(x)
        yd = derivative(self.func, x, dx=1e-6)

        plt.plot(x, yf, label='F')
        if 'd' in mode:
            # 導関数
            plt.plot(x, yd, label='D')
        if 'i' in mode:
            # 不定積分の仕方がわかりませんでした……
            pass
        # Matplotlibでグラフを表示
        plt.xlabel('X')
        plt.ylabel('Y')
        plt.legend()
        plt.show()