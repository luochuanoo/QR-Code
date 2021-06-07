/*
 * @Description: 
 * @version: 
 * @Author: LuoChuan
 * @Date: 2021-04-27 11:24:29
 * @LastEditors: LuoChuan
 * @LastEditTime: 2021-05-07 16:55:37
 */

#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>

// #include "cuda_runtime.h"

#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"

#include "common.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    // string qr_code = "../data/Test.png";
    // Mat img = imread(qr_code, IMREAD_COLOR);

    VideoCapture cap(1);
    Mat imageInput;
    cap >> imageInput;
    int width = imageInput.cols;
    int height = imageInput.rows;

    QRCodeDetector qrDecoder;

    while (1)
    {
        cap >> imageInput;
        // namedWindow("src", 0);
        // imshow("src", imageInput);

        Mat imageGray;
        cvtColor(imageInput, imageGray, CV_RGB2GRAY);

        Mat bbox, rectifiedImage;
        vector<Point2i> qr_box;

        clock_t start = clock();

        string data = qrDecoder.detectAndDecode(imageGray, bbox, rectifiedImage);

        clock_t end = clock();
        double during_time = (double)(end - start) / CLOCKS_PER_SEC;
        cout << "During_time:\t" << during_time << endl;

        if (data.length() > 0)
        {
            cout << "Decoded:\t" << data << endl; // 二维码信息

            for (int i = 0; i < bbox.rows; i++)
                qr_box.push_back(Point2i(bbox.at<float>(i, 0), bbox.at<float>(i, 1)));

            // rectifiedImage.convertTo(rectifiedImage, CV_8UC3);
        }
        else
            cerr << "Failed to detect QR code!" << endl;

        display(imageInput, qr_box, data);

        if (waitKey(1) == 27)
            break;
    }

    return 0;
}