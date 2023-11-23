#include "opencv2/opencv.hpp"

int main() {
    // 이미지 불러오기
    cv::Mat image1 = cv::imread("image1.jpg");
    cv::Mat image2 = cv::imread("image2.jpg");

    if (image1.empty() || image2.empty()) {
        std::cout << "Error: Could not read one or both images." << std::endl;
        return -1;
    }

    // 이미지 크기가 같다고 가정
    if (image1.size() != image2.size()) {
        std::cout << "Error: Images have different sizes." << std::endl;
        return -1;
    }

    // 이미지 합성
    cv::Mat blendedImage;
    double alpha = 0.5; // 합성 가중치 (0.0부터 1.0까지)
    cv::addWeighted(image1, alpha, image2, 1.0 - alpha, 0.0, blendedImage);

    // 합성 결과를 저장하거나 표시
    cv::imwrite("blended_image.jpg", blendedImage);
    cv::imshow("Blended Image", blendedImage);
    cv::waitKey(0);

    return 0;
}