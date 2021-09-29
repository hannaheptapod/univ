import numpy as np
import cv2
from matplotlib import pyplot as plt

img = cv2.imread('digits.png')
gray = cv2.cv2color(img,cv2.COLOR_BGR2GRAY)

# この画像をそれぞれ20x20のサイズのセル5,000個に分割する。
cells = [np.hsplit(row,100) for row in np.vsplit(gray,50)]

# Numpy配列に変換する。そのサイズは (50,100,20,20)
x = np.array(cells)

# train_data(学習データ)とtest_data(テストデータ)を用意
train = x[:,:50].reshape(-1,400).astype(np.float32) 
test = x[:,50:100].reshape(-1,400).astype(np.float32) 

# 学習データとテストデータのラベルを作る
k = np.arange(10)
train_labels = np.repeat(k,250)[:,np.newaxis]
test_labels = train_labels.copy()

# kNNのインスタンスを作り、学習データで学習し、テストデータでテストする(k=1とする)
knn = cv2.KNearest()
knn.train(train,train_labels)
ret,result,neighbours,dist = knn.find_nearest(test,k=5)

# 分類の精度を調べる
# そのために、テストデータのラベルと比較し、誤りを調べる
matches = result==test_labels
correct = np.count_nonzero(matches)
accuracy = correct*100.0/result.size
print(accuracy)