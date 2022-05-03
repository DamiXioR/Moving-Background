#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <vector>

#include "backgroundLoader.h"
#include "brick.h"

namespace bg {
    using background = std::vector<std::vector<Brick>>;
    using row = std::vector<Brick>;
}

class Background {
public:
    explicit Background(uint16_t hight, uint16_t widht, bl::background loadedBackground) noexcept : hight_(hight), widht_(widht) {
        reserveBackground();
        createBackground(loadedBackground);
    }
    bg::background getBackground() const {
        return background_;
    }
private:
    uint16_t hight_;
    uint16_t widht_;

    bg::background background_;

    void createBackground (bl::background loadedBackground) {
        uint16_t height{0};
        uint16_t width{0};
            std::transform(loadedBackground.begin(), loadedBackground.end(), std::back_inserter(background_), [&height, &width] (bl::row& loadedBackgroundRow) {
                bg::row backgroundRow;
                for(const auto& singleBrick : loadedBackgroundRow) {
                    backgroundRow.emplace_back(Brick{height, width, singleBrick});
                    ++width;
                }
                ++height;
                width = 0;
                return backgroundRow;
            });
    }

    void reserveBackground(){
        background_.reserve(hight_);
        for(auto& brickRow : background_){
            brickRow.reserve(widht_);
        }
    }

};

#endif // BACKGROUND_H