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
    explicit BackgroundLoader(std::string fileName) noexcept;
    ~BackgroundLoader();

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

    void openFile();
    void readFile();
    void closeFile();
};

#endif // BACKGROUNDLOADER_H
