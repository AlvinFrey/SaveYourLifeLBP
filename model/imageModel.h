
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
#include "../MaskLabel.h"

namespace fs = std::filesystem;
using namespace std;


class imageModel {

    private:
        fs::path _path;
        MaskLabel _label;
        vector<int> _lbp;
    public:
        imageModel(fs::path path, MaskLabel label, vector<int> lbp);
        MaskLabel getLabel();
        vector<int> getLbp();
        std::string getLbpAsString(bool showLabel);
        static vector<imageModel> loadFile(fs::path path);

};