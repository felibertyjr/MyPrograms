#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>//for output formatting

using namespace std;

//----  6/3/16  ----
//This is a program that automates a restaurants breakfast billing.

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
    //Try using VOID data type for the getData function.
    int counter = 0;
    //Also take out "thing" and leave the parameter empty.
    //Think about using IFSTREAM to get a menu from a users document.
    string menu[NumOfItems]={"Plain Egg", "Bacon and Egg","Muffin","French Toast","Fruit Basket","Cereal","Coffee","Tea"};
    float prices[NumOfItems] = {1.45,2.45,0.99,1.99,2.49,0.69,00.50,0.75};
    do{
            menuList[counter].option = (counter + 1);
            menuList[counter].item = menu[counter];
            menuList[counter].price = prices[counter];
            //cout<<menuList[counter].option<<menuList[counter].item<<menuList[counter].price<<endl ;
            counter += 1;
    }while(counter < NumOfItems);
}

void showMenu(menuItemType menuList[]){
    //Think about excluding the parameter
    int counter = 0;

    do{
        cout<<left;
        cout<<"Enter "<<menuList[counter].option<<") "<<setw(25)<<menuList[counter].item<<setw(5)<<menuList[counter].price<<endl;
        counter += 1;
    } while (counter < NumOfItems);
}

void printCheck(float *sumPointer, string *itemPointer, float *pricePointer, int counter){
    //Use a void data type for this cuz you could just use couts in here::CHECK
    //You need to sum everything up and include the tax at the end.
    //BONUS: Use out file to give a receipt.
    int c;

    for (c = 0; c < counter; c++)
        cout<<left<<setw(25)<<itemPointer[c]<<setw(8)<<pricePointer[c]<<endl;

    cout<<setprecision(2);
    cout<<(*sumPointer) * .05<<endl;
    cout<<*sumPointer<<endl;
}
//**************************************----    End of function    ----***************************************************************
//************************************************************************************************************************************

int main()
{
    //VV----    Update this shit to take in a file for the menu!!!    ----VV
    menuItemType *point[NumOfItems] = &menuList[NumOfItems]; //check out page 825 in CPP text
    getData(point);

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
        if (num < 0){
            do{
                cout<<"**That is not a valid order amount**"<<endl;
                cout<<"How many items will you be purchasing today?\n";
                cin>>num;
            } while(num < 0);
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
        }
        else if(choice < 0 || choice > NumOfItems)
            cout<<"**Please Make a valid menu selection**\n";//Error message if they don't make a valid choice.
        else
            return 0;//If the client chooses to exit or cancel their order

    }while(tracker < num); //do-while to get the whole order
    //********************************----     End of Menu Loop    ----************************************************
    //*****************************************************************************************************************


printCheck(&sum, itemsOrdered, itemsOrderedPrice, num); //Prints out the order that the customer placed

return 0;
}
