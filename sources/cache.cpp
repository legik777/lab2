// Copyright 2020 Andreytorix
#include <cache.hpp>

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
    int k;
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
   // std::cout << "straightExperiment stop" << std::endl;
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
int main()
{
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
}
