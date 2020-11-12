
#include "predict.h"
#include "model/imageModel.h"
#include "distance.h"

size_t numberOfFilesInDir(fs::path path){
    using filesystem::directory_iterator;
    return distance(directory_iterator(path), directory_iterator{});
}

void predict(fs::path folderPath){

    int correct = 0;
    int incorrect = 0;

    vector<imageModel> trainingImages = imageModel::loadFile(fs::path(fs::current_path().append("gray-train-1.txt")));

    size_t fileCount = numberOfFilesInDir(fs::path(folderPath).append("CMFD/"));
    int count = 0;

    for (const auto & entry: fs::directory_iterator(fs::path(folderPath).append("CMFD/"))){

        count++;

        imageModel *image = new imageModel(fs::path(entry.path()), MaskLabel::CMFD, computeLBP(fs::path(entry.path())));
        vector<int> baseImageLbp = image->getLbp();

        cout << "IMAGE N°" << count << "/" << fileCount;

        double minDifference = std::numeric_limits<double>::max();
        MaskLabel foundLabel;

        for(imageModel trainingImage:trainingImages){

            vector<int> trainingImageLbp = trainingImage.getLbp();

            double sadOutput = sad(baseImageLbp, trainingImageLbp);

            if(sadOutput < minDifference){
                foundLabel = trainingImage.getLabel();
                minDifference = sadOutput;
            }

            //cout << trainingImage.getLbpAsString(false) << endl;
        }

        cout << " : " << foundLabel;

        if(foundLabel == image->getLabel()){
            cout << " -> CORRECT" << endl;
            correct++;
        }else{
            cout << " -> INCORRECT" << endl;
            incorrect++;
        }

        // LOAD FILE IMAGE MODEL
        // LOOPER CHAQUE ENTREE
        // PLUS TARD : LOOPER CHAQUE DIFFERENCE
        //  FAIRE LA DIFFERENCE AVEC BASE IMAGE
        //  PLUS PETITE DIFFERENCE = PREDICTED
        // SI PREDICTED == CMFD ALORS GOOD SINON BAD

    }

    cout << "CMFD RESULT : " << endl;
    cout << "Correct : " << correct << " / Incorrect : " << incorrect << endl;

    cout << "Ratio : " << correct / (correct+incorrect);

    correct = 0;
    incorrect = 0;

    size_t imfdFileCount = numberOfFilesInDir(fs::path(folderPath).append("IMFD/"));
    int imfdCount = 0;

    for (const auto & entry: fs::directory_iterator(fs::path(folderPath).append("IMFD/"))){

        imfdCount++;

        imageModel *image = new imageModel(fs::path(entry.path()), MaskLabel::IMFD, computeLBP(fs::path(entry.path())));
        vector<int> baseImageLbp = image->getLbp();

        cout << "IMAGE N°" << imfdCount << "/" << imfdFileCount;

        double minDifference = std::numeric_limits<double>::max();
        MaskLabel foundLabel;

        for(imageModel trainingImage:trainingImages){

            vector<int> trainingImageLbp = trainingImage.getLbp();

            double sadOutput = sad(baseImageLbp, trainingImageLbp);

            if(sadOutput < minDifference){
                foundLabel = trainingImage.getLabel();
                minDifference = sadOutput;
            }

            //cout << trainingImage.getLbpAsString(false) << endl;
        }

        cout << " : " << foundLabel;

        if(foundLabel == image->getLabel()){
            cout << " -> CORRECT" << endl;
            correct++;
        }else{
            cout << " -> INCORRECT" << endl;
            incorrect++;
        }

        // LOAD FILE IMAGE MODEL
        // LOOPER CHAQUE ENTREE
        // PLUS TARD : LOOPER CHAQUE DIFFERENCE
        //  FAIRE LA DIFFERENCE AVEC BASE IMAGE
        //  PLUS PETITE DIFFERENCE = PREDICTED
        // SI PREDICTED == CMFD ALORS GOOD SINON BAD

    }

    cout << "IMFD RESULT : " << endl;

    cout << "Correct : " << correct << " / Incorrect : " << incorrect << endl;

    cout << "Ratio : " << correct / (correct+incorrect);

}