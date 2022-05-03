#ifndef BACKGROUNDLOADER_H
#define BACKGROUNDLOADER_H

#include <cstdint>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

namespace bl {
    using background =  std::vector<std::string>;
    using row = std::string;
}

class BackgroundLoader {
public:
    explicit BackgroundLoader(std::string fileName) noexcept : fileName_(fileName) {
        openFile();
        readFile();
    }
    ~BackgroundLoader(){
        closeFile();
    }

    bl::background getLoadedBackground() const {
        return loadedBackground_;
    }

    std::pair<uint16_t, uint16_t> getNumberOfColumnsAndRows() const {
        return std::make_pair(numberOfColumns_, numberOfRows_);
    }
private:
    std::ifstream fileHandler_;
    std::string fileName_;
    bl::background loadedBackground_;

    uint16_t numberOfColumns_;
    uint16_t numberOfRows_;

    void openFile(){
        fileHandler_.open(fileName_.c_str(), std::ifstream::in);
    }

    void readFile(){
        std::string line;
        numberOfColumns_ = 0;
        while(std::getline(fileHandler_, line)){
            loadedBackground_.emplace_back(bl::row{line});
            ++numberOfColumns_;
        }
        numberOfRows_ = line.size();
    }
    
    void closeFile(){
        if(fileHandler_.is_open()){
            fileHandler_.close();
        }
    }
};

#endif // BACKGROUNDLOADER_H