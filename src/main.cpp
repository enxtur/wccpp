#include <fstream>
#include <iostream>
#include <string>
#include "utils.h"

int main(int argc, char* argv[]) {
    char* file_name = NULL;
    bool count_bytes = false;
    bool count_lines = false;
    bool count_words = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            count_bytes = true;
        } else if (strcmp(argv[i], "-l") == 0) {
            count_lines = true;
        } else if (strcmp(argv[i], "-w") == 0) {
            count_words = true;
        } else {
            file_name = argv[i];
        }
    }

    if (file_name == NULL) {
        std::cerr << "Provide file name" << std::endl;
        return 1;
    }

    std::ifstream input_file;

    input_file.open(file_name);

    if (!input_file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    if (count_bytes) {
        char byte;
        int count = 0;
        while(input_file.get(byte)) {
            count++;
        }
        std::cout << file_name << " " << count << std::endl;
    } else if (count_lines) {
        std::string line;
        int count = 0;
        while(std::getline(input_file, line)) {
            count++;
        }
        std::cout << file_name << " " << count << std::endl;
    } else if (count_words) {
        std::string word;
        int count = 0;
        while (input_file >> word) {
            count++;
        }
        std::cout << file_name << " " << count << std::endl;
    }

    input_file.close();
    
    return 0;
}