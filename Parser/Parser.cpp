//
// Created by Александр Клонов on 22.11.2022.
//


#include "Parser.h"

std::vector<std::string> SplitString(const std::string& str,
                                      const std::string& delimiter) {
    std::vector<std::string> strings;

    std::string::size_type pos;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos) {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + delimiter.size();
    }

    // To get the last substring (or only, if delimiter is not found)
    strings.push_back(str.substr(prev));

    return strings;
}

Parser::Parser(const std::string& filePath) {
    std::string line;
    std::ifstream in(filePath); // окрываем файл для чтения
    if (in.is_open()) {
        while (getline(in, line)) {
            const auto res = SplitString(line, "  ");
            int counter = 0;
            auto data = new Data();
            for (auto i: res) {
                if (!i.empty()) {
                    switch (counter) {
                        case 0:
                            data->time = std::stod(i);
                            break;
                        case 1:
                            data->pX = std::stod(i);
                            break;
                        case 2:
                            data->pY = std::stod(i);
                            break;
                        case 3:
                            data->pZ = std::stod(i);
                            break;
                        case 4:
                            data->vX = std::stod(i);
                            break;
                        case 5:
                            data->vY = std::stod(i);
                            break;
                        case 6:
                            data->vZ = std::stod(i);
                            break;
                        default:
                            break;
                    }
                    counter++;
                }
            }
            this->parsedData.push_back(*data);
        }
    }
    in.close();
}

void Parser::printData(int head) {
    std::cout << std::setprecision(10);
    short counter = 0;
    for (auto i: this->parsedData) {
        std::cout << "time: " << i.time << "  x:" << i.pX << "  y: " << i.pY << "  z: " << i.pZ
            << std::endl << "Vx: " << i.vX << "  Vy: " << i.vY << "  Vz: " << i.vZ << std::endl << std::endl;
        counter++;
        if (head != 0 && counter >= head) {
            return;
        }
    }
}

int Parser::getDataLength() {
    return this->parsedData.size();
}

int Parser::getRandomVariablesCount() {
    return sizeof(this->parsedData.at(0)) / sizeof(double) - 1;
}

std::vector<Data> Parser::getData() {
    return this->parsedData;
}

void Parser::applyNoise(const std::vector<std::vector<double>>& noise) {
    const int dataSize = this->getDataLength();
    for (int i = 0; i < dataSize; i++) {
        this->parsedData[i].pX += noise[i][0];
        this->parsedData[i].pY += noise[i][1];
        this->parsedData[i].pZ += noise[i][2];
        this->parsedData[i].vX += noise[i][3];
        this->parsedData[i].vY += noise[i][4];
        this->parsedData[i].vZ += noise[i][5];
    }
}
