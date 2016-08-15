#include "election.h"
using namespace std;

void election::addCandidate(string nameIn, int votesIn)
{
    if (head == NULL)
        head = new candidates(nameIn, votesIn);
    else
    {
        candidates *nextNode = head;

        while(nextNode->next != NULL)
            nextNode = nextNode->next;

        nextNode->next = new candidates(nameIn, votesIn);
    }
}


void election::printElectionResults()
{
    float sum = 0;
    candidates *nextNode = head;

    while(nextNode)
    {
        sum = sum + nextNode->votes;
        nextNode = nextNode->next;
    }


    nextNode = head;

    cout<<left;
    cout<<setw(15)<<"Name"<<setw(15)<<"Votes"<<setw(15)<<"Percentage"<<endl;

    while(nextNode)
    {
        nextNode->percent = (nextNode->votes/ sum) * 100;
        cout<<setw(15)<<nextNode->name<<setw(15)<<nextNode->votes<<setw(15)<<fixed<<setprecision(2)<<nextNode->percent<<endl;

        nextNode = nextNode->next;
    }
}

void election::printWinner()
{
    int winnerVotes = 0;
    string winner;

    candidates *nextNode = head;

    while(nextNode)
    {
        if(nextNode->votes > winnerVotes)
        {
            winnerVotes = nextNode->votes;
            winner = nextNode->name;
        }

        nextNode = nextNode->next;
    }
    cout<<winner<<" is the winner!\n";
}

election::~election()
{
    candidates *nextNode = head;

    while(nextNode != NULL)
    {
        candidates *garbage = nextNode;
        nextNode = nextNode->next;
        delete garbage;
    }

    //cout<<"Thank you for using the program\n";
}

