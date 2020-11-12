
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc//imgproc.hpp>

double sad(std::vector<int> baseImage, std::vector<int> comparisonImage){

    double sum = 0;

    for(int i = 0; i < 256; i++){
        std::vector<double> baseImageDouble(baseImage.begin(), baseImage.end());
        std::vector<double> comparisonImageDouble(comparisonImage.begin(), comparisonImage.end());
        sum += cv::abs(baseImageDouble[i] - comparisonImageDouble[i]);
    }

    return sum;

}