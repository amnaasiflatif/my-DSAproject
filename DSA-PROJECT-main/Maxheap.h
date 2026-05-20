#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct heapNode
{
    int length;
    int size;
    vector<string> words_array;
};

class Maxheap
{
    public:
        // Constructor
        Maxheap(int capacity= 8);
        // Destructor
        virtual ~Maxheap();
        // Add the word in a heap
        void add_word(string word);
        // Remove the word from the heap
        string remove_word();
        // Check if the heap is empty
        bool isEmpty();

    protected:

    private:
        vector<heapNode*> max_heap;
        int heap_size;
        // Insert the new node in a heap
        void insert_node(string word);
        // To search the node in a heap
        heapNode* search_node(int length);
        // Validate the max heap by moving down
        void percolate_down();
        // Validate the max heap by moving up
        void percolate_up();
        // Remove max element from the heap
        void removeMax();
};

#endif // MAXHEAP_H
