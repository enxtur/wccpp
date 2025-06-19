#include <fstream>
#include <iostream>
#include <string>
#include "utils.h"

int main(int argc, char* argv[]) {
    bool count_bytes = false;
    char* file_name = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            count_bytes = true;
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
    }

    input_file.close();
    
    return 0;
}