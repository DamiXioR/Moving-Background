#include "background.h"

#include <algorithm>
#include <iterator>

// public section

Background::Background(uint16_t hight, uint16_t widht, bl::background loadedBackground) noexcept : hight_(hight), widht_(widht) {
    reserveBackground();
    createBackground(loadedBackground);
}

// private section

void Background::createBackground (bl::background loadedBackground) {
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

void Background::reserveBackground(){
    background_.reserve(hight_);
    for(auto& brickRow : background_){
        brickRow.reserve(widht_);
    }
}
