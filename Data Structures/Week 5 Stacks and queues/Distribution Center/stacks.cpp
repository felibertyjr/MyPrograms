#include "stacks.h"


void stacks::push(string clientIn, string originIn, string destinationIn, int weightIn)
{
    stackNode1 *newNode = NULL; // Node for a layer in the stack.
    newNode = new stackNode1;//Creates a space in memory for that node.


    queues information;
    information.stackEnqueue(clientIn,originIn,destinationIn,weightIn);

    queueTracker *nextNode = NULL;
    nextNode = new queueTracker;
    if(createNewLayer == true)
    {
        if(isEmpty())
        {
            top = newNode;//for the stack
            newNode->nextDown = NULL;//for the stack


            lastQueue = nextNode;//This is to update the position of my queue tracker
            nextNode->nextTrackDown = NULL;//This is to update the position of my queue tracker
            createNewLayer = false;//Reset condition


        }
        else
        {
            newNode->nextDown = top;
            top = newNode;

            nextNode->nextTrackDown = lastQueue;
            lastQueue = nextNode;
            createNewLayer = false;
        }
    }
}

void stacks::pop()
{
    int a = 0;
    cInfo *transfer = NULL;


    transfer = lastQueue->heads;//Copies the data available to this pointer variable

    if(isEmpty())
        cout<<"The stack is empty.\n";
    else
    {

        while()        {
            enqueue(->client, ->origin, ->destination, ->weight);


            transfer->next =
            newNode =

            transfer =
        }

        queueTracker *update = first;

        while(a < numLayers)//This is to get to the correct layer of the stack to get the correct head and tail of circular queue.
        {
            last = update->nextTrack;
            update = update->nextTrack;
            a++;
        }


        //For deleting the top node from the stack to make the next one available to pop
        temp = top->next;
        delete top;
        top = temp;
    }
}

void stacks::stackSwap()
{
    stackNode2 *newNode = NULL; // Node for a layer in the stack.
    newNode = new stackNode2;//Creates a space in memory for that node.
    string client,origin,destination;
    int weight;

//insert function dequeue to stack. get pointer variables to fill up the information

    queues information;
    information.dequeueToStack(client,origin,destination,weight);//to remove contents of original stack into variables in this function.

    information.stackEnqueue2(*client,*origin,*destination,*weight);//Takes what was removed and places it in the second stack.



    queueTracker *nextNode = NULL;
    nextNode = new queueTracker;
    if(information.isEmpty())
    {
        if(isEmpty())
        {
            top = newNode;//for the stack
            newNode->nextDown = NULL;//for the stack


            lastQueue = nextNode;//This is to update the position of my queue tracker
            nextNode->nextTrackDown = NULL;//This is to update the position of my queue tracker
            createNewLayer = false;//Reset condition


        }
        else
        {
            newNode->nextDown = top;
            top = newNode;

            nextNode->nextTrackDown = lastQueue;
            lastQueue = nextNode;
            createNewLayer = false;
        }
    }
}

bool stacks::isEmpty() const;
{
    bool status;

    if(!top)
        status = true;
    else
        status = false;

    return status;
}

stacks::~stacks()
{
    stackNode1 *nodePtr, *nextNode = NULL;
    stackNode2 *nodePtr2, *nextNode2 = NULL;

    nodePtr = top;
    nodePtr2 = top;

    while(nodePtr1 != NULL && nodePtr2 != NULL)
    {
        nextNode = nodePtr->next;
        nextNode2 = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
        nodePtr2 = nextNode2;
    }
}
