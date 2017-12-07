#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits.h>
#include <stdlib.h>

int main() {
    std::fstream in;
    std::string line, word;
    int max, min, current, checksum = 0;

    in.open("inputs/day2.in", std::fstream::in);

    while(std::getline(in, line)) {
        std::istringstream iss(line, std::istringstream::in);
        max = INT_MIN;
        min = INT_MAX;
        
        while (iss >> word) {
            current = atoi(word.c_str());
            max = std::max(max, current);
            min = std::min(min, current);
        }

        checksum += (max - min);
    }

    std::cout << checksum << "\n";
    return 0;
}