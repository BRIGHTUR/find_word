#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat srcMat = imread("gtest.jpg", 0);
	Mat dstMat;
	srcMat.copyTo(dstMat);
	int temp;
	float lut[256];
	float gamma = 0.3;
	for (int i = 0; i < 256; i++) {
		lut[i] = (float)i / 255;
		lut[i] = pow(lut[i], gamma);
		lut[i] = (int)(lut[i] * 255);
	}
	for (int i = 0; i < srcMat.rows; i++) {
		for (int j = 0; j < srcMat.cols; j++) {
			temp = srcMat.at<uchar>(i, j);
			dstMat.at<uchar>(i, j) = lut[temp];

		}
	}
	imshow("Ô­Í¼", srcMat);
	imshow("µ÷ÁÁ", dstMat);
	waitKey(0);
}