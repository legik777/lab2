// Copyright 2020 Andreytorix
#include "cache.hpp"
#include <gtest/gtest.h>

TEST(Test, straightBackExperiment) {
    bool t1 = false;
    int rarr = 0.150 * 1024 * 1024; //размер массива
    if (straightExperiment(rarr, tCount) < backExperiment(rarr, initMem(rarr), tCount)) {
        EXPECT_EQ(t1, true);
    }
}
