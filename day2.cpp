#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits.h>
#include <stdlib.h>
#include <vector>

int main() {
    std::fstream in;
    std::string line, word;
    int max, min, current, checksum = 0;
    std::vector<int> lineNumbers;
    bool found;

    in.open("inputs/day2.in", std::fstream::in);

    while(std::getline(in, line)) {
        std::istringstream iss(line, std::istringstream::in);
        lineNumbers.clear();
        max = INT_MIN;
        min = INT_MAX;
        /* PART 2 */
        found = false;
        
        while (!found && iss >> word) {
            current = atoi(word.c_str());
            /* PART 1
            
            max = std::max(max, current);
            min = std::min(min, current);
            */

            /* PART 2 */
            for (auto number : lineNumbers) {
                max = std::max(number, current);
                min = std::min(number, current);
                if (max != 0 && min != 0 && max % min == 0) {
                    checksum += (max / min);
                    found = true;
                    break;
                }
            }

            lineNumbers.push_back(current);
        }

        /* PART 1

        checksum += (max - min);
        */
    }

    std::cout << checksum << "\n";
    return 0;
}