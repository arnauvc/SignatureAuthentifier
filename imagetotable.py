from PIL import Image
import PIL
for n in xrange(1, 3):
  img = Image.open(str(n) + '.png').convert('LA')
  inf = 256.0
  sup = -1.0
  for pixel in iter(img.getdata()):
      inf = min(pixel[0], inf)
      sup = max(pixel[0], sup)
  print(inf),
  print(sup)
  pix = img.load()
  width, height = img.size
  print(width),
  print(height)
  for x in xrange(0, width - 1):
      for y in xrange(0, height  - 1):
	  tmp = pix[x, y][0];
	  pix[x, y] = (255 * (tmp - inf) / (sup - inf),) + pix[x, y][1:1]
  top = 0 #tancat-tancat
  down = height - 1
  left = 0
  right = width - 1
  for y in xrange(0, height, 1): #fer baixar lo de dalt
      gut = True
      for x in xrange(0, width, 1):
	  if pix[x, y][0] < 200:
	      gut = False
      if gut:
	  top = y
      else:
	  break
  for y in xrange(height - 1, -1, -1): #fer pujar lo de baix
    gut = True
    for x in xrange(0, width, 1):
	if pix[x, y][0] < 200:
	    gut = False
    if gut:
	down = y
    else:
        break
  for x in xrange(0, width, 1): #fer lo de lasquerra
      gut = True
      for y in xrange(0, height, 1):
	  if pix[x, y][0] < 200:
	      gut = False
      if gut:
	  left = x
      else:
	  break
  for x in xrange(width - 1, -1, -1): #fer lo de la dreta
      gut = True
      for y in xrange(0, height, 1):
	  if pix[x, y][0] < 200:
	      gut = False
      if gut:
	  right = x
      else:
	  break
  print(left),
  print(top),
  print(right),
  print(down)
  img = img.crop((left, top, right, down))
  img = img.resize((50, 20), PIL.Image.ANTIALIAS)
  img.save(str(n) + 'cropped.png')
  f=open('./input' + str(n) + '.txt', 'w')
  for pixel in iter(img.getdata()):
      f.write(str(pixel[0]) + ' '),
  f.close()
