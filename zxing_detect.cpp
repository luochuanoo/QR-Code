/*
 * @Description: 
 * @version: 
 * @Author: LuoChuan
 * @Date: 2021-04-27 17:20:04
 * @LastEditors: LuoChuan
 * @LastEditTime: 2021-04-27 17:38:07
 */

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

#include <zxing/LuminanceSource.h>
#include <zxing/common/Counted.h>
#include <zxing/Reader.h>

#include <zxing/common/GlobalHistogramBinarizer.h>
#include <zxing/DecodeHints.h>
#include <zxing/MultiFormatReader.h>
#include <zxing/oned/CodaBarReader.h>
#include <zxing/oned/Code39Reader.h>
#include <zxing/oned/Code93Reader.h>
#include <zxing/oned/Code128Reader.h>

#include <zxing/MatSource.h>

using namespace std;
using namespace zxing;
using namespace zxing::qrcode;
using namespace cv;

int main()
{
    std::string image_name = "F:\\chenggeng\\HalconItem\\code1d_1.png";
    cv::Mat matSrc = cv::imread(image_name, 1);
    if (!matSrc.data)
    {
        std::cout << "read image error: " << image_name << std::endl;
        return -1;
    }

    cv::Mat matGray;
    cv::cvtColor(matSrc, matGray, cv::COLOR_BGR2GRAY);

    zxing::Ref<zxing::LuminanceSource> source(new MatSource(matGray));
    int width = source->getWidth();
    int height = source->getHeight();
    std::cout << "image width: " << width << ", height: " << height << std::endl;
    zxing::Ref<zxing::Reader> reader;
    reader.reset(new zxing::oned::Code128Reader);

    zxing::Ref<zxing::Binarizer> binarizer(new zxing::GlobalHistogramBinarizer(source));
    zxing::Ref<zxing::BinaryBitmap> bitmap(new zxing::BinaryBitmap(binarizer));
    zxing::Ref<zxing::Result> result(reader->decode(bitmap, zxing::DecodeHints(zxing::DecodeHints::CODE_128_HINT)));
    std::string str2 = result->getText()->getText();
    std::cout << "recognization result: " << str2 << std::endl;

    zxing::ArrayRef<zxing::Ref<zxing::ResultPoint>> rpoints = result->getResultPoints();
    cv::Point point0(rpoints[0]->getX() + 30, rpoints[0]->getY() + 50);
    cv::Point point1(rpoints[1]->getX() - 30, rpoints[1]->getY() - 50);
    cv::putText(matSrc, str2, cv::Point(rpoints[1]->getX() - 10, rpoints[1]->getY() - 10), 1, 2, cv::Scalar(0, 0, 255));
    cv::rectangle(matSrc, cv::Rect(point1, point0), cv::Scalar(0, 0, 255), 2);
    cv::imshow("locate", matSrc);
    cv::waitKey(0);
    return 0;
}