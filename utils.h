
#include "MaskLabel.h"

#include "opencv2/opencv.hpp"
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

namespace fs = std::filesystem;
using namespace cv;
using namespace std;

vector<int> computeLBP(fs::path path);