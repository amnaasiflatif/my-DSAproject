#ifndef DICTIONARYTRIE_H
#define DICTIONARYTRIE_H
#include <Node.h>
#include <string>
#include <vector>

using namespace std;

class DictionaryTrie
{
    public:
        Node* root;
        // Constructor
        DictionaryTrie();
        // Default Constructor
        virtual ~DictionaryTrie();
        // Search the word in a trie
        bool search(string word);
        // Insert the word in a trie
        void insert(string word);
        // To get the root node
        Node* get_root();

    protected:

    private:
};

#endif // DICTIONARYTRIE_H
