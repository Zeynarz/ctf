import cv2
c = cv2.QRCodeDetector()

for i in range(41):
    retval,points,straight_qrcode = c.detectAndDecode(cv2.imread("frames/frame" + str(i) + ".png"))
    print(retval,end="")
    
print()
