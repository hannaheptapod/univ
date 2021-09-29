import cv2

img = [[cv2.imread("Wed" + str(i) + ".png") for i in range(25)], [cv2.imread("Wed" + str(i) + ".png") for i in range(25, 50)], [cv2.imread("Wed" + str(i) + ".png") for i in range(50, 75)], [cv2.imread("Wed" + str(i) + ".png") for i in range(75, 100)]] 
im = cv2.vconcat([cv2.hconcat(img[i]) for i in range(4)])
cv2.imwrite("WedWed.png", im)
img = [[cv2.imread("Thu" + str(i) + ".png") for i in range(25)], [cv2.imread("Thu" + str(i) + ".png") for i in range(25, 50)], [cv2.imread("Thu" + str(i) + ".png") for i in range(50, 75)], [cv2.imread("Thu" + str(i) + ".png") for i in range(75, 100)]] 
im = cv2.vconcat([cv2.hconcat(img[i]) for i in range(4)])
cv2.imwrite("ThuThu.png", im)
img = [[cv2.imread("Fri" + str(i) + ".png") for i in range(25)], [cv2.imread("Fri" + str(i) + ".png") for i in range(25, 50)], [cv2.imread("Fri" + str(i) + ".png") for i in range(50, 75)], [cv2.imread("Fri" + str(i) + ".png") for i in range(75, 100)]] 
im = cv2.vconcat([cv2.hconcat(img[i]) for i in range(4)])
cv2.imwrite("FriFri.png", im)
img = [[cv2.imread("Sat" + str(i) + ".png") for i in range(25)], [cv2.imread("Sat" + str(i) + ".png") for i in range(25, 50)], [cv2.imread("Sat" + str(i) + ".png") for i in range(50, 75)], [cv2.imread("Sat" + str(i) + ".png") for i in range(75, 100)]] 
im = cv2.vconcat([cv2.hconcat(img[i]) for i in range(4)])
cv2.imwrite("SatSat.png", im)
img = [[cv2.imread("Sun" + str(i) + ".png") for i in range(25)], [cv2.imread("Sun" + str(i) + ".png") for i in range(25, 50)], [cv2.imread("Sun" + str(i) + ".png") for i in range(50, 75)], [cv2.imread("Sun" + str(i) + ".png") for i in range(75, 100)]] 
im = cv2.vconcat([cv2.hconcat(img[i]) for i in range(4)])
cv2.imwrite("SunSun.png", im)
img = [[cv2.imread("Mon" + str(i) + ".png") for i in range(25)], [cv2.imread("Mon" + str(i) + ".png") for i in range(25, 50)], [cv2.imread("Mon" + str(i) + ".png") for i in range(50, 75)], [cv2.imread("Mon" + str(i) + ".png") for i in range(75, 100)]] 
im = cv2.vconcat([cv2.hconcat(img[i]) for i in range(4)])
cv2.imwrite("MonMon.png", im)
img = [[cv2.imread("Tue" + str(i) + ".png") for i in range(25)], [cv2.imread("Tue" + str(i) + ".png") for i in range(25, 50)], [cv2.imread("Tue" + str(i) + ".png") for i in range(50, 75)], [cv2.imread("Tue" + str(i) + ".png") for i in range(75, 100)]] 
im = cv2.vconcat([cv2.hconcat(img[i]) for i in range(4)])
cv2.imwrite("TueTue.png", im)
