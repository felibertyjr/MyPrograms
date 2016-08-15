#include "drivers.h"
#include "stacks.h"

using namespace std;

int main()
{

    stacks something;
    drivers driver;
    string *name = new string;
    string *origin = new string;
    string *destination = new string;
    string *location = new string;
    string *status = new string;
    int menuSelect, queueCount = 0;
    int *weight = new int;
    int *radius = new int;

    cout<<"Trucking Distribution Center software.\n";
    cout<<"\n\n\n\n\n";

    cout<<"Did a client or driver call in?\nEnter 1) CLIENT\nEnter 2) DRIVER\n";
    cin>>menuSelect;//I could switch this to use an ID number

    if(menuSelect < 1 || menuSelect > 2 || cin.fail())
    {
        do
        {
            cin.clear();
            cin.ignore();
            cout<<"** INVALID **\n";
            cout<<"Did a client or driver call in?\nEnter 1) CLIENT\nEnter 2) DRIVER\n";
            cin>>menuSelect;
        }while(menuSelect < 1 || menuSelect > 2 || cin.fail());
    }

    if(menuSelect == 1)
    {
        cout<<"Enter the clients name: ";
        cin>>*name;

        if(cin.fail())
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout<<"** INVALID **\n";
                cout<<"Enter the clients name: ";
                cin>>*name;
            }while(cin.fail());
        }

        cout<<"Enter origin of the goods being shipped: ";
        cin>>*origin;


        if(cin.fail())
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout<<"** INVALID **\n";
                cout<<"Enter origin of the goods being shipped: ";
                cin>>*origin;
            }while(cin.fail());
        }

        cout<<"Enter the destination of the goods: ";
        cin>>*destination;


        if(cin.fail())
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout<<"** INVALID **\n";
                cout<<"Enter the destination of the goods: ";
                cin>>*destination;
            }while(cin.fail());
        }


        cout<<"Enter the weight of the goods: ";
        cin>>*weight;

        if(cin.fail()|| *weight < 1 )
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout<<"** INVALID **\n";
                cout<<"Enter the weight of the goods: ";
                cin>>*weight;
            }while(cin.fail() || *weight < 1 );
        }


        something.push(*name, *origin, *destination, *weight);
        queueCount++;

    }
    else
    {
        cout<<"Enter the drivers name: ";
        cin>>*name;

        if(cin.fail())
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout<<"** INVALID **\n";
                cout<<"Enter the drivers name: ";
                cin>>*name;
            }while(cin.fail());
        }

        cout<<"Enter the current location of the driver: ";
        cin>>*location;


        if(cin.fail())
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout<<"** INVALID **\n";
                cout<<"Enter the current location of the driver: ";
                cin>>*location;
            }while(cin.fail());
        }


        cout<<"How many miles is the driver willing to travel: ";
        cin>>*radius;


        if(cin.fail())
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout<<"** INVALID **\n";
                cout<<"How many miles is the driver willing to travel: ";
                cin>>*radius;
            }while(cin.fail());
        }

        driver.addDriver(*name, *location, *radius, "Yes");



     //   while(queueCount != 0)
        //{
          //  something.pop();
          //  something.push();
          //  queueCount--;
        //}
        something.stackSwap();
        something.pop();
        something.dequeue();
        something.showClient();
    }


    if(queueCount % 5 == 0)
    {
        something.createNewLayer == true;
    }

    return 0;
}
