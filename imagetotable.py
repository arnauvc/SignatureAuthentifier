from PIL import Image
import PIL
for n in range(1, 3):
  img = Image.open(str(n) + '.png').convert('LA')
  img = img.resize((10, 10), PIL.Image.ANTIALIAS)
  inf = 256.0
  sup = -1.0
  for pixel in iter(img.getdata()):
      inf = min(pixel[0], inf)
      sup = max(pixel[0], sup)
  f=open('./input' + str(n) + '.txt', 'w')
  for pixel in iter(img.getdata()):
      tmp = 0.0 + pixel[0]
      tmp = 256 * (tmp - inf) / (sup - inf)
      f.write(str(tmp) + ' '),
  f.close()