#include "ASCore.hpp"
#include <Windows.h>
#include <opencv2/opencv.hpp>

static cv::VideoCapture cap;
static cv::Mat frame;

void HelloCore() {
    MessageBoxA(NULL, "Hello from ASCORE DLL!", "ASCORE", MB_OK);
}

bool InitCamera() {
    cap.open(0);
    return cap.isOpened();
}

void ReleaseCamera() {
    if (cap.isOpened()) {
        cap.release();
    }
}

bool GetFrameRGB(unsigned char* buffer, int width, int height) {
    if (!cap.isOpened()) {
        return false;
    }

    cap >> frame;

    if (frame.empty()) {
        return false;
    }

    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    cv::resize(frame, frame, cv::Size(width, height));
    memcpy(buffer, frame.data, width * height * 3);
    return true;
}