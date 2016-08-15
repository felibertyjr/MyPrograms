#include <iostream>
using namespace std;

float privateRoom(int), semiprivateRoom(int), wardRoom(int), phone(int),  tele(int),  phone(int);

float privateRoom(int days)
{
    float cost;

    cost = days * 125.00;

    return cost;

}

float semiprivateRoom(int days)
{
    float cost;

    cost = days * 95.00;

    return cost;

}

float wardRoom(int days)
{
    float cost;

    cost = days * 75.00;

    return cost;

}

float phone(int days)
{
    float addCost;

    addCost = days * 1.75;

    return addCost;
}

float tele(int days)
{
    float addCost;

    addCost = days * 3.50;

    return addCost;
}


int main()
{

int roomType = 0, days = 0 , ammen = 0, choice = 0;
float teleTotal = 0.0, phoneTotal = 0.0, roomTotal = 0.0;
string room;

do
{
    cout<<"How many days will you be staying for?\n";
    cin>>days;


    if(days < 1)
    {
        do{
        cout<<"Please enter a valid number of days!\n";
        cout<<"How many days will you be staying for?\n";
        cin>>days;
        } while (days<1);
    }

    cout<<"What type of room would you like?\n";
    cout<<"Enter 1) Private Room\n";
    cout<<"Enter 2) SemiPrivate Room\n";
    cout<<"Enter 3) Ward\n";
    cin>>roomType;


    if (roomType < 1 || roomType > 3)
    {

        do
        {
                cout<<"Please make a valid choice!\n";
                cout<<"What type of room would you like?\n";
                cout<<"Choose 1 for Private Room\n";
                cout<<"Choose 2 for SemiPrivate Room\n";
                cout<<"Choose 3 for Ward\n";
                cin>>roomType;
        }while (roomType < 1 || roomType > 3);
    }


           if (roomType == 1)
                {
                    roomTotal = privateRoom(days);
                    room = "Private";
                }

            else if (roomType == 2)
                {
                    roomTotal = semiprivateRoom(days);
                    room = "Semi-Private";
                }

            else
                {
                    roomTotal = wardRoom(days);
                    room = "Ward";
                }


    cout<<"Would you like a TV and/or phone?\n";
    cout<<"Choose 1 for a TV\n";
    cout<<"Choose 2 for a phone\n";
    cout<<"Choose 3 for both\n";
    cout<<"Choose 4 for none\n";
    cin>>ammen;

    if(ammen < 1 || ammen > 4)
        do
        {
                cout<<"Please make a valid choice!\n";
                cout<<"Would you like a TV and/or phone?\n";
                cout<<"Choose 1 for a TV\n";
                cout<<"Choose 2 for a phone\n";
                cout<<"Choose 3 for both\n";
                cout<<"Choose 4 for none\n";
                cin>>ammen;
        }while (ammen < 1 || ammen > 4);



        if (ammen == 1)
            teleTotal = tele(days);
        else if (ammen == 2)
            phoneTotal = phone(days);
        else
            phoneTotal = phone(days);
            teleTotal = tele(days);


        cout<<"Number of days in the hospital: "<<days<<endl;

        cout<<"Type of Room: "<<room<<endl;

        cout<<"Telephone Charge: "<<phoneTotal<<endl;

        cout<<"TV charge: "<<teleTotal<<endl;

        cout<<"Total Due: "<< phoneTotal + teleTotal + roomTotal<<endl;

        teleTotal = 0.0;
        phoneTotal = 0.0;
        roomTotal = 0.0;
        roomType = 0;
        days = 0;
        ammen = 0;
        choice = 0;


    cout<<"Would you like to continue using this program?\n";
    cout<<"Enter 1) YES\n";
    cout<<"Enter 2) NO\n";
    cin>>choice;

    if (choice < 1 || choice > 2)
        do{

                    cout<<"Please enter a valid choice\n";
                    cout<<"Would you like to continue using this program?\n";
                    cout<<"Enter 1) YES\n";
                    cout<<"Enter 2) NO\n";
                    cin>>choice;

        }while (choice < 1 || choice > 2);

}while(choice != 2);

return 0;

}
