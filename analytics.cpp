#include "analytics.h"
using namespace std;
/**
 * @brief 
 * 
 * @param v 
 */

void readFileIntoVector(vector<Major> &v, ifstream & file)
{
    string temp;
    getline(file, temp);
    while (true)
    {
        Major j;
        file >> j.total;
        file.ignore();
        if (file.peek() == '"')
        {   
            file.ignore();
            getline(file, j.major ,'"');
            file.ignore();
        }else 
        {
            getline(file, j.major ,',');
        }
        file >> j.mean;
        file.ignore();
        file >> j.median;
        file.ignore();
        file >> j.asian;
        file.ignore();
        file >> j.minorities;
        file.ignore();
        file >> j.white;
        file.ignore();
        file >> j.female;
        file.ignore();
        file >> j.male;
        file.ignore();
        file >> j.bachelors;
        file.ignore();
        file >> j.doctorates;
        file.ignore();
        file >> j.masters;
        file.ignore();
        j.percentageMale = 100 * (double(j.male)/j.total);
        v.push_back(j);

        if (file.peek() == EOF) break;
    }
}
void setPointersToVector(vector <Major *> &p, vector <Major> &v)
{
    for (long unsigned int i = 0; i < v.size(); i++)
    {
        Major * tmpptr;
        tmpptr = & v[i];
        p.push_back(tmpptr);
    }
}
double getValue(Major pointers, int input)
{
    if ((input == 1) || (input == 2)) return pointers.mean;
    if ((input == 3) || (input == 4)) return pointers.median;
    if ((input == 5) || (input == 6)) return pointers.asian;
    if ((input == 7) || (input == 8)) return pointers.minorities;
    if ((input == 9) || (input == 10)) return pointers.percentageMale;
    return -1;
}
void printMenu()
{
cout << "2015 National Survey of Recent College Graduate\n";
cout << "1. Top 10 Majors with the Highest Mean Salary\n";
cout << "2. Top 10 Majors with the Lowest Mean Salary\n";
cout << "3. Top 10 Majors with the Highest Median Salary\n";
cout << "4. Top 10 Majors with the Lowest Median Salary\n";
cout << "5. What are the Top 5 Majors with the Highest Number of Asians\n";
cout << "6. What are the Top 5 Majors with the Lowest Number of Asians\n";
cout << "7. What are the Top 5 Majors with the Highest Number of Minorities\n";
cout << "8. What are the Top 5 Majors with the Lowest Number of Minorities\n";
cout << "9. What are the Top 5 Majors with the Highest precentage of men\n";
cout << "10. What are the Top 5 Majors with the lowest precentage of men\n";
cout << "11. Display Information for a Specific Major\n";
cout << "12. Exit\n";
cout << "\n";
cout << "Select a Menu: _";


}
void collectValidInput(int &input)
{
    cin >> input;
    while ((input > 12) || (input < 1))
    {
        cin.get();
        cout << "invalid value"<< endl;
        cout << "Please enter a value between 1 and 12" << endl;
        cin >> input;
    }

}
void sortPointers(vector <Major *> & pointers, vector<Major> & majors, int input)
{
    bool sorted;
    do
    {
        sorted = true;

        for (long unsigned int i = 0; i < pointers.size()-1; i++)
        {
            Major * tmpptr;
            if (input%2)// if odd sort from large to small
            {
                if (getValue(*pointers[i], input) < getValue(*pointers[i+1],input))
                {
                    sorted = false;
                    tmpptr = pointers[i];
                    pointers[i] = pointers[i+1];
                    pointers[i+1] = tmpptr;
                }
            }
            if (!(input%2))// if even sort from small to large
            {
                if (getValue(*pointers[i], input) > getValue(*pointers[i+1],input))
                {
                    sorted = false;
                    tmpptr = pointers[i];
                    pointers[i] = pointers[i+1];
                    pointers[i+1] = tmpptr;
                }
            }
            
        



        }
    }while (!sorted);



}
void printPointers(vector <Major *> & pointers,int input)
{
    string sortBy[] = {"mean salary","median salary","# of asian", 
                    "# of minorities","percentage male"};

    cout << left << setw(40)<< "Education Major" << sortBy[(input-1)/2] << endl;
    cout << "---------------------------------------------" << endl;
    int range = 5;
    if (input <= 4) range = 10;
    for (int i = 0; i < range; i++) 
    {
        cout << left << setw(40)<< (*pointers[i]).major << getValue(*pointers[i], input) << endl;
    }


}
void specificMajor(vector <Major> &v)
{
    cout << "enter major (case sensitive): ";
    int index = -1;
    while (index == -1)
    {
        string majorName;
        cin >> majorName;
        cin.clear();
        
        for (long unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i].major == majorName)
            {
                index = i;
                break;
            }

        }   
        if (index == -1) cout << "Major not found, try again: ";

    }
    cout << "-------------------------"<< endl;
    cout << "Total #            " << v[index].total << endl;
    cout << "Mean salary $      " << v[index].mean << endl;
    cout << "Median salary $    " << v[index].median << endl;
    cout << "Asian #            " << v[index].asian << endl;
    cout << "Minorities #       " << v[index].minorities << endl;
    cout << "White #            " << v[index].white << endl;
    cout << "Male #             " << v[index].male << endl;
    cout << "Female #           " << v[index].female << endl;
    cout << "Bachleors #        " << v[index].bachelors << endl;
    cout << "Doctorates#        " << v[index].doctorates << endl;
    cout << "Masters #          " << v[index].masters << endl;
    

}

