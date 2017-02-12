from PIL import Image
from PIL import ImageFilter
import PIL
import os
cnt = 0
inputname = raw_input()
outputname = raw_input()
for filename in os.listdir('./' + inputname + '/'):
  if filename.endswith('.PNG') or filename.endswith('.jpg') or filename.endswith('.png'):
    img = Image.open(inputname + '/' + filename).convert('LA')
    inf = 256.0
    sup = -1.0
    for pixel in iter(img.getdata()):
    	inf = min(pixel[0], inf)
    	sup = max(pixel[0], sup)
    pix = img.load()
    width, height = img.size
    print(width),
    print(height)
    for x in xrange(0, width - 1):
    	for y in xrange(0, height  - 1):
    		tmp = pix[x, y][0];
    		pix[x, y] = (min(255, 435 * (pix[x, y][0] - inf) / (sup - inf)),) + pix[x, y][1:1];
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
    #img.save(str(cnt) + 'cropped.png')
    f=open('./' + outputname + '/input' + str(cnt) + '.txt', 'w')
    for pixel in iter(img.getdata()):
	f.write(str(1.0 - (pixel[0] + 0.0) / 255.0) + ' '),
    f.close()
    cnt = cnt + 1
  else:
continue