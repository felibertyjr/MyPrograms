#include <iostream>
using namespace std;

float mealKids(float), mealAdTotal (int , float ), mealKidsTotalFun (int , float ), dessertTotal(int , float ), foodBill (float ,float ,float ),tipFin(float, int),taxFin(float, int),tipTaxTotal(float, float),totalFin(float, float, float, float, float);

float mealKids(float mealAdults)
{
    float cost;

    cost = mealAdults * 0.6;
    return cost;
}

float mealAdTotal (int numAdults, float mealAdults)
{
    float cost;

    cost = numAdults * mealAdults;
    return cost;
}

float mealKidsTotalFun (int numKids, float mealKidsCost)
{
    float cost;

    cost = numKids * mealKidsCost;
    return cost;
}

float dessertTotal(int dessertQ, float dessertCostPer)
{
    float cost;

    cost = dessertQ * dessertCostPer;
    return cost;
}

float foodBill (float mealAdTotal,float mealKidsTotal,float dessertTotalCost)
{
    float cost;

    cost = mealAdTotal + mealKidsTotal + dessertTotalCost;
    return cost;
}

float tipFin(float preTaxTotal, int tipIn)
{
    float cost, tipCalc;

    tipCalc = tipIn/100.0;
    cost = tipCalc * preTaxTotal;
    return cost;
}

float taxFin(float preTaxTotal, int taxIn)
{
    float cost, taxCalc;

    taxCalc = taxIn/100.0;
    cost = taxCalc * preTaxTotal;
    return cost;
}


float totalFin(float preTaxTotal, float fee, float deposit, float tipTotal, float taxTotal)
{
    float total;

    total = (preTaxTotal + fee + tipTotal + taxTotal) - deposit;
    return total;
}



int main()
{
int numAdults = 0, numKids = 0, tipIn = 0, taxIn = 0;
float mealAdults = 0.0, mealKidsCost, dessertCostPer = 0.0, dessertQ = 0.0, fee = 0.0, deposit = 0.0, mealAdultsTotal, mealKidsTotal, dessertTotalCost, preTaxTotal = 0, tipTotal, taxTotal, GrandTotal;

//Questions to fetch info
do
{
    if(numAdults < 0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"How many adults will be Eating today?"<<endl;
        cin>>numAdults;
    }
    else
    {
        cout<<"How many adults will be Eating today?"<<endl;
        cin>>numAdults;
    }

}while(numAdults < 0);

do
{
    if (numKids < 0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"Will they're be any children at your party? If so, how many?"<<endl;
        cin>>numKids;
    }
    else
    {
        cout<<"Will they're be any children at your party? If so, how many?"<<endl;
        cin>>numKids;
    }
} while(numKids < 0);

do
{
    if (mealAdults < 0.0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"Whats the cost per Adult meal? **DO NOT include Dessert**"<<endl;
        cin>>mealAdults;
    }
    else
    {
        cout<<"Whats the cost per Adult meal? **DO NOT include Dessert**"<<endl;
        cin>>mealAdults;
    }
} while(mealAdults < 0.0);

do
{
    if (dessertCostPer < 0.0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"Whats the cost per Dessert?"<<endl;
        cin>>dessertCostPer;
    }
    else
    {
        cout<<"Whats the cost per Dessert?"<<endl;
        cin>>dessertCostPer;
    }
} while(dessertCostPer < 0.0);

do
{
    if (dessertQ < 0.0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"How many Desserts were ordered?"<<endl;
        cin>>dessertQ;
    }
    else
    {
        cout<<"How many Desserts were ordered?"<<endl;
        cin>>dessertQ;
    }
} while(dessertQ < 0.0);


do
{
    if (fee < 0.0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"Whats the room fee?"<<endl;
        cin>>fee;
    }
    else
    {
        cout<<"Whats the room fee?"<<endl;
        cin>>fee;
    }
} while(fee < 0.0);

do
{
    if (tipIn < 0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"Whats the tip rate? (Provide it in a whole number: eg, Input 10 for 10 percent)"<<endl;
        cin>>tipIn;
    }
    else
    {
        cout<<"Whats the tip rate? (Provide it in a whole number: eg, Input 10 for 10 percent)"<<endl;
        cin>>tipIn;
    }
} while(tipIn < 0);

do
{
    if (taxIn < 0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"Whats the tax rate? (Provide it in a whole number: eg, Input 10 for 10 percent)"<<endl;
        cin>>taxIn;
    }
    else
    {
        cout<<"Whats the tax rate? (Provide it in a whole number: eg, Input 10 for 10 percent)"<<endl;
        cin>>taxIn;
    }
} while(taxIn < 0);

do
{
    if (deposit < 0.0)
    {
        cout<<"Please enter a valid quantity!"<<endl;
        cout<<"Whats the required deposit amount?"<<endl;
        cin>>deposit;
    }
    else
    {
        cout<<"Whats the required deposit amount?"<<endl;
        cin>>deposit;
    }
} while(deposit < 0.0);


cout<<"Thank you! Please wait while I process your Customers Bill ...."<<endl;

//Done with questions

//Lets start showing the fruits of our labor!

    cout<<"Casewell Catering and Convention Service"<<endl;

    cout<<"-----Final Bill------"<<endl;

    cout<<"-----------------------------------------"<<endl;

    cout<<"Number of Adults:"<<numAdults<<endl;

    cout<<"Number of Children:"<<numKids<<endl;

    cout<<"Cost per Adult without dessert:"<<mealAdults<<endl;

    mealKidsCost = mealKids(mealAdults);
    cout<<"Cost per Child without dessert:"<<mealKidsCost<<endl;

    cout<<"Cost per dessert:"<<dessertCostPer<<endl;

    cout<<"Room fee:"<<fee<<endl;

    cout<<"Plus Tip and Tax rate:"<<tipIn<< "% " <<taxIn<<"%"<<endl;

    cout<<" "<<endl;

    cout<<"-----------------------------------------"<<endl;

    //time to use our functions


    mealAdultsTotal = mealAdTotal(numAdults,  mealAdults);
    cout<<"Total cost for Adult meals:"<<mealAdultsTotal<<endl;

    mealKidsTotal = mealKidsTotalFun (numKids, mealKidsCost);
    cout<<"Total cost for Kids meals:"<<mealKidsTotal<<endl;

    dessertTotalCost = dessertTotal(dessertQ, dessertCostPer);
    cout<<"Total cost for Desserts:"<<dessertTotalCost<<endl;

    preTaxTotal = foodBill (mealAdultsTotal,mealKidsTotal, dessertTotalCost);
    cout<<"Total food cost:"<<preTaxTotal<<endl;

    taxTotal = taxFin(preTaxTotal, taxIn);
    tipTotal = tipFin(preTaxTotal, tipIn);
    cout<<"Plus tips and tax:"<<tipTotal<< taxTotal<<endl;

    cout<<"Plus room fee:"<<fee<<endl;

    cout<<"Less the deposit:"<<deposit<<endl;

    cout<<" "<<endl;

    GrandTotal = totalFin(preTaxTotal, fee, deposit, tipTotal, taxTotal);
    cout<<"Balance Due:"<<GrandTotal<<endl;



return 0;
}
