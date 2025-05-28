#include <iostream>
using namespace std;
const int PATIENTS = 5;
const int DAYS = 7;
void inputStatus(char status[PATIENTS][DAYS])
{
    cout << "-------ENTER PATIENT STATUS DATA-------" << endl;
    cout << "Use ONLY uppercase letters: 'S' (Stable)" << endl;
    cout << "'C' (Critical)" << endl;
    cout<<"'R' (Recovered)" << endl;
    for (int i = 0; i < PATIENTS; i++)
    {
        for (int j = 0; j < DAYS; j++)
        {
            char s;
            do 
            {
                cout << "Patient " << i + 1 << ", Day " << j + 1 << ": ";
                cin >> s;

                if (s != 'S' && s != 'C' && s != 'R') 
                {
                    cout << "Invalid input! Please enter only 'S', 'C', or 'R'.\n";
                }
            } 
            while (s != 'S' && s != 'C' && s != 'R');
            status[i][j] = s;
        }
    }
}
void countStatusCategories(char status[PATIENTS][DAYS]) 
{
    int stable = 0, critical = 0, recovered = 0;
    for (int i = 0; i < PATIENTS; i++)
    {
        for (int j = 0; j < DAYS; j++)
        {
            if (status[i][j] == 'S')
            {
                 stable++;
            }
            else if (status[i][j] == 'C')
            {
                critical++;
            }
            else if (status[i][j] == 'R')
            {
                recovered++;
            }
        }
    }
    cout << endl;
    cout << "--------STATUS COUNTS (ALL PATIENTS & DAYS)--------" << endl;
    cout << "Stable (S)= " << stable << endl;
    cout << "Critical (C)= " << critical << endl;
    cout << "Recovered (R)= " << recovered << endl;
}
void countCriticalDaysPerPatient(char status[PATIENTS][DAYS])
{
    cout << endl;
    cout << "--------DAYS IN CRITICAL STATE PER PATIENT--------" << endl;
    for (int i = 0; i < PATIENTS; i++) 
    {
        int criticalCount = 0;
        for (int j = 0; j < DAYS; j++)
        {
            if (status[i][j] == 'C')
            {
                criticalCount++;
            }
        }
        cout << "Patient " << i + 1 << ": " << criticalCount << " day(s) in critical state" << endl;
    }
}
int main()
{
    char status[PATIENTS][DAYS];
    inputStatus(status);
    countStatusCategories(status);
    countCriticalDaysPerPatient(status);
    return 0;
}
