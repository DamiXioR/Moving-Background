#include "brick.h"

#include <cstdint>
#include <utility>

// public section

Brick::Brick (uint16_t hightPos, uint16_t widhtPos, char pattern) noexcept : hightPos_(hightPos), widhtPos_(widhtPos), pattern_(pattern) {}
