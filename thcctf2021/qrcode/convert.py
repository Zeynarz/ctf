from PIL import Image, ImageSequence

im = Image.open("qrcode.gif")

for index,frame in enumerate(ImageSequence.Iterator(im)):
    frame.save("frame%d.png" % index)
