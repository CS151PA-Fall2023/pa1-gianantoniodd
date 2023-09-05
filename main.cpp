/**
 * @file main.cpp
 * @author David Durrant
 * @brief Presents cvs file to user so they can view sorted information
 * @version 0.1
 * @date 2023-09-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "analytics.h"
using namespace std;

int main()
{

    vector <Major> majors;
    ifstream file;
    file.open("graduates2015.csv");
    readFileIntoVector(majors, file);
    file.close();
    vector <Major *> pointers;
    setPointersToVector(pointers, majors);
    int input = -1;
   
    while (true)
    {
        printMenu();
        collectValidInput(input);
        if (input ==12) break;
        if (input == 11)
        {
            specificMajor(majors);
            cin.ignore();
            cin.get();
            continue;
        }


        sortPointers(pointers, input);
        printPointers(pointers, input);
        cin.ignore();
        cin.get();


    
    }


    return 0;
}