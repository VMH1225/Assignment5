// Date: 10/04/2022
// Description: Chapter 5 - Assignment
// By: Victor Huerta Alejandro Mamani, Arturo Sanchez, Bryan Soto, and Tien Nguyen

#include <iostream>
#include "input.h"
#include "vectorContain.h"
using namespace std;

int menuOption();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1: {
            vectorContain v;
            v.vectorMain();
        }break;
        default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
        }
    } while (true);
    return EXIT_SUCCESS;
}

// return a valid option (0...3)
int menuOption()
{
    system("cls");
    cout << "\n\t==============================================================================================";
    cout << "\n\tCMPR131 Chapter 5 - Vector and List Container (10/04/2022)";
    cout << "\n\tDeveloped by Group 3: Victor H., Alejandro M., Arturo S., Bryan S., and Tien N.";
    cout << "\n\t==============================================================================================";
    cout << "\n\t\t1> Vector container";
    cout << "\n\t\t2> List container";
    cout << "\n\t\t3> Application using Vector and/or List container";
    cout << "\n\t----------------------------------------------------------------------------------------------";
    cout << "\n\t\t0> Exit";
    cout << "\n\t==============================================================================================\n";

    int option = inputInteger("\tOption: ", 0, 3);
    system("cls");

    return option;
}