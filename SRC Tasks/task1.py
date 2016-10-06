import numpy as np
import cv2

cap = cv2.VideoCapture(0)

while(True):
	ret, frame = cap.read()
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
	ret,thresh1 = cv2.threshold(frame,220,255,cv2.THRESH_BINARY)
	mask = cv2.inRange(hsv, (0,0,255), (180,255,255))
	mask = cv2.erode(mask, None, iterations = 2)
	mask = cv2.dilate(mask, None, iterations = 2)
	cv2.imshow('frame', mask)
	cv2.imshow('frame1', thresh1)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break
cap.release()
cv2.destroyAllWindows()
