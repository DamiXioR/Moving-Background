#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <cstdint>
#include <vector>

#include "backgroundLoader.h"
#include "brick.h"

namespace bg {
    using background = std::vector<std::vector<Brick>>;
    using row = std::vector<Brick>;
}

class Background {
public:
    explicit Background(uint16_t hight, uint16_t widht, bl::background loadedBackground) noexcept;
    bg::background getBackground() const {
        return background_;
    }
    
private:
    uint16_t hight_;
    uint16_t widht_;

    bg::background background_;

    void createBackground (bl::background loadedBackground);
    void reserveBackground();
};

#endif // BACKGROUND_H
