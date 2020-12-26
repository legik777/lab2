// Copyright 2020 Andreytorix
#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <utility>
#include <ctime>
#include <algorithm>
#include <set>

static const size_t offset = 16;
static const int tCount = 1000;
int* initMem(int len);
double straightExperiment(size_t size, int testCount);
double backExperiment(size_t size, int* arr, int testCount);
double randomExperiment(size_t size, int* arr, int testCount);
