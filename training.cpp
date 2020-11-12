//
// Created by alvin on 11/11/2020.
//

#include "training.h"
#include "model/imageModel.h"

void train(fs::path folderPath, string fileName){

    ofstream fileStreamTrain1(fileName);
    fileStreamTrain1.clear();
    for (const auto & entry: fs::directory_iterator(fs::path(folderPath).append("CMFD/"))){
        imageModel *image = new imageModel(fs::path(entry.path()), MaskLabel::CMFD, computeLBP(fs::path(entry.path())));
        fileStreamTrain1 << image->getLbpAsString(true);
    }
    for (const auto & entry: fs::directory_iterator(fs::path(folderPath).append("IMFD/"))){
        imageModel *image = new imageModel(fs::path(entry.path()), MaskLabel::IMFD, computeLBP(fs::path(entry.path())));
        fileStreamTrain1 << image->getLbpAsString(true);
    }
    fileStreamTrain1.close();

}