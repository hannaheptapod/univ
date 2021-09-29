import cv2
import numpy as np
filename = 'Jan' + '.jpeg'
img = cv2.imread("./" + filename, cv2.IMREAD_GRAYSCALE)

th = cv2.threshold(img, 0, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)[1]

cv2.imwrite('1' + filename, th)