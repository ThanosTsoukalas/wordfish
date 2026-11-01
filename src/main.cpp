#include <iostream>
#include <vector>

#include "opener.h"
#include "parser.h"
#include "treemaker.h"
#include "predictor.h"

int main()
{
    // Open the text file for reading
    std::string training_data;
    std::vector<std::string> word_list;
    wordTree word_tree;

    CopyFleToVar("/Users/thanossoublakopitas/Desktop/Development/wordfish/src/data.txt", &training_data);
    ParseWordsFromString(&training_data, &word_list);
    MakeTreeFromVec(&word_list, &word_tree);

    // for (word_t word : word_tree)
    // {
    //     std::cout << "Current word: " << word.content <<
    //     " | Previous word: " << word.previous_word << 
    //     " | Next word: " << word.next_word << 
    //     " | Appearances: " << word.appearances <<  std::endl;
    // }
    // std::cout << std::endl;

    std::string starting_word;
    std::cout << "> ";
    std::cin >> starting_word;
    std::cout << std::endl;

    while (true)
    {
        std::cout << "> ";
        std::cin >> starting_word;
        std::cout << std::endl;

        std::cout << "Next word is: " << PredictNextWord(starting_word, &word_tree) << std::endl;
    }
    
    return 0;
}