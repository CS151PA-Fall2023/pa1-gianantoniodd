#include "analytics.h"
using namespace std;

int main()
{

    vector <Major> majors;
    ifstream file;
    file.open("graduates2015.csv");
    readFileIntoVector(majors, file);
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


        sortPointers(pointers, majors, input);
        printPointers(pointers, input);
        cin.ignore();
        cin.get();


    
    }


    return 0;
}