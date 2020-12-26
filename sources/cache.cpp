// Copyright 2020 Andreytorix
#include <cache.hpp>

//инициализация памяти
//прогрев памяти
int* initMem(int len) {
    int* arr = new int[len];
    int k = 0;
    for (int i = 0; i < len; i++) {
        arr[i] = std::rand();
        k = arr[i];
    }
    return arr;
}

//Эксперимент прямой
double straightExperiment(size_t size, int *arr, int testCount) { //функция для прямого эксперимента
  //  std::cout << "straightExperiment start" << std::endl;
    int*  array = initMem(size); //функция инициализация памяти
    int k;
    for (size_t i = 0; i < size; i += offset) { //обращение к элементам массива (прогрев)
        k += array[i];
    }
    k = 0;
    //Начало эксперимента 
    auto start = std::chrono::high_resolution_clock::now(); //запоминаем текущее время  для подсчёта времени эксперимента
    for (size_t i = 0; i < size * testCount; i += offset) { // эксперимент с заданным кол-вом повторений
        k += array[i % size];
    }
    auto end = std::chrono::high_resolution_clock::now(); //запоминаем время конца эксперимента
    delete[] array;
   // std::cout << "straightExperiment stop" << std::endl;
    return
        static_cast<double>\
        (std::chrono::nanoseconds(end - start).count()) / testCount; //считаем время эксперимента и делим на количество попыток
    
}

//Эксперимент обратный
double backExperiment(size_t size, int* arr, int testCount) { //эксперимент обратный 
   // std::cout << "backExperiment start" << std::endl;
    int* array = initMem(size);
    int k = 0;
    //обращение к элементам массива (прогрев)
    for (size_t i = 0; i < size; i += offset) {
        k += array[i];
    }
    k = 0;
    //начало эксперимента
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = size * testCount; i > 0; i -= offset) { //обратный порядок обращения к элементам массива
        k += array[i % size];
       // std::cout << i << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    delete[] array;
  //  std::cout << "backExperiment stop" << std::endl;
    return
        static_cast<double>\
        (std::chrono::nanoseconds(end - start).count()) / testCount; //среднее время эксперимента
}

double randomExperiment(size_t size, int* arr, int testCount) { //эксперимент с рандомным обращение
    int* array = initMem(size);
    int k = 0;
    for (size_t i = 0; i < size; i += offset) { 
        k += array[i];
    }
    k = 0;
    auto start = std::chrono::high_resolution_clock::now();
    std::set<size_t> used;
    size_t l;
    int t = 0;
    std::vector<int> randZn;
    randZn.clear();
    for (int i = 1; i <= size / offset; i++) {
        randZn.push_back(i);
    }
    for (int j = 0; j < testCount; j++) {
    srand(unsigned(time(0)));
    random_shuffle(randZn.begin(), randZn.end());
    for (int i = 0; i < size / offset; i ++) { //рандомное обращение к памяти
        //std::cout << randZn[i] << std::endl;                
        k += array[randZn[i]];    
    }
    //std::cout << "Test # " << j << std::endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    delete[] array;
    return
        static_cast<double>(std::chrono::nanoseconds(end - start).count()) / testCount;
}
int main()
{
    //i5-10210U

    std::cout << "investigaion:" << std::endl;
    std::cout << "  travel_order: \"straight\"" << std::endl;
    std::cout << "  experiments:" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 1" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.150mb\"" << std::endl;
    int rarr = 0.150 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << straightExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 2" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 0.640 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << straightExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 3" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 5 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << straightExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 4" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 7 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << straightExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 5" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 9 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << straightExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;




    std::cout << "investigaion:" << std::endl;
    std::cout << "  travel_order: \"back\"" << std::endl;
    std::cout << "  experiments:" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 1" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.150mb\"" << std::endl;
    rarr = 0.150 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << backExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 2" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 0.640 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << backExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 3" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 5 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << backExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 4" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 7 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << backExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 5" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 9 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << backExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;


    std::cout << "investigaion:" << std::endl;
    std::cout << "  travel_order: \"random\"" << std::endl;
    std::cout << "  experiments:" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 1" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.150mb\"" << std::endl;
    rarr = 0.150 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << randomExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 2" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 0.640 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << randomExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 3" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 5 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << randomExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 4" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 7 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << randomExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
    std::cout << "  - experiment:" << std::endl;
    std::cout << "      number: 5" << std::endl;
    std::cout << "      input_data:" << std::endl;
    std::cout << "        buffer_size: \"0.640mb\"" << std::endl;
    rarr = 9 * 1024 * 1024; //размер массива
    std::cout << "      results:" << std::endl;
    std::cout << "        duration: \"" << randomExperiment(rarr, initMem(rarr), tCount) << "\"" << std::endl;
}
