#ifndef ELECTION_H
#define ELECTION_H
#include <iostream>
#include <iomanip>
using namespace std;

class election
{
protected:
    struct candidates{
        string name;
        int votes;
        float percent;
        candidates *next;

        //THIS IS A CONSTRUCTOR FOR THE STRUCT TO INITILIZE THE VALUES IN IT
        candidates(string nameIn = "blank", int votesIn = 0, candidates *nextIn = NULL)
        {
            name = nameIn;
            votes = votesIn;
            next = nextIn;
        }
    };

    candidates *head;


public:
         election(){head = NULL;};//CONSTRUCTOR
         ~election();//DESTRUCTOR
    void addCandidate(string nameIn, int votesIn);//ADDS INFORMATION TO THE LINK LIST AND CREATES THE LINK LIST
    void printElectionResults();//PRINT OUT THE LINK LIST
    void printWinner();//FINDS THE WINNER BY VOTE COUNT AND COUT THE RESULTS
};

#endif // ELECTION_H
