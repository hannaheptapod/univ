import numpy as np
from scipy.stats import t, norm
import matplotlib.pyplot as plt
import matplotlib.animation as animation

ims = []
ks = (1, 2, 3, 5, 10, 30)
fig = plt.figure()
x = np.linspace(-6, 6, 1000)
plt.xlabel(r'$x$')
plt.ylabel(r'$f(x)$')
plt.grid()
for k in ks:
    im = plt.plot(x, norm.pdf(x, 0, 1), color='black', linestyle=':')
    im = plt.plot(x, t.pdf(x, k), label=r'$\nu$ = {}'.format(str(k)))
    plt.legend()
    ims.append(im)
im = plt.plot(x, norm.pdf(x, 0, 1), color='black', linestyle='-', label=r'$N( 0, 1 )$')
plt.legend()
ims.append(im)
ani = animation.ArtistAnimation(fig, ims, interval=1000)
ani.save('tdist.gif', writer='imagemagick')