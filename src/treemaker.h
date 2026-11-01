#pragma once

#include <iostream>
#include <vector>
#include <string>

typedef struct word_t{
    std::string content;
    int appearances;
    std::string previous_word;
    std::string next_word;
} word_t;

typedef std::vector<word_t> wordTree;

static void MakeTreeFromVec(std::vector<std::string> *word_vector, wordTree *word_tree)
{
    word_t temp_word;

    for (int i = 0; i < (*word_vector).size(); i++)
    {
        temp_word.content = (*word_vector)[i];
        temp_word.appearances = 1;
        temp_word.previous_word = (*word_vector)[i - 1];
        temp_word.next_word = (*word_vector)[i + 1];

        (*word_tree).push_back(temp_word);
    }
}