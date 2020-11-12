//
// Created by alvin on 11/11/2020.
//

#include "imageModel.h"

imageModel::imageModel(fs::path path, MaskLabel label, vector<int> lbp) {

    _path = path;
    _label = label;
    _lbp = lbp;

}

MaskLabel imageModel::getLabel() {
    return _label;
}

vector<int> imageModel::getLbp() {
    return _lbp;
}

string imageModel::getLbpAsString(bool showLabel) {

    stringstream outputStringStream;

    for(int i = 0; i < 256; i++){

        if(i<255){

            outputStringStream << _lbp[i] << ",";

        }else{

            if(showLabel){

                outputStringStream << _lbp[i] << ":" << _label;

            }else{

                outputStringStream << _lbp[i];

            }

        }


    }

    outputStringStream << endl;

    return outputStringStream.str();

}

vector<imageModel> imageModel::loadFile(fs::path path) {

    vector<imageModel> output;

    std::ifstream inputFile(path);

    if(inputFile.is_open()){
        string line;
        while(getline(inputFile, line)){

            vector<int> data;

            stringstream ss(line);
            string split;

            while(getline(ss, split,',')){
                data.push_back(stoi(split.substr(0, split.find(':'))));
            }

            MaskLabel label = MaskLabel::UNKNOWN;

            if(stoi(line.substr(line.find(':')+1)) == 1){
                label = MaskLabel::CMFD;
            }else if(stoi(line.substr(line.find(':')+1)) == 0){
                label = MaskLabel::IMFD;
            }

            imageModel *image = new imageModel("", label, data);
            output.push_back(*image);
        }
        inputFile.close();
    }

    return output;

}
