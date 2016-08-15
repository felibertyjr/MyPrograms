#ifndef QUEUES_H
#define QUEUES_H
#include "clients.h"
using namespace std;

class queues : public clients
{
protected:
    struct cInfo//To store top of second stacks top queues
    {
        string client;
        string origin;
        string destination;
        int weight;
        cInfo *next;
    };

    cInfo *head;
    cInfo *tail;
    int numClients;//This will be used to tell my stack when to make a new level in stack of queues.


//vv------------------------Used for stack 1 LL and circular queues----------------------vv
    struct stackQueue//LL circular queues for the stack layers
    {
        string client;
        string origin;
        string destination;
        int weight;
        stackQueue *next;
    };

    struct queueTracker : stackQueue//Created to keep track of the unique heads/tails of each layer of queues in the stack. FUCK!
    {
        stackQueue *heads;
        stackQueue *tails;
        int numClient1;

        queueTracker(stackQueue *headIn = NULL, stackQueue *tailsIn = NULL, int numClient1In = 0)//I hope this shit works at as a constructor.
        {
            heads = headIn;
            tails = tailsIn;
            numClient1 = numClient1In;
        }

        queueTracker *nextTrackDown;
    };

    //queueTracker *first;//First node of this head/tails LL.
    queueTracker *lastQueue;//Most recent LL of head/tails.
//-------------------------------END----------------------------------------

//vv----------------This is for the second stack LL of LL circular queues.--------------vv
    struct stackQueue2//LL circular queues for the stack layers
    {
        string client;
        string origin;
        string destination;
        int weight;
        stackQueue2 *next;
    };

    struct queueTracker2 : stackQueue2//Created to keep track of the unique heads/tails of each layer of queues in the stack. FUCK!
    {
        stackQueue2 *heads;
        stackQueue2 *tails;
        int numClients2;

        queueTracker2(stackQueue2 *headIn = NULL, stackQueue2 *tailsIn = NULL, int numClients2In = 0)//I hope this shit works at as a constructor.
        {
            heads = headIn;
            tails = tailsIn;
            numClients2 = numClients2In;
        }

        queueTracker2 *nextTrackDown;
    };

    //queueTracker *first;//First node of this head/tails LL.
    queueTracker2 *lastQueue;//Most recent LL of head/tails.


public:
    //Function prototypes
    queues(){head = NULL; tail = NULL; numClients = 0; first = NULL; last = NULL;}; //Constructor
    ~queues();//Destructor
    void enqueue(string clientIn, string originIn, string destinationIn, int weightIn);
    void stackEnqueue(string clientIn, string originIn, string destinationIn, int weightIn);//Fill first stack with queues from newest on top to oldest on the bottom.
    void stackEnqueue2(string clientIn, string originIn, string destinationIn, int weightIn);//Fills second stack with queues from 1st stack to make it oldest on top and recent calls on the bottom.
    void dequeue();//I need to review this part
    void stackDequeue();
    void dequeueToStack(string &clientOut, string &originOut, string &destinationOut, int &weightOut);
    bool isEmpty() const;
    void wipeClean();

};


#endif // QUEUES_H
