#!/usr/bin/python
#-*- coding:utf-8 -*-
import cv2

image = cv2.imread("test.jpg")
cv2.imshow("win", image)
cv2.waitKey(1000)

print image.shape

r = 100.0/image.shape[1]
dim = (100, int(image.shape[0]*r))

# 执行图片缩放，并显示
resized = cv2.resize(image, dim, interpolation=cv2.INTER_AREA)
cv2.imshow("resized", resized)
cv2.waitKey(1000)

h,w = image.shape[:2]
center = (w/2, h/2)

# 将图像旋转180度
M = cv2.getRotationMatrix2D(center, 180, 1.0)
rotated = cv2.warpAffine(image, M, (w, h))
cv2.imshow("rotated", rotated)
cv2.waitKey(1000)


# 使用numpy数组切片对图像进行剪裁
cropped = image[170:270, 140:240]
cv2.imshow("cropped", cropped)
cv2.waitKey(1000)

# 将剪切后的图片以PNG格式保存至磁盘
cv2.imwrite("thumbnail.png", cropped)


