#ifndef BRICK_H
#define BRICK_H

#include <cstdint>
#include <utility>

class Brick {
public:
    explicit Brick (uint16_t hightPos, uint16_t widhtPos, char pattern) noexcept : hightPos_(hightPos), widhtPos_(widhtPos), pattern_(pattern) {}
    std::pair<uint16_t, uint16_t> getPosition() const {
        return std::make_pair(hightPos_, widhtPos_);
    }
private:
    uint16_t hightPos_;
    uint16_t widhtPos_;
    char pattern_;
};
    
#endif // BRICK_H