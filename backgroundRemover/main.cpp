#include <opencv2/opencv.hpp>

int main() {
    // Load the image
    cv::Mat image = cv::imread("C:\\Users\\leonv\\Desktop\\test.jpg", cv::IMREAD_UNCHANGED);

    // Convert the image to HSV color space
    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

    // Threshold the image to isolate white regions
    cv::Mat mask;
    cv::inRange(hsvImage, cv::Scalar(0, 0, 200), cv::Scalar(255, 50, 255), mask);

    // Apply the mask to the original image
    cv::Mat result;
    image.copyTo(result, mask);

    // Save the output image
    cv::imwrite("C:\\Users\\leonv\\Desktop\\test2.jpg", result);

    return 0;
}