#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
int x = 0, x2=0 , dice, dice2, pc, user;

cout<<"This is a dice game\n";

std::cout << std::endl << "Press any key to continue...";
    getchar();

do
{
dice = rand() % 6 + 1;
dice2 = rand() % 6 + 1;

if (x == 0)
    {
    cout<<"I will roll the dice first\n";
    cout<< dice<< endl;
    cout<<"Now your turn\n";
    cout << dice2<< endl;

    if (dice > dice2)
        {
        cout<<"HAHAHA! I win!"<< endl;
        pc=+ 1;
        std::cout << std::endl << "Press any key to continue...";
        getchar();
        }
    else if (dice2 > dice)
        {

        cout<<"DAMN! You win!"<< endl;
        user=+ 1;
        std::cout << std::endl << "Press any key to continue...";
        getchar();
        }
    else
        {
        cout<<"Its a tie"<< endl;
        pc=+ 1;
        user=+1;
        std::cout << std::endl << "Press any key to continue...";
        getchar();
        }
x++;
    }
else
{
    cout<<"I'll go again\n";
    cout<< dice<< endl;
    cout<<"Now your turn\n";
    cout << dice2<< endl;

    if (dice > dice2)
        {
        cout<<"HAHAHA! I win!"<< endl;
        pc=+ 1;
        std::cout << std::endl << "Press any key to continue...";
        getchar();
        }
    else if (dice2 > dice)
        {

        cout<<"DAMN! You win!"<< endl;
        user=+ 1;
        std::cout << std::endl << "Press any key to continue...";
        getchar();
        }
    else
        {
        cout<<"Its a tie"<< endl;
        pc=+ 1;
        user=+1;
        std::cout << std::endl << "Press any key to continue...";
        getchar();
        }
x++;
}



} while (x < 11);

if (pc > user)
    cout<<"I am the Grand Winner!!!!"<< endl;
else if(user > pc)
    cout<<"You must've cheated but you win!"<< endl;
else
    cout<<"Its a tie"<< endl;

return 0;
}
