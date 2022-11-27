//
// Created by Александр Клонов on 27.11.2022.
//

#ifndef CALMAN_NOISEMODEL_H
#define CALMAN_NOISEMODEL_H


#include <string>
#include <vector>

class NoiseModel {
public:
    NoiseModel(int dataSize, int variablesNum, const std::string& mode);
    std::vector<std::vector<double>> getNoise();
private:
    std::vector<std::vector<double>> noiseData;
    static std::vector<double> generateWhiteNoiseUniform(int count);
    static std::vector<double> generateGaussianNoise(int count);
};


#endif //CALMAN_NOISEMODEL_H
