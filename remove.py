#!/usr/bin/python3
import sys
from rembg import remove
from PIL import Image
inpath = sys.argv[1]
outpath = inpath
inp = Image.open(inpath)
output = remove(inp)
output.save(outpath)
