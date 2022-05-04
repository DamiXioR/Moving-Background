#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "background.h"
#include "backgroundLoader.h"

#include <memory>

class BackgroundTest : public ::testing::Test {
public:
    BackgroundTest() {
        loadBackgroundFromFile();
        createBricksBackground();
    }

    void loadBackgroundFromFile() {
        bl = std::make_unique<BackgroundLoader>("background.txt");
        backgroundLoadedFromFile = std::make_unique<bl::background>(bl->getLoadedBackground());
        auto [h, w] = bl->getNumberOfColumnsAndRows();
        height = h;
        width = w;
    }

    void createBricksBackground() {
        bg = std::make_unique<Background>(height, width, *backgroundLoadedFromFile);
        backgroundBricks = std::make_unique<bg::background>(bg->getBackground());
    }

    std::unique_ptr<BackgroundLoader>  bl;
    std::unique_ptr<bl::background> backgroundLoadedFromFile;
    std::unique_ptr<Background> bg;
    std::unique_ptr<bg::background> backgroundBricks;

    uint16_t height;
    uint16_t width;
};

TEST_F(BackgroundTest, BackgroundBricksAreInitializedWithLoadedBackground) {
    uint16_t heightCounter{0};
    uint16_t widthCounter{0};
    for(const auto& backgroundRow : *backgroundBricks) {
        for(const auto& brick : backgroundRow){
            auto [height, width] = brick.getPosition();
            EXPECT_EQ(heightCounter, height);
            EXPECT_EQ(widthCounter, width);
            ++widthCounter;
        }
        ++heightCounter;
        widthCounter = 0;
    }
}
