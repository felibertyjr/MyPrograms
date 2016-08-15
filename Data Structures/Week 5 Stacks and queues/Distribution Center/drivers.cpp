#include "drivers.h"


void drivers::addDriver(string driverIn, string currentLocationIn, int radiusIn, string statusIn)
{
    if (head == NULL)
        head = new dInfo(driverIn, currentLocationIn, radiusIn, statusIn);
    else
    {
        dInfo *nextNode = head;

        while(nextNode->next != NULL)
            nextNode = nextNode->next;

        nextNode->next = new dInfo(driverIn, currentLocationIn, radiusIn, statusIn);
    }
}


void drivers::printDrivers()
{
    dInfo *nextNode = head;

    cout<<left;
    cout<<setw(15)<<"Name"<<setw(15)<<"Current Location"<<setw(15)<<"Driving Radius"<<setw(15)<<"Check-in Status"<<endl;
    while(nextNode)
    {
        cout<<setw(15)<<nextNode->driver<<setw(15)<<nextNode->currentLocation<<setw(15)<<nextNode->radius<<setw(15)<<nextNode->status<<endl;
        nextNode = nextNode->next;
    }
}


void drivers::noShowDrivers()
{
    dInfo *nextNode = head;

    while(nextNode)
    {
        if(nextNode->status == "No Show")
        {
            cout<<setw(15)<<nextNode->driver<<endl;
            nextNode = nextNode->next;
        }
    }
}

void drivers::validDriver(string searchDriver)
{
    dInfo *nextNode = head;

    while(nextNode && !exists)
    {
        if(nextNode->driver == searchDriver)
            exists = true;
        else
            nextNode = nextNode->next;
    }
}

drivers::~drivers()
{
    dInfo *nextNode = head;

    while(nextNode != NULL)
    {
        dInfo *garbage = nextNode;
        nextNode = nextNode->next;
        delete garbage;
    }
}
