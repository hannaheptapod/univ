import cv2
import numpy as np
import glob
import sys
import pathlib

def file_name(args):
    return ''.join(map(str, args)) + '.png'

def linear(src: np.ndarray, n):

    dst = src.copy()
    k = np.uint(n * 10)
    r = np.random.randint(0, 3)
    dst[r] += k
    dst[(r + 1) // 3] -= k
    return dst

def eq_hist_bgr(src):

    src_splitted = cv2.split(src)

    for c in src_splitted:
        cv2.equalizeHist(c)
    
    dst = cv2.merge(*src_splitted)
    return dst

def gaussian(src):

    row, col, ch = src.shape
    mean, sigma = 0, 15
    dst = src.copy()
    dst += np.uint8(np.random.normal(mean, sigma, (row, col, ch)))
    return dst

def salt_and_pepper(src):

    row, col, ch = src.shape
    ratio, amount = np.random.rand(), 0.004

    dst = src.copy()

    num_salt = np.ceil(amount * src.size * ratio)
    num_pepper = np.ceil(amount * src.size * (1 - ratio))
    coords = [np.random.randint(0, i - 1, int(num_salt)) for i in (row, col, ch)]
    dst[tuple(coords[:-1])] = (255, 255, 255)
    coords = [np.random.randint(0, i - 1, int(num_pepper)) for i in (row, col,ch)]
    dst[tuple(coords[:-1])] = (0, 0, 0)

    return dst

path_src = sys.argv[1]
files = glob.glob(path_src + '/**/**.png', recursive=True)

for item in files:

    im_src = cv2.imread(item)
    path_dst = item.replace('.png', '/')
    pathlib.Path(path_dst).mkdir()
    im_line = []

    for i in range(10):

        im_line.append(linear(im_src, i + 1))
        im_temp = []
        for j in range(5):
            im_temp.append(gaussian(im_line[i]))
            for k in range(10):
                cv2.imwrite(file_name((path_dst, i, j, k)), salt_and_pepper(im_temp[j]))
        for j in range(5, 10):
            im_temp.append(salt_and_pepper(im_line[i]))
            for k in range(10):
                cv2.imwrite(file_name((path_dst, i, j, k)), gaussian(im_temp[j]))