#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "treemaker.h"

typedef struct TreeFinding{
    std::vector<int> indexlist; // contains a list of index numbers in a word_tree
    int appearances = indexlist.size();
} tree_f; 

// vector size comparator function
bool comp(tree_f a, tree_f b)
{
    return a.appearances > b.appearances;
}

static tree_f SeacrhInTree(wordTree *word_tree, std::string search_term)
{
    std::vector<int> index_list;

    for (int i = 0; i < (*word_tree).size(); i++)
    {
        if (((*word_tree)[i]).content == search_term)
        {
            index_list.push_back(i);
        }
    }

    return {index_list};
}

static std::string PredictNextWord(std::string curr_word, wordTree *word_tree)
{
    // This is gonna be complex
    // Just brace yourselves

    tree_f curr_word_data = SeacrhInTree(word_tree, curr_word);

    // search for the next word of every occurence of the current word in the training data
    std::vector<tree_f> predicted_wordList;

    for (int i= 0; i < curr_word_data.appearances; i++)
    {
        predicted_wordList.push_back(SeacrhInTree(word_tree, ((*word_tree)[curr_word_data.indexlist[i] + 1]).content));
    }
    std::sort(predicted_wordList.begin(), predicted_wordList.end(), comp);


    return ((*word_tree)[(predicted_wordList[0].indexlist[0])]).content;

}