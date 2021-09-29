import cv2

img = cv2.imread('./1Jan.jpeg', cv2.IMREAD_COLOR)
window_name = 'img'

def mouse(event, x, y, flags, params):
    if event == cv2.EVENT_LBUTTONDOWN:
        print(x, y)

cv2.imshow(window_name, img)
cv2.setMouseCallback(window_name, mouse)
cv2.waitKey(0)
