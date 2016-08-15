#ifndef CLIENTS_H
#define CLIENTS_H

#include <iostream>
#include <iomanip>
using namespace std;


class clients
{
protected:
    struct client1
    {
        string client;
        string origin;
        string destination;
        int weight;
        client1(string clientIn, string originIn, string destinationIn, int weightIn)
        {
            client = clientIn;
            origin = originIn;
            destination = destinationIn;
            weight = weightIn;
        };
    };

    client1 *cust;

public:
    clients(){cust = NULL;};
    ~clients();//Deletes clients info
    void newClient(string clientIn, string originIn, string destinationIn, int weightIn);//Prints client info to cout.
    void showClient();
};





#endif // CLIENTS_H
