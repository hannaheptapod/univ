import numpy as np
from scipy.stats import norm
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig = plt.figure()
ims = []
for s in range(1, 6):
    x = np.arange(-5, +5, 0.1)
    y = norm.pdf(x, 0, s**0.5)
    im = plt.plot(x, y, label='$\mu$: 0, $\sigma^2$: {}'.format(str(s)))
    plt.legend(loc='upper left')
    ims.append(im)
ani = animation.ArtistAnimation(fig, ims, interval=1000)
ani.save('sigma.gif', writer='imagemagick')