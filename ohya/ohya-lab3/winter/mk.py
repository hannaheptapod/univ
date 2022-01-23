from PIL import Image
import os

src_dir = './datas/wine/'
dst_dir = './dataset/wine/'

ls = os.listdir(src_dir)

for file in ls:
    if file[-3::] == 'png':
        img = Image.open(src_dir+file)
        img_resize_lanczos = img.resize((224, 224), Image.LANCZOS)
        img_resize_lanczos.save(dst_dir+file)