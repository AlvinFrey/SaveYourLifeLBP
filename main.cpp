
#include "utils.h"
#include "training.h"
#include "predict.h"

namespace fs = std::filesystem;
using namespace cv;
using namespace std;

int main() {

   /* cout << "GRAY TRAIN 1 - LBP Training started" << endl;

    train(fs::path(fs::current_path().append("dataset/GRAY/1TRAIN/")), "gray-train-1.txt");

    cout << "GRAY TRAIN 1 - Training file saved" << endl;*/

    cout << "GRAY PREDICT 1 - Predicting ..." << endl;

    predict(fs::path(fs::current_path().append("dataset/GRAY/1TEST/")));

    return 0;

}

