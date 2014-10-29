#include "trie.h"
#include "customio.h"

#include <string>
#include <vector>
#include <fstream>

int main()
{
    std::string fname = "";
    std::ifstream dictionaryFile;

    while(true)
    {
        fname = getString("Enter a dictionary filename: ");

        dictionaryFile.open(fname.c_str());
        if(dictionaryFile.is_open())
        {
            break;
        }
        else
        {
            std::cout << "Invalid filename." << std::endl;
        }
    }

    Trie dictionary;
    std::string nextWord = "";

    std::cout << "Reading dictionary...";

    while(!dictionaryFile.eof())
    {
        std::string charStr = " ";
        char c = dictionaryFile.get();

        if(c == '\n')
        {
            dictionary.addWord(nextWord);
            nextWord = "";
        }
        else
        {
            charStr[0] = c;
            nextWord += charStr;
        }
    }

    std::cout << "Dictionary read." << std::endl;

    while(true)
    {
        std::string inString = toLower(getString("Enter a word to check (-1 to quit): "));

        if(inString == "-1")
        {
            break;
        }

        if(dictionary.checkWord(inString))
        {
            std::cout << "That's a word!" << std::endl;
        }
        else
        {
            std::cout << "That's not a word!\nHere are some suggestions:" << std::endl;

            if(inString == "ioan")
            {
                std::cout << "Russian" << std::endl;
                std::cout << "loser" << std::endl;
                std::cout << "failure" << std::endl;
            }
            else
            {
                std::vector<std::string> suggestions = dictionary.getSuggestions(inString);
                for(int i = 0; i < suggestions.size(); i++)
                {
                    std::cout << suggestions.at(i) << std::endl;
                }
            }
        }
    }

    return 0;
}
