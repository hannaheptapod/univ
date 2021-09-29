import cv2
import numpy as np

img = cv2.imread('./Apr.jpeg')

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
edges = cv2.Canny(gray, 1, 100, apertureSize=3)
cv2.imwrite('edges.png', edges)
kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
edges = cv2.dilate(edges, kernel)
contours, hierarchy = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
rects = []
for cnt, hrchy in zip(contours, hierarchy[0]):
    if cv2.contourArea(cnt) < 5000:
        continue
    #if hrchy[3] == -1:
       #continue
    rect = cv2.minAreaRect(cnt)
    rect_points = cv2.boxPoints(rect).astype(int)
    rects.append(rect_points)

rects = sorted(rects, key=lambda x: (x[0][1], x[0][0]))

for i, rect in enumerate(rects):
    color = np.random.randint(0, 255, 3).tolist()
    cv2.drawContours(img, rects, i, color, 2)
    cv2.putText(img, str(i), tuple(rect[0]), cv2.FONT_HERSHEY_SIMPLEX, 0.8, color, 3)

    print('rect:\n', rect)

cv2.imwrite('img.png', img)