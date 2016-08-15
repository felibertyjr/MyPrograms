#include <iostream>
#include <iomanip>
using namespace std;
/**INSTRUCTIONS:
                Write a program that reads students' names followed by their test scores. The
                program should output each students name followed by their test scores and the
                relevant grade. It should also find and print the highest test score and the name
                of the student with the highest score.
*************************************************************************************************/
//Try to create a void function that does the question part. Pass the reference of the pointer(&).
//Don't forget to delete pointers!
//ALSO, Try to make a new struct for just the name and see how to link list it together.
//And make a seperate struct for individual test scores.

/*********** RECORD STRUCT *******/
struct studentType{
    string studentFName;
    string studentLName;
    float avg;
    string grade;
    studentType *link;
}*first,*last,*newNode,*current;
/********************************/


int main(){

    int a, b, numStu,numTest, sum = 0, *grades;
    float high;

    /**********         Questions to get us started             ****************/
    /**********             With Input Validation               ****************/

    cout<<"Please tell me how many students are in the class?"<<endl;
    cin>>numStu;

    if (numStu < 0 || cin.fail()){
        do{
            cin.clear();
            cin.ignore();
            cout<<"**That is not valid**"<<endl;
            cout<<"Please tell me how many students are in the class?"<<endl;
            cin>>numStu;
        }while(numStu < 0 || cin.fail());
    }

    /**************** Question 2 ***********/

    cout<<"Please tell me how many tests did the students take this semester?"<<endl;
    cin>>numTest;

    if (numTest <= 0 || cin.fail()){
        do{
            cin.clear();
            cin.ignore();
            cout<<"**That is not valid**"<<endl;
            cout<<"Please tell me how many tests did the students take this semester?"<<endl;
            cin>>numTest;
        }while(numTest < 0 || cin.fail());
    }

    grades = new int[numTest];//Sets the size of our pointer array

    /********************       End of Questions        ********************************/

    /*******         Start of creating Linked List Nodes and updating their members           *******/


    first = NULL; //Needed to set pointer MEMORY LOCATION to NULL or ZERO

    for(a=0;a<numStu;a++){//Run loop for the correct number of students

        newNode = new studentType;//Creates a new node in linked list.
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Please enter student "<<a+1<<"s FIRST name:\n";
        cin>>newNode->studentFName;//Requesting FIRST name of student
            if (cin.fail()){//Input Validation
                do{
                    cout<<"** INVALID **\n";
                    cout<<"Please enter student "<<a+1<<"s FIRST name:\n";
                    cin>>newNode->studentFName;
                } while(cin.fail());
            }
        /*********              END OF STEP 1                   **********/

        cout<<"Please enter student "<<a+1<<"s LAST name\n";
        cin>>newNode->studentLName;//Requesting LAST name of student
            if (cin.fail()){//Input Validation
                    do{
                        cout<<"** INVALID **\n";
                        cout<<"Please enter student "<<a+1<<"s LAST name\n";
                        cin>>newNode->studentLName;
                    } while(cin.fail());
                }
        /*********              END OF STEP 2                   **********/


        for(b=0;b<numTest;b++){//Nested FOR-LOOP to get students test scores and store in pointer array
            cout<<"Please enter "<<newNode->studentFName<<" "<<newNode->studentLName<<"'s test score Number "<<b+1<<endl;
            cin>>grades[b];
            if (grades[b] < 0 || grades[b] > 100|| cin.fail()){//Input Validation
                    do{
                        cout<<"** INVALID **\n";
                        cout<<"Please enter "<<newNode->studentFName<<" "<<newNode->studentLName<<"'s test score Number "<<b+1<<endl;
                        cin>>grades[b];
                    } while(grades[b] < 0 || grades[b] > 100|| cin.fail());
                }
            sum = sum + grades[b];//Get sum of the tests
        }//End of nested FOR-LOOP

        /*********              END OF STEP 3                   **********/

        newNode->avg = (sum/numTest) * 1.0;//Get avg for student of current Linked List Node and store it

        if (newNode->avg >= 90)//This section is to assign a letter grade according to avg
            newNode->grade = "A";
        else if (newNode->avg >= 80)
            newNode->grade = "B";
        else if (newNode->avg >= 70)
            newNode->grade = "C";
        else if (newNode->avg >= 60)
            newNode->grade = "D";
        else
            newNode->grade = "F";

        /*********              END OF STEP 4                   **********/

        if (first == NULL){//This section is to apply appropriate memory addresses to the node that being worked on.
            first = newNode;
            last = newNode;
        }
        else {
            last->link = newNode;
            last = newNode;
        }

        /*********              END OF STEP 5                   **********/

    sum = 0; //clear sum for next student
    }

    /******************************        END of main FOR-LOOP         **********************/

    last->link = NULL; //assign the last Link List Node to NULL.
    current = first; //copy memory address of starting node to a variable
    high = 0.0; // to get the student with the highest avg


    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<left;
    cout<<setw(20)<<"First Name"<<setw(20)<<"Last Name"<<setw(5)<<"AVG"<<setw(5)<<"GRADE"<<endl;
    cout<<"\n";

    /******     This is to traverse the linked list to find the student with the highest avg     ******/
    while(current != NULL){
        cout<<left;
        cout<<setw(20)<<current->studentFName<<setw(20)<<current->studentLName<<setw(5)<<current->avg<<setw(5)<<current->grade<<endl;

        if(high < current->avg){
                high = current->avg;
        }
        current = current->link;
    }
    /*************************************     End of FIRST traversal      ******************************/


    /***********************        This section is to find a print who has the Highest average in the class        ****************/
    current = first; //copy memory address of starting node to a variable again

    while(current != NULL){
        if (high == current->avg){
            cout<<left;
            cout<<current->studentFName<<" "<<current->studentLName<<" has the highest grade of the class with and average of: "<<current->avg<<endl;
            current = NULL;
        }
        else
            current = current->link;
    }
    /************************************************       End of Last Traversal       **********************************************/

delete grades;//clear memory of pointer array.
return 0;
}//End of Program
