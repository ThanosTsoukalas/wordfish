#pragma once 

#include <iostream>
#include <vector>
#include <string>

static void ParseWordsFromString(std::string *stringloc, std::vector<std::string> *vectroloc)
{
    std::string current_word = "";

    // convert the whole text to lowercase
    std::transform((*stringloc).begin(), (*stringloc).end(), (*stringloc).begin(),
    [](unsigned char c){ return std::tolower(c); });

    for (int i = 0; i < (*stringloc).length(); i++)
    {
        if ((*stringloc)[i] == ' ' || (*stringloc)[i] == '\n' || (*stringloc)[i] == '"')
        {
            if (current_word != "")
            {
                (*vectroloc).push_back(current_word);
            }
            current_word = "";
        }
        else if ((*stringloc)[i] != '.')
        {
            current_word = current_word + (*stringloc)[i];
        }
    }
}