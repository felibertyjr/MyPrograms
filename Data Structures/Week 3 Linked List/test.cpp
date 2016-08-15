#include <iostream>
#include <iomanip>
using namespace std;



    struct candidates{
    string name;
    int votes;
    float percent;
    }temp;

void sorter();

void sorter(candidates info[],candidates& temp,int& num){
    int a,b,c,d;
    float sum = 0;

    for (b = 0; b < num; b++)
        sum = sum + info[b].votes;

    for(c = 1; c < num;c++){
        for(d=num-1; d>=c; d--){
            if(info[d-1].votes > info[d].votes){
                temp = info[d - 1];
                info[d - 1]= info[d];
                info[d] = temp;
            }
        }
    }

    cout<<left;
    cout<<setw(15)<<"Name"<<setw(15)<<"Votes"<<setw(15)<<"Percentage"<<endl;
    for(a = 0; a < num; a++){
        info[a].percent = ((info[a].votes) / sum) * 100;
        cout<<left;
        cout<<setw(15)<<info[a].name<<setw(15)<<info[a].votes<<setw(15)<<fixed<<setprecision(2)<<info[a].percent<<endl;
    }

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<info[num - 1].name<<" is the winner!\n";
}

int main(){
    int a, first, last, mid, change, choice, c, num, counter;
    bool found = false;
    string searchItem;



    cout<<"How many candidates do we have this election?\n";
    cin>>num;

    if(num <= 0 || cin.fail()){
        do{
            cin.clear();
            cin.ignore();
            cout<<"** Invalid **\n";
            cout<<"How many candidates do we have this election?\n";
            cin>>num;
        }while(num <= 0 || cin.fail());
    }

    candidates info[num];

    for(a = 0; a < num; a++){
        cout<<"Enter candidate "<<a+1<<"'s name\n";
        cin>>info[a].name;
            if(cin.fail()){
                do{
                    cin.clear();
                    cin.ignore();
                    cout<<"** Invalid **\n";
                    cout<<"Enter candidate"<<a+1<<"'s name\n";
                    cin>>info[a].name;
                }while(cin.fail());
            }
    }

    for(c = 0; c < num; c++){
        cout<<"How many votes did "<<info[c].name<<" receive?\n";
        cin>>info[c].votes;
            if(cin.fail()){
                do{
                    cin.clear();
                    cin.ignore();
                    cout<<"** Invalid **\n";
                    cout<<"How many votes did "<<info[c].name<<" receive?\n";
                    cin>>info[c].votes;
                }while(cin.fail());
            }
    }

    do{
        cout<<"Do you have to update any of the votes?\n";
        cout<<"Enter 1) YES \nEnter 2) NO\n";
        cin>>change;
            if(change < 1 || change > 2 || cin.fail()){
                do{
                    cin.clear();
                    cin.ignore();
                    cout<<"** Invalid **\n";
                    cout<<"Do you have to update any of the votes?\n";
                    cout<<"Enter 1) YES \n Enter 2) NO\n";
                    cin>>change;
                } while(change < 1 || change > 2 || cin.fail());
            }

        first = 0;
        last = num - 1;
        bool validate = true;

        if(change == 1){
            cout<<"What candidate would you like to change?\n";
            cin>>searchItem;
            for(counter = 0; counter < num; counter++){
                if(cin.fail() || searchItem != info[counter].name)
                    validate = false;
                else{
                    validate = true;
                    counter = num;
                }
            }

                if(validate == false){
                    do{
                        cin.clear();
                        cin.ignore();
                        cout<<"** Invalid **\n";
                        cout<<"What candidate would you like to change?\n";
                        cin>>searchItem;
                        for(counter = 0; counter < num; counter++){
                            if(cin.fail()||searchItem != info[counter].name)
                                validate = false;
                            else{
                                validate = true;
                                counter = num;
                            }
                        }
                    }while(validate == false);
                }

            do{
                while(first <= last && !found){
                    mid = (first + last) /2;
                    if(info[mid].name == searchItem){
                        found = true;
                        cout<<"What is the updated vote count?\n";
                        cin>>info[mid].votes;

                        if(info[mid].votes <= 0 || cin.fail()){
                            do{
                                cin.clear();
                                cin.ignore();
                                cout<<"** Invalid **\n";
                                cout<<"What is the updated vote count?\n";
                                cin>>info[mid].votes;
                            }while(info[mid].votes <= 0 || cin.fail());
                        }
                    }
                    else if(info[mid].name > searchItem)
                        last = mid - 1;
                    else
                        first = mid + 1;
                }

                if(found == false){
                    cout<<"We were unable to locate that name. Please try again...\n";
                    choice = 1;
                }
                else{
                    cout<<"Do you have to update another candidates votes?\n";
                    cout<<"Enter 1) YES \nEnter 2) NO\n";
                    cin>>choice;

                    if(choice < 1 || choice > 2 || cin.fail()){
                        do{
                            cin.clear();
                            cin.ignore();
                            cout<<"** Invalid **\n";
                            cout<<"Do you have to update another candidates votes?\n";
                            cout<<"Enter 1) YES \n Enter 2) NO\n";
                            cin>>choice;
                        }while(choice < 1 || choice > 2 || cin.fail());
                    }
                }

            }while(choice != 2);
        }
        if (choice = 2)
            change = 2;
    }while(change != 2);

sorter(info,temp,num);

return 0;
}
