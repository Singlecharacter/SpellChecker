#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

class TrieNode
{
public:

    TrieNode(std::string s = "");
    ~TrieNode();
    std::string data;
    bool endOfWord;

    std::vector<TrieNode*> children;
};

class Trie
{
public:

    Trie();
    ~Trie();
    void addWord(std::string newWord);
    bool checkWord(std::string word);
    std::vector<std::string> getSuggestions(std::string word);

    //void compress(TrieNode *start = NULL);

private:

    TrieNode *root;
};

#endif // TRIE_H
