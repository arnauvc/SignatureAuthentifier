from PIL import Image
import PIL
img = Image.open('image.png').convert('LA')
img = img.resize((33, 33), PIL.Image.ANTIALIAS)
inf = 256.0
sup = -1.0
for pixel in iter(img.getdata()):
    inf = min(pixel[0], inf)
    sup = max(pixel[0], sup)
for pixel in iter(img.getdata()):
    tmp = 0.0 + pixel[0]
    tmp = 256 * (tmp - inf) / (sup - inf)
    print(tmp),
