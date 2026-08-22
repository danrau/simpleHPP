#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <random>

const std::string simpleHPPversion = "simpleHPP.v0-1";

void simpleHPP() {
    std::cout << "Git: \"https://github.com/danrau/simpleHPP?tab=readme-ov-file\"" << std::endl;
    std::cout << simpleHPPversion << std::endl;
}

inline int randge(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

inline int randint() {
    return randge(1, 100); // This is default numbers. You may change they if you need.
}

inline void wait_mcsec(int mcsec) {
    std::this_thread::sleep_for(std::chrono::microseconds(mcsec));
}

inline void wait_min(int min) {
    std::this_thread::sleep_for(std::chrono::minutes(min));
}

inline void wait_mlsec(int mlsec) {
    std::this_thread::sleep_for(std::chrono::milliseconds(mlsec));
}

inline void wait_sec(int secnd) {
    std::this_thread::sleep_for(std::chrono::seconds(secnd));
}

inline void ccls() {
    std::system("cls");
}