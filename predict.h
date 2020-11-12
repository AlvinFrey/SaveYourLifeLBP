
#include "opencv2/opencv.hpp"
#include "MaskLabel.h"
#include "utils.h"

#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

namespace fs = std::filesystem;
using namespace cv;
using namespace std;

void predict(fs::path folderPath);