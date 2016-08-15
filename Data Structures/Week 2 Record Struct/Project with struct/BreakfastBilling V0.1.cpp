#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>//for output formatting

using namespace std;

//----  6/3/16  ----
//This is a program that automates a restaurants breakfast billing.
//Bonus: Update it to take in a file for the menu and out put receipt in txt file
//Add fixed and setprecision to 2 to get the zeros
//****************************************************************************
const int NumOfItems = 8;//Update this to tell how many items are on the menu*
//****************************************************************************

//******************************************************************
void getData(), printCheck();void showMenu();//Function Declaration*
//******************************************************************


//*****************************************
//*********Global Record Struct************
struct menuItemType{                    //*
        string item;                    //*
        int option;                     //*
        float price;                    //*
    } menuList[NumOfItems];             //*
//*****************************************

//********************************************************************************************************************************
//****************************************----    **My functions**    ----********************************************************
void getData(menuItemType menuList[]){
    int counter = 0;
    string menu[NumOfItems]={"Plain Egg", "Bacon and Egg","Muffin","French Toast","Fruit Basket","Cereal","Coffee","Tea"};
    float prices[NumOfItems] = {1.45,2.45,0.99,1.99,2.49,0.69,00.50,0.75};
    do{
            menuList[counter].option = (counter + 1);
            menuList[counter].item = menu[counter];
            menuList[counter].price = prices[counter];
            counter += 1;
    }while(counter < NumOfItems);
}

void showMenu(menuItemType menuList[]){
    int counter = 0;

    do{
        cout<<left;
        cout<<fixed;
        cout<<setprecision(2);
        cout<<"Enter "<<menuList[counter].option<<") "<<setw(25)<<menuList[counter].item<<setw(5)<<menuList[counter].price<<endl;
        counter += 1;
    } while (counter < NumOfItems);
}

void printCheck(float *sumPointer, string *itemPointer, float *pricePointer, int counter){
    int c;

    cout<<"Receipt for your order:\n";
    cout<<endl;
    for (c = 0; c < counter; c++)
        cout<<left<<setw(25)<<itemPointer[c]<<setw(8)<<pricePointer[c]<<endl;

    cout<<endl;
    cout<<fixed;
    cout<<setprecision(2);
    cout<<left<<setw(25)<<"Tax"<<setw(8)<<(*sumPointer) * .05<<endl;
    cout<<left<<setw(25)<<"Amount Due"<<setw(8)<<*sumPointer + ((*sumPointer) * .05)<<endl;
    cout<<setw(33)<<setfill('-')<<"";
}
//**************************************----    End of functions    ----**************************************************************
//************************************************************************************************************************************

int main()
{
    getData(menuList);

    int choice,tracker = 0, num, i,a;
    string exists[4] = {"Yummy!!", "That's my Favorite!", "Good choice!", "Great!"};//Messages that can be printed out
    float sum= 0;//sum of what was ordered
    bool loop = true, test;//for menu loop


    srand (time(NULL));//Seed for Rand


    //*********************************************************************
    //****----    This is to get my array length for items ordered    ----*
    showMenu(menuList);
    cout<<"How many items will you be purchasing today?\n";
    cin>>num;
        if (cin.fail() || num <= 0){

            do{
                cin.clear();
                cin.ignore();
                cout<<"**That is not a valid order amount**"<<endl;
                cout<<"How many items will you be purchasing today?\n";
                cin>>num;
            } while(cin.fail() || num <= 0);
        }
    //---------------------------------------------------------------------

    string itemsOrdered[num];//This is to record the ordered items
    float itemsOrderedPrice[num];//Records items prices

    //****************************************************************************************************************
    //******************************----    This section is for the menu loop    ----*********************************
    do{
        showMenu(menuList);
        cout<<"Please enter what you would like to order: "<<endl;
        cout<<"----    If you wish to exit ENTER 0    ----\n";
        cin>>choice;

        if(choice > 0 && choice <= NumOfItems){
            itemsOrdered[tracker] = menuList[choice - 1].item;//Store order item in array
            itemsOrderedPrice[tracker] = menuList[choice - 1].price;//Store item price in array
            sum = sum + itemsOrderedPrice[tracker]; //Sum
            tracker += 1;
            //-------------
            a = rand() % 4;
            cout<<exists[a]<<endl; //Prints out a compliment
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }
        else if(choice <= 0 || choice > NumOfItems|| cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"**Please Make a valid menu selection**\n";//Error message if they don't make a valid choice.
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
        }
        else
            return 0;//If the client chooses to exit or cancel their order

    }while(tracker < num); //do-while to get the whole order
    //********************************----     End of Menu Loop    ----************************************************
    //*****************************************************************************************************************


printCheck(&sum, itemsOrdered, itemsOrderedPrice, num); //Prints out the order that the customer placed

return 0;
}
