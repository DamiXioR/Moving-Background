#include "backgroundLoader.h"

//public section

BackgroundLoader::BackgroundLoader(std::string fileName) noexcept : fileName_(fileName) {
    openFile();
    readFile();
}
BackgroundLoader::~BackgroundLoader(){
    closeFile();
}

//private section

void BackgroundLoader::openFile(){
    fileHandler_.open(fileName_.c_str(), std::ifstream::in);
}

void BackgroundLoader::readFile(){
    std::string line;
    numberOfColumns_ = 0;
    while(std::getline(fileHandler_, line)){
        loadedBackground_.emplace_back(bl::row{line});
        ++numberOfColumns_;
    }
    numberOfRows_ = line.size();
}

void BackgroundLoader::closeFile(){
    if(fileHandler_.is_open()){
        fileHandler_.close();
    }
}
