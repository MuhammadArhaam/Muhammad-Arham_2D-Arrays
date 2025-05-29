#include <iostream>
using namespace std;
const int ROWS = 5;
const int COLS = 5;
void inputBookStatus(char books[ROWS][COLS])
{
    cout << "Enter status for each book (A = Available, I = Issued, M = Missing):" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "Shelf " << i + 1 << ":" << endl;
        for (int j = 0; j < COLS; j++)
        {
            char status;
            do 
            {
                cout << "  Book " << j + 1 << ": ";
                cin >> status;
                if (status != 'A' && status != 'I' && status != 'M')
                {
                    cout << "  Invalid input. Please enter A, I, or M." << endl;
                }
            } 
            while (status != 'A' && status != 'I' && status != 'M');
            books[i][j] = status;
        }
    }
}
void displayBookStatus(char books[ROWS][COLS]) 
{
    cout << endl;
    cout << "--------Library Book Status--------" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < COLS; j++)
        {
            cout << books[i][j] << " ";
        }
        cout << endl;
    }
}
void countBookStatus(char books[ROWS][COLS], int& available, int& issued, int& missing) 
{
    available = issued = missing = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (books[i][j] == 'A')
            {
                available++;
            }
            else if (books[i][j] == 'I')
            {
                issued++;
            }
            else if (books[i][j] == 'M')
            {
                missing++;
            }
        }
    }
}
void findShelvesWithMostMissing(char books[ROWS][COLS])
{
    int maxMissing = 0;
    int missingPerRow[ROWS] = { 0 };
    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (books[i][j] == 'M')
            {
                count++;
            }
        }
        missingPerRow[i] = count;
        if (count > maxMissing)
        {
            maxMissing = count;
        }
    }
    cout << endl;
    cout << "Shelf(s) with the highest missing books (" << maxMissing << "):" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        if (missingPerRow[i] == maxMissing)
        {
            cout << "  Shelf " << i + 1 << endl;
        }
    }
}
int main() 
{
    char books[ROWS][COLS];
    int available, issued, missing;
    inputBookStatus(books);
    displayBookStatus(books);
    countBookStatus(books, available, issued, missing);
    cout << endl;
    cout << "Total Available Books: " << available << endl;
    cout << "Total Issued Books: " << issued << endl;
    cout << "Total Missing Books: " << missing << endl;
    findShelvesWithMostMissing(books);
    return 0;
}
