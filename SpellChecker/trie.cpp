#include "trie.h"
#include <iostream>

//TrieNode methods

TrieNode::TrieNode(std::string s) : endOfWord(false)
{
    data = s;
    children.clear();
}

TrieNode::~TrieNode()
{
    children.clear();
}

//Trie methods

Trie::Trie()
{
    root = new TrieNode();

    //Initialize root with the entire alphabet
    root->children.push_back(new TrieNode("a"));
    root->children.push_back(new TrieNode("b"));
    root->children.push_back(new TrieNode("c"));
    root->children.push_back(new TrieNode("d"));
    root->children.push_back(new TrieNode("e"));
    root->children.push_back(new TrieNode("f"));
    root->children.push_back(new TrieNode("g"));
    root->children.push_back(new TrieNode("h"));
    root->children.push_back(new TrieNode("i"));
    root->children.push_back(new TrieNode("j"));
    root->children.push_back(new TrieNode("k"));
    root->children.push_back(new TrieNode("l"));
    root->children.push_back(new TrieNode("m"));
    root->children.push_back(new TrieNode("n"));
    root->children.push_back(new TrieNode("o"));
    root->children.push_back(new TrieNode("p"));
    root->children.push_back(new TrieNode("q"));
    root->children.push_back(new TrieNode("r"));
    root->children.push_back(new TrieNode("s"));
    root->children.push_back(new TrieNode("t"));
    root->children.push_back(new TrieNode("u"));
    root->children.push_back(new TrieNode("v"));
    root->children.push_back(new TrieNode("w"));
    root->children.push_back(new TrieNode("x"));
    root->children.push_back(new TrieNode("y"));
    root->children.push_back(new TrieNode("z"));
}

Trie::~Trie()
{
    delete root;
}

void Trie::addWord(std::string newWord)
{
    TrieNode *currentNode = root;

    for(int i = 0; i < newWord.length(); i++)
    {
        if(currentNode->children.size() > 0)
        {
            bool foundLetter = false;
            for(int j = 0; j < currentNode->children.size(); j++)
            {
                std::string checkStr = currentNode->children.at(j)->data;
                std::string charStr = newWord.substr(i,1);
                if(checkStr == charStr)
                {
                    currentNode = currentNode->children.at(j);
                    foundLetter = true;
                    break;
                }
            }

            if(!foundLetter)
            {
                currentNode->children.push_back(new TrieNode(newWord.substr(i,1)));
                currentNode = currentNode->children.at(currentNode->children.size()-1);
            }
        }
        else
        {
            currentNode->children.push_back(new TrieNode(newWord.substr(i,1)));
            currentNode = currentNode->children.at(0);
        }
    }

    currentNode->endOfWord = true;
}

bool Trie::checkWord(std::string word)
{
    TrieNode *currentNode = root;

    bool foundLetter = false;
    for(int i = 0; i < word.length(); i++)
    {
        foundLetter = false;

        for(int j = 0; j < currentNode->children.size(); j++)
        {
            std::string checkStr = currentNode->children.at(j)->data;
            std::string charStr = word.substr(i,1);
            if(checkStr == charStr)
            {
                currentNode = currentNode->children.at(j);
                foundLetter = true;
                break;
            }
        }

        if(!foundLetter)
        {
            return false;
        }
    }

    if(currentNode->endOfWord)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<std::string> Trie::getSuggestions(std::string word)
{
    TrieNode *currentNode = root;

    std::vector<std::string> suggestions;

    bool foundLetter = false;
    for(int i = 0; i < word.length(); i++)
    {
        foundLetter = false;

        for(int j = 0; j < currentNode->children.size(); j++)
        {
            std::string checkStr = currentNode->children.at(j)->data;
            std::string charStr = word.substr(i,1);
            if(checkStr == charStr)
            {
                currentNode = currentNode->children.at(j);
                foundLetter = true;
                break;
            }
        }

        if(!foundLetter)
        {
            for(int j = 0; j < currentNode->children.size(); j++)
            {
                if(currentNode->children.at(j)->endOfWord)
                {
                    suggestions.push_back(word.substr(0,i)+currentNode->children.at(j)->data);
                }
            }

            if(suggestions.size() == 0)
            {
                suggestions.push_back("No suggestions");
            }

            return suggestions;
        }
    }

    suggestions.push_back("No suggestions");
    return suggestions;
}
