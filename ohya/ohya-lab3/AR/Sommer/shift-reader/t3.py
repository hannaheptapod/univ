import cv2
import numpy as np
from matplotlib import pyplot as plt

filename = 'Jan.jpeg'
src = cv2.imread('./' + filename, 1)

p1 = np.array([102, 130])
p2 = np.array([940, 138])
p3 = np.array([100, 402])
p4 = np.array([950, 391])

o_width = np.linalg.norm(p2 - p1)
o_width=int(np.floor(o_width))
o_height = np.linalg.norm(p3 - p1)
o_height=int(np.floor(o_height))

ori_cor = np.float32([p1, p2, p3, p4])
dst_cor=np.float32([[0, 0],[o_width, 0],[0, o_height],[o_width, o_height]])

M = cv2.getPerspectiveTransform(ori_cor, dst_cor)
cor_src = cv2.warpPerspective(src, M,(o_width, o_height))

plt.imshow(cor_src)
plt.show()