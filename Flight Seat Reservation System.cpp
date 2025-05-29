#include <iostream>
using namespace std;
const int ROWS = 6;
const int COLS = 4;
void initializeSeats(char seats[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            seats[i][j] = 'E';
        }
    }
}
void displaySeats(char seats[ROWS][COLS]) 
{
    cout << endl;
    cout << "--------SEATING CHART--------" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < COLS; j++) 
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}
void bookSeat(char seats[ROWS][COLS], int row, int col)
{
    if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS)
    {
        if (seats[row - 1][col - 1] == 'E') 
        {
            seats[row - 1][col - 1] = 'B';
            cout << "Seat successfully booked!" << endl;
        }
        else
        {
            cout << "Seat is already booked" << endl;
        }
    }
    else 
    {
        cout << "Invalid seat position" << endl;
    }
}
int countAvailableSeats(char seats[ROWS][COLS])
{
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (seats[i][j] == 'E')
            {
                count++;
            }
        }
    }
    return count;
}
int rowWithMaxEmptySeats(char seats[ROWS][COLS])
{
    int maxRow = 0, maxEmpty = 0;
    for (int i = 0; i < ROWS; i++) 
    {
        int emptyCount = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (seats[i][j] == 'E')
            {
            emptyCount++;
            }
        }
        if (emptyCount > maxEmpty)
        {
            maxEmpty = emptyCount;
            maxRow = i;
        }
    }

    return maxRow + 1;
}
int showMenuAndGetChoice()
{
    int choice;
    cout << endl;
    cout << "--------FLIGHT SEAT RESERVATION MENU--------" << endl;
    cout << "1. Display Seating Chart" << endl;
    cout << "2. Book a Seat" << endl;
    cout << "3. Count Available Seats" << endl;
    cout << "4. Row with Maximum Empty Seats" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
void handleUserChoice(int choice, char seats[ROWS][COLS])
{
    switch (choice)
    {
    case 1:
        displaySeats(seats);
        break;
    case 2:
    {
        int row, col;
        cout << "Enter row (1-6) and column (1-4) to book: ";
        cin >> row >> col;
        bookSeat(seats, row, col);
        break;
    }
    case 3:
    {
        cout << "Available seats: " << countAvailableSeats(seats) << endl;
        break;
    }
    case 4:
    {
        cout << "Row with maximum empty seats: " << rowWithMaxEmptySeats(seats) << endl;
        break;
    }
    case 0:
    {
        cout << "Exiting program" << endl;
        break;
    }
    default:
    {
        cout << "Invalid choice" << endl;
    }
    }
}
int main() 
{
    char seats[ROWS][COLS];
    initializeSeats(seats);
    int choice;
    do 
    {
        choice = showMenuAndGetChoice();
        handleUserChoice(choice, seats);
    }
    while (choice != 0);
    return 0;
}

