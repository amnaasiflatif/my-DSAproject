#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node* element[26];
        bool flag;
        // Constructor
        Node();
        // Destructor
        virtual ~Node();
        // Check if the node exists
        bool ifExist(char ch);
        // To insert the element in a node
        void put(char ch, Node* node);
        // Mark end of the word
        void putEnd();
        // Check if the word is end
        bool isEnd();
        // To obtain the next node
        Node* next(char ch);
        // To remove the indication of end of the word
        void set_false();

    protected:

    private:
};

#endif // NODE_H
