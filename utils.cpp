
#include "utils.h"

vector<int> computeLBP(fs::path path){

    Mat inputImage = imread(path, IMREAD_GRAYSCALE);

    auto multipliers = new tuple<Point, uchar>[8]{
            tuple<Point, int>(Point(-1, -1), 1),
            tuple<Point, int>(Point(0, -1), 2),
            tuple<Point, int>(Point(1, -1), 4),
            tuple<Point, int>(Point(-1, 0), 8),
            tuple<Point, int>(Point(1, 0), 16),
            tuple<Point, int>(Point(-1, 1), 32),
            tuple<Point, int>(Point(0, 1), 64),
            tuple<Point, int>(Point(1, 1), 128)
    };

    vector<int> data(256);

    for(int x = 1; x < inputImage.cols - 1; x++) {
        for (int y = 1; y < inputImage.rows - 1; y++) {

            uchar middlePixel = inputImage.at<uchar>(Point(x, y));

            uchar outputValue = 0;

            for (auto i = 0; i < 8; i++) {

                auto position = multipliers[i];

                Point offsetPoint = get<0>(position);

                uchar multiplier = get<1>(position);

                uchar pixel = inputImage.at<uchar>(Point(x, y) + offsetPoint);

                outputValue += (pixel >= middlePixel ? 1 : 0) * multiplier;

            }

            data[outputValue] = data[outputValue] + 1;

        }
    }

    return data;

}