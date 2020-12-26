// Copyright 2020 Andreytorix
#include "cache.hpp"
#include <iostream>
#include <gtest/gtest.h>
#include "../sources/cache.cpp"
TEST(Test, straightBackExperiment) {
        std::cout << "investigaion:" << std::endl;
    std::cout << "  travel_order: \"straight\"" << std::endl;
    std::cout << "  experiments:" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 1" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.150mb\"" << std::endl;
    int rarr = 0.150 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
       straightExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 2" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 0.640 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        straightExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 3" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 5 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        straightExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 4" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 7 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        straightExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 5" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 9 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        straightExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "investigaion:" << std::endl;
    std::cout << "  travel_order: \"back\"" << std::endl;
    std::cout << "  experiments:" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 1" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.150mb\"" << std::endl;
    rarr = 0.150 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        backExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 2" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 0.640 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        backExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 3" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 5 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        backExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 4" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 7 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        backExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 5" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 9 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        backExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "investigaion:" << std::endl;
    std::cout << "  travel_order: \"random\"" << std::endl;
    std::cout << "  experiments:" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 1" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.150mb\"" << std::endl;
    rarr = 0.150 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        randomExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 2" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 0.640 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        randomExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 3" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 5 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        randomExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 4" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 7 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        randomExperiment(rarr, tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 5" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 9 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" <<
        randomExperiment(rarr, tCount) << "\"" << std::endl;
    bool t1 = false;
    rarr = 0.150 * 1024 * 1024; //размер массива
    if (straightExperiment(rarr, tCount)
        < backExperiment(rarr, tCount)) {
        EXPECT_EQ(t1, true);
    }
}
