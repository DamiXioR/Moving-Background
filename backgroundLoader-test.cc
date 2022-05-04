#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "backgroundLoader.h"

TEST(BackgroundLoaderTest, loadingBackgroundFromFileAndGetIt) {
    BackgroundLoader bl{"background.txt"};
    auto backgroundLoadedFromFile = bl.getLoadedBackground();
    
    bl::background expectedBackground {
        {"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"},
        {"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"},
        {"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"},
        {"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"},
        {"BBBBBBBBBBBBXBBBBBBBBBBBBBBBBBBBBB"},
        {"BBBBBBBBBBBXXXBBBBBBBBBBBBBBBBBBBB"},
        {"BBBBBBBBBXXXXXXXBBBBBBBBBBBBBBBBBB"},
        {"BBBBBBBBXXXXXXXXXXBBBBBBBBBBBBBBBB"},
        {"BBBBXXXXXXXXXXXXXXXXXXBBBBBBBBBBBB"},
        {"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"}
    };
    
    EXPECT_EQ(backgroundLoadedFromFile, expectedBackground);
}
