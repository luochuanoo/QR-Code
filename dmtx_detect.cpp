/*
 * @Description: libdmtx库检测DM码
 * @version: 
 * @Author: LuoChuan
 * @Date: 2021-05-18 15:36:33
 * @LastEditors: LuoChuan
 * @LastEditTime: 2021-05-31 16:27:04
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "dmtx.h"

#include "common.hpp"

int main(int argc, char *argv[])
{
    string qr_code = "../data/DM_0001.png";
    Mat imageInput = imread(qr_code, IMREAD_GRAYSCALE);

    // VideoCapture cap(1);
    // cap.set(CAP_PROP_FRAME_WIDTH, 640);
    // cap.set(CAP_PROP_FRAME_HEIGHT, 480);

    // Mat imageInput;
    // cap >> imageInput;
    int width = imageInput.cols;
    int height = imageInput.rows;
    cout << width << '\t' << height << endl;

    DmtxImage *img;
    DmtxDecode *dec;
    DmtxRegion *reg;
    DmtxMessage *msg;

    while (1)
    {
        img = dmtxImageCreate(imageInput.data, width, height, DmtxPack8bppK);
        assert(img != NULL);
        cout << "111111111111" << endl;

        dec = dmtxDecodeCreate(img, 1);
        assert(dec != NULL);
        cout << "222222222222" << endl;

        // cap >> imageInput;
        cout << "333333333333" << endl;

        reg = dmtxRegionFindNext(dec, NULL);
        cout << "444444444444" << endl;
        if (reg == NULL)
        {
            cerr << "Failed to detect DM code!" << endl;
            namedWindow("Result", 0);
            imshow("Result", imageInput);
        }
        else
        {
            msg = dmtxDecodeMatrixRegion(dec, reg, DmtxUndefined);
            if (msg != NULL)
            {
                cout << "output: " << msg->output << sizeof(unsigned char) << msg->outputIdx << endl;
                dmtxMessageDestroy(&msg);
            }
            dmtxRegionDestroy(&reg);
            dmtxDecodeDestroy(&dec);
        }

        if (waitKey(1) == 27)
            break;
    }

    dmtxImageDestroy(&img);

    return 0;
}