/*
 * @Description: 
 * @version: 
 * @Author: LuoChuan
 * @Date: 2021-04-27 16:10:08
 * @LastEditors: LuoChuan
 * @LastEditTime: 2021-04-28 11:03:38
 */
#include <iostream>
#include <string>

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "common.hpp"

void display(Mat &image, const vector<Point2i> &bbox, const string &code_information)
{
    if (bbox.empty())
    {
        namedWindow("Result", 0);
        imshow("Result", image);
        return;
    }

    RotatedRect r = minAreaRect(bbox); // 包含所示角点的最小旋转矩形
    Point2f pts[4];
    r.points(pts); // 将最小旋转矩形的四个角点存到 pts

    Point textPoint(pts[1]);
    for (int i = 0; i < 4; i++)
    {
        line(image, pts[i], pts[(i + 1) % 4], Scalar(255, 0, 0), 3);
        textPoint.x >= pts[i].x ? textPoint.x = pts[i].x : textPoint.x = textPoint.x;
        textPoint.y >= pts[i].y ? textPoint.y = pts[i].y : textPoint.y = textPoint.y;
    }
    putText(image, code_information, textPoint, FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255), 1, LINE_8, false);

    cout << "X:\t" << r.center.x - image.cols / 2 << endl
         << "Y:\t" << r.center.y - image.rows / 2 << endl
         << "Angle:\t" << r.angle << endl
         << endl;

    namedWindow("Result", 0);
    imshow("Result", image);
}