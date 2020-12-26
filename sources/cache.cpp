// Copyright 2020 Andreytorix
#include <cache.hpp>
namespace testExperiments {
void voidFunc(int p) {
    p = p + 1;
}

int* initMem(int len) {
    int* arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = std::rand();
       int y = arr[i];
       voidFunc(y);
    }
    return arr;
}

double straightExperiment(size_t size,
                          int testCount) {
    int*  array = initMem(size);
    int k = 0;
    for (size_t i = 0; i < size; i += offset) {
        k += array[i];
    }
    k = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < size * testCount; i += offset) {
        k += array[i % size];
    }
    auto end = std::chrono::high_resolution_clock::now();
    delete[] array;
    return
        static_cast<double>\
        (std::chrono::nanoseconds(end - start).count()) / testCount;
}
double backExperiment(size_t size, int testCount) {
    int* array = initMem(size);
    int k = 0;
    for (size_t i = 0; i < size; i += offset) {
        k += array[i];
    }
    k = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = size * testCount; i > 0; i -= offset) {
        k += array[i % size];
    }
    auto end = std::chrono::high_resolution_clock::now();
    delete[] array;
    return
        static_cast<double>\
        (std::chrono::nanoseconds(end - start).count()) / testCount;
}

double randomExperiment(size_t size, int testCount) {
    int* array = initMem(size);
    int k = 0;
    for (size_t i = 0; i < size; i += offset) {
        k += array[i];
    }
    k = 0;
    auto start = std::chrono::high_resolution_clock::now();
    std::set<size_t> used;
    std::vector<int> randZn;
    randZn.clear();
    for (size_t i = 1; i <= size / offset; i++) {
        randZn.push_back(i);
    }
    for (int j = 0; j < testCount; j++) {
    srand(unsigned(time(0)));
    random_shuffle(randZn.begin(), randZn.end());
    for (size_t i = 0; i < size / offset; i ++) {
        k += array[randZn[i]];
    }
    }
    auto end = std::chrono::high_resolution_clock::now();
    delete[] array;
    return
        static_cast<double>
        (std::chrono::nanoseconds(end - start).count()) / testCount;
}
}
