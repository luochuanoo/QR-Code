/*
 * @Description: 
 * @version: 
 * @Author: LuoChuan
 * @Date: 2021-04-27 16:07:17
 * @LastEditors: LuoChuan
 * @LastEditTime: 2021-04-28 10:55:55
 */

#ifndef COMMON_HPP
#define COMMON_HPP

#include <vector>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void display(Mat &image, const vector<Point2i> &bbox, const string &code_information);

#endif