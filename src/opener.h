#pragma once 

#include <iostream>
#include <fstream>
#include <string>

static void CopyFleToVar(const char *directory, std::string *varLocation)
{
    // Open the text file for reading
    std::ifstream file(directory);

    // Check if the file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Error opening the file!";
    }

    std::string s;
    std::string data;
    // Read each line from the file
    while (std::getline(file, s))
        data = data + s + "\n";

    // Close the file
    *varLocation = data;

    file.close();
}