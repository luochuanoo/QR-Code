/*
 * @Description: 
 * @version: 
 * @Author: LuoChuan
 * @Date: 2021-04-15 09:32:30
 * @LastEditors: LuoChuan
 * @LastEditTime: 2021-05-31 16:56:32
 */

#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>

#include "zbar.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"

#include "common.hpp"

using namespace std;
using namespace zbar;
using namespace cv;

int main(int argc, char *argv[])
{
	// string qr_code = "../data/Test.png";
	// Mat imageInput = imread(qr_code, IMREAD_COLOR);

	VideoCapture cap(1);
	cap.set(CAP_PROP_FRAME_WIDTH, 320);
	cap.set(CAP_PROP_FRAME_HEIGHT, 240);

	Mat imageInput;
	cap >> imageInput;
	int width = imageInput.cols;
	int height = imageInput.rows;
	cout << width << '\t' << height << endl;

	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

	while (1)
	{
		cap >> imageInput;

		Mat imageGray;
		cvtColor(imageInput, imageGray, CV_RGB2GRAY);

		clock_t start = clock();

		uchar *raw = (uchar *)imageGray.data;
		Image imageZbar(width, height, "Y800", raw, width * height); // Y800 灰度图像
		scanner.scan(imageZbar);									 // 扫描图片进行检测

		clock_t end = clock();
		double during_time = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "During_time:\t" << during_time << endl;

		if (imageZbar.symbol_begin() == imageZbar.symbol_end())
		{
			cerr << "Failed to detect QR code!" << endl;
			namedWindow("Result", 0);
			imshow("Result", imageInput);
		}

		for (Image::SymbolIterator symbol = imageZbar.symbol_begin(); symbol != imageZbar.symbol_end(); ++symbol)
		{

			cout << "Decoded:\t" << symbol->get_type_name() << endl; // 二维码类型
			cout << "Symbol:\t" << symbol->get_data() << endl;		 // 二维码信息

			vector<Point2i> qr_box;
			int num_cornor = symbol->get_location_size(); // 二维码的角点
			for (int i = 0; i < num_cornor; i++)
				qr_box.push_back(Point(symbol->get_location_x(i), symbol->get_location_y(i)));

			display(imageInput, qr_box, symbol->get_data());
		}

		imageZbar.set_data(NULL, 0);

		if (waitKey(1) == 27)
			break;
	}

	return 0;
}