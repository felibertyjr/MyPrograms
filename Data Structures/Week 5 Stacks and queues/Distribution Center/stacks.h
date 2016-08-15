#ifndef STACKS_H
#define STACKS_H
#include "queues.h"

class stacks : public queues
{
private:
    struct stackNode1
    {
        stackNode1 *nextDown;
    };

    stackNode1 *top;

    struct stackNode2
    {
        stackNode2 *nextDown;
    };

    stackNode2 *tops;

public:
    bool createNewLayer;
    int numLayers;
    stacks(){top = NULL;createNewLayer = false;numLayers = 0;};
    ~stacks();

    void push(string clientIn, string originIn, string destinationIn, int weightIn);
    void pop();
    void stackSwap();
    bool isEmpty() const;

};



#endif // STACKS_H
