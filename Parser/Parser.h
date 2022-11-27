//
// Created by Александр Клонов on 22.11.2022.
//

#ifndef CALMAN_PARSER_H
#define CALMAN_PARSER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

struct Data {
    double time;
    double pX;
    double pY;
    double pZ;

    double vX;
    double vY;
    double vZ;
};

class Parser {
public:
    Parser(const std::string& filePath);
    std::vector<Data> getData();
    void printData(int head = 0);
    int getDataLength();
    int getRandomVariablesCount();
    void applyNoise(const std::vector<std::vector<double>>& noise);
private:
    std::string filePath;
    std::vector<Data> parsedData;
};


#endif //CALMAN_PARSER_H
