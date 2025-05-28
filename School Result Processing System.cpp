#include <iostream>
#include <iomanip>  /* im using iomanip for better console output formation
                       only after learning it completely..*/
using namespace std;
const int STUDENTS = 10;
const int SUBJECTS = 5;
void inputMarks(int marks[STUDENTS][SUBJECTS]) 
{
    cout << "Enter marks for 10 students (5 subjects each) " << endl;
    for (int i = 0; i < STUDENTS; i++)
    {
        cout << "Student " << i + 1 << "" << endl;
        for (int j = 0; j < SUBJECTS; j++)
        {
            cout << "  Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }
}
void calculateTotalsAndAverages(int marks[STUDENTS][SUBJECTS], int total[], float average[])
{
    for (int i = 0; i < STUDENTS; i++)
    {
        total[i] = 0;
        for (int j = 0; j < SUBJECTS; j++)
        {
            total[i] += marks[i][j];
        }
        average[i] = total[i] / (SUBJECTS * 1.0);
    }
}

void assignGrades(float average[], char grades[]) 
{
    for (int i = 0; i < STUDENTS; i++)
    {
        if (average[i] >= 85)
        {
            grades[i] = 'A';
        }
        else if (average[i] >= 70)
        {
            grades[i] = 'B';
        }
        else if (average[i] >= 50)
        {
            grades[i] = 'C';
        }
        else
        {
            grades[i] = 'F';
        }
    }
}
int findTopScorer(int total[])
{
    int maxIndex = 0;
    for (int i = 1; i < STUDENTS; i++)
    {
        if (total[i] > total[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}
void displayResults(int marks[STUDENTS][SUBJECTS], int total[], float average[], char grades[], int topScorer)
{
    cout << endl;
    cout << "School Result Summary" << endl;
    cout << left << setw(10) << "Student"  // left is used for aligning word to the left
        << setw(15) << "Total Marks" // using setw(15) so it aligns it width
        << setw(15) << "Average"
        << setw(10) << "Grade" << endl;
    for (int i = 0; i < STUDENTS; i++)
    {
        cout << left << setw(10) << "Student " << (i + 1)
            << setw(15) << total[i]
            << setw(15) << fixed << setprecision(2) << average[i] 
        // using fixed because it shows numbers is decimal format
        // setprecision is for how many numbers to show after point
            << setw(10) << grades[i] << endl;
    }
    cout << endl;
    cout << "Top Scorer= Student " << topScorer + 1 << " with " << total[topScorer] << " marks" << endl;
}
int main() 
{
    int marks[STUDENTS][SUBJECTS];
    int total[STUDENTS];
    float average[STUDENTS];
    char grades[STUDENTS];
    inputMarks(marks);
    calculateTotalsAndAverages(marks, total, average);
    assignGrades(average, grades);
    int topScorer = findTopScorer(total);
    displayResults(marks, total, average, grades, topScorer);
    return 0;
}
