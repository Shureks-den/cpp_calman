#include <iostream>

#include "Parser/Parser.h"
#include "NoiseModel/NoiseModel.h"

int main() {
    auto parser = new Parser("./testData/output.dat");
    std::cout << parser->getDataLength();
    parser->printData(2);
    const int variableCount = parser->getRandomVariablesCount();
    auto data = parser->getData();

    auto noise = new NoiseModel(parser->getDataLength(), variableCount, "Gaussian");
    parser->applyNoise(noise->getNoise());
    parser->printData(2);
    return 0;
}