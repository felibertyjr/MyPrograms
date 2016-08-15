#include "queues.h"



void queues::enqueue(string clientIn, string originIn, string destinationIn, int weightIn)
{
    cInfo *newNode = NULL;

    newNode = new cInfo;

    newNode->client = clientIn;
    newNode->origin = originIn;
    newNode->destination = destinationIn;
    newNode->weight = weightIn;
    newNode->next = head;//This is the part that makes it circular cuz instead of pointing to NULL its the first node.

    if(isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    numClients++;
}

void queues::stackEnqueue(string clientIn, string originIn, string destinationIn, int weightIn)//Makes the first stack of queues.
{
    //stackQueue *newNode = NULL;
    queueTracker *newTrackerNode = NULL;

    //newNode = new stackQueue;
    newTrackerNode = new queueTracker;


    if(isEmpty())
    {
        newTrackerNode->heads = newTrackerNode;
        newTrackerNode->tails = newTrackerNode;
    }
    else
    {
        newTrackerNode->tails->next = newTrackerNode;
        newTrackerNode->tails = newTrackerNode;
    }

    //This section copies the contents to a circular LL queue
    newTrackerNode->client = clientIn;
    newTrackerNode->origin = originIn;
    newTrackerNode->destination = destinationIn;
    newTrackerNode->weight = weightIn;
    newTrackerNode->next = newTrackerNode->heads;//This is the part that makes it circular cuz instead of pointing to NULL its the first node.


    newTrackerNode->numClient1++;

}

void queues::stackEnqueue2(string clientIn, string originIn, string destinationIn, int weightIn)//This is to make a second stack of queues.
{
    queueTracker2 *newTrackerNode = NULL;

    newTrackerNode = new queueTracker2;


    if(isEmpty())
    {
        newTrackerNode->heads = newTrackerNode;
        newTrackerNode->tails = newTrackerNode;
    }
    else
    {
        newTrackerNode->tails->next = newTrackerNode;
        newTrackerNode->tails = newTrackerNode;
    }

    //This section copies the contents to a circular LL queue
    newTrackerNode->client = clientIn;
    newTrackerNode->origin = originIn;
    newTrackerNode->destination = destinationIn;
    newTrackerNode->weight = weightIn;
    newTrackerNode->next = newTrackerNode->heads;//This is the part that makes it circular cuz instead of pointing to NULL its the first node.

    newTrackerNode->numClients2++;

}

void queues::dequeue()//I need to review this part
{
    cInfo *temp = NULL;

    if(isEmpty())
    {
        cout<<"The queue is empty.\n";
    }
    else
    {
        clients eject;
        eject.newClient(head->client, head->origin, head->destination,head->weight);

        temp = head;
        head = head->next;
        delete temp;

        numClients--;
    }
}

void queues::dequeueToStack(string &clientOut, string &originOut, string &destinationOut, int &weightOut)//I need to review this part
{
    queueTracker *temp = NULL;



    if(isEmpty())
    {
        cout<<"The queue is empty.\n";
    }
    else
    {

        clientOut = lastQueue->heads->client;
        originOut = lastQueue->heads->origin;
        destinationOut = lastQueue->heads->destination;
        weightOut = lastQueue->heads->weight;

        temp = lastQueue->heads;
        lastQueue->heads = lastQueue->heads->next;
        delete temp;

        numClients--;
    }
}

void queues::stackDequeue()//I need to review this part
{
    cInfo *temp = NULL;


    if(isEmpty())
    {
        cout<<"The queue is empty.\n";
    }
    else
    {
        clients test;
        test.newClient(head->client, head->origin, head->destination,head->weight);

        temp = head;
        head = head->next;
        delete temp;

        numClients--;
    }
}

bool queues::isEmpty() const
{
    bool status;

    if (numClients > 0)
        status = false;
    else if (queueTracker.numClient1 > 0)
        status = false;
    else if(queueTracker2.numClients2 > 0)
        status = false;
    else
        status = true;
    return status;
}

void queues::wipeClean()
{
    while(!isEmpty())
        dequeue();
}

queues::~queues()
{
    wipeClean();
}
