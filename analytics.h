#ifndef ANALYTICS_H
#define ANALYTICS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;
struct Major
{
    int total;
    string major;
    double mean;
    double median;
    double percentageMale;
    int asian;
    int minorities;
    int white;
    int female;
    int male;
    int bachelors;
    int doctorates;
    int masters;
};

void readFileIntoVector(vector <Major> &v, ifstream & file);
void setPointersToVector(vector <Major *> &p, vector <Major> &v);
double getValue(Major pointers, int input);
void printMenu();
void collectValidInput(int &input);
void sortPointers(vector <Major *> & pointers, int input);
void printPointers(vector <Major *> & pointers,int input);
void specificMajor(vector <Major> &v);

#endif
