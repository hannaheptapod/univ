import cv2

img = cv2.imread('./May.jpeg', 0)

imt = cv2.threshold(img, 0, 255, cv2.THRESH_BINARY)

cv2.imshow('img', img)
cv2.imshow('imt', imt)
cv2.waitKey(0)