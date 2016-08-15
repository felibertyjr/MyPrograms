#include "clients.h"


void clients::newClient(string clientIn, string originIn, string destinationIn, int weightIn)
{
    cust = new client1(clientIn, originIn, destinationIn, weightIn);
}

void clients::showClient()
{
    cout<<left;
    cout<<setw(15)<<"Name"<<setw(15)<<"Origin"<<setw(15)<<"Destination"<<setw(15)<<"Weight of goods"<<endl;
    cout<<setw(15)<<cust->client<<setw(15)<<cust->origin<<setw(15)<<cust->destination<<setw(15)<<cust->weight<<endl;
}

clients::~clients()
{
    delete cust;
}
