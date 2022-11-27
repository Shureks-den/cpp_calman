//
// Created by Александр Клонов on 27.11.2022.
//

#include "NoiseModel.h"
#include <random>

NoiseModel::NoiseModel(int dataSize, int variablesNum, const std::string& mode) {
    std::vector<std::vector<double>> dataVector(dataSize);
    for (auto &i: dataVector) {
        if (mode == "whiteNoise") {
            i = NoiseModel::generateWhiteNoiseUniform(variablesNum);
        } else if (mode == "Gaussian") {
            i = NoiseModel::generateGaussianNoise(variablesNum);
        }
    }
    this->noiseData = dataVector;
}

std::vector<double> NoiseModel::generateWhiteNoiseUniform(int count) {
    std::vector<double> res(count);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(-1, 1);
    for (auto &i: res) {
        i = distr(eng);
    }
    return res;
}

std::vector<double> NoiseModel::generateGaussianNoise(int count) {
    std::vector<double> res(count);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine eng(seed);
    std::normal_distribution<double> distr(0.0, 1.0);
    for (int i = 0; i < count; i++) {
        res.at(i) = distr(eng);
    }
    return res;
}

std::vector<std::vector<double>> NoiseModel::getNoise() {
    return this->noiseData;
}
