import cv2
Mo = cv2.imread("MonMon.png")
Tu = cv2.imread("TueTue.png")
We = cv2.imread("WedWed.png")
Th = cv2.imread("ThuThu.png")
Fr = cv2.imread("FriFri.png")
Sa = cv2.imread("SatSat.png")
Su = cv2.imread("SunSun.png")
img = cv2.vconcat([Mo, Tu, We, Th, Fr, Sa, Su])
cv2.imwrite("dieslist.png", img)