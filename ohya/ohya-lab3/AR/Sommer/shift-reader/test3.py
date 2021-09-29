import cv2

filename = 'May.jpeg'
img = cv2.imread('./' + filename)

corners0 = [[36, 59], [1004, 59], [31, 359], [1012, 360]]
corners1 = [[30, 392], [860, 390], [22, 707], [873, 716]]

for i in range(4):
    cv2.circle(img, corners0[i], 5, (255, 0, 0))
    cv2.circle(img, corners1[i], 5, (0, 255, 0))

cv2.imwrite('./0' + filename, img)
cv2.waitKey(0)