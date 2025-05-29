#include <iostream>
using namespace std;
const int SHIFTS = 3;
const int DAYS = 7;
void inputDefects(float defects[SHIFTS][DAYS])
{
    cout << "Enter defect percentage for each shift over 7 days:" << endl;
    for (int i = 0; i < SHIFTS; i++) 
    {
        cout << "Shift " << i + 1 << ":" << endl;
        for (int j = 0; j < DAYS; j++) 
        {
            float value;
            do
            {
                cout << "  Day " << j + 1 << ": ";
                cin >> value;
                if (value < 0 || value > 100)
                {
                    cout << "  Invalid input. Enter a percentage between 0 and 100." << endl;
                }
            } 
            while (value < 0 || value > 100);
            defects[i][j] = value;
        }
    }
}
void calculateAvgPerShift(float defects[SHIFTS][DAYS], float shiftAvg[SHIFTS]) 
{
    for (int i = 0; i < SHIFTS; i++) 
    {
        float sum = 0;
        for (int j = 0; j < DAYS; j++) 
        {
            sum += defects[i][j];
        }
        shiftAvg[i] = sum / DAYS;
    }
}
void calculateAvgPerDay(float defects[SHIFTS][DAYS], float dayAvg[DAYS])
{
    for (int j = 0; j < DAYS; j++) 
    {
        float sum = 0;
        for (int i = 0; i < SHIFTS; i++) 
        {
            sum += defects[i][j];
        }
        dayAvg[j] = sum / SHIFTS;
    }
}
void displayAverages(float shiftAvg[SHIFTS], float dayAvg[DAYS])
{
    cout << endl;
    cout << "Average Defects Per Shift:" << endl;
    for (int i = 0; i < SHIFTS; i++) 
    {
        cout << "  Shift " << i + 1 << ": " << shiftAvg[i] << "%" << endl;
    }
    cout << endl;
    cout << "Average Defects Per Day:";
    for (int j = 0; j < DAYS; j++) 
    {
        cout << "  Day " << j + 1 << ": " << dayAvg[j] << "%" << endl;
    }
}
void identifyCriticalShifts(float shiftAvg[SHIFTS])
{
    cout << endl;
    cout << "Critical Shifts (avg defects > 10%):" << endl;
    bool found = false;
    for (int i = 0; i < SHIFTS; i++) 
    {
        if (shiftAvg[i] > 10.0)
        {
            cout << "  Shift " << i + 1 << " with " << shiftAvg[i] << "% defects" << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "  No critical shifts" << endl;
    }
}
int main()
{
    float defects[SHIFTS][DAYS];
    float shiftAvg[SHIFTS];
    float dayAvg[DAYS];
    inputDefects(defects);
    calculateAvgPerShift(defects, shiftAvg);
    calculateAvgPerDay(defects, dayAvg);
    displayAverages(shiftAvg, dayAvg);
    identifyCriticalShifts(shiftAvg);
    return 0;
}
