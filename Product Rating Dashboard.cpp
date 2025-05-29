#include <iostream>
using namespace std;
const int PRODUCTS = 5;
const int USERS = 10;
void inputRatings(int ratings[PRODUCTS][USERS]) 
{
    cout << "Enter ratings (1 to 5) for 5 products by 10 users:" << endl;
    for (int i = 0; i < PRODUCTS; i++)
    {
        cout << "Product " << i + 1 << ":" << endl;
        for (int j = 0; j < USERS; j++)
        {
            int rate;
            do 
            {
                cout << "  User " << j + 1 << ": ";
                cin >> rate;
                if (rate < 1 || rate > 5)
                {
                    cout << "  Invalid. Enter a rating between 1 and 5.\n";
                }
            } 
            while (rate < 1 || rate > 5);
            ratings[i][j] = rate;
        }
    }
}
void calculateAverageRatings(int ratings[PRODUCTS][USERS], float avg[PRODUCTS])
{
    for (int i = 0; i < PRODUCTS; i++)
    {
        int sum = 0;
        for (int j = 0; j < USERS; j++)
        {
            sum += ratings[i][j];
        }
        avg[i] = (float)sum / USERS;
    }
}
void countPerfectRatings(int ratings[PRODUCTS][USERS], int perfectCount[PRODUCTS])
{
    for (int i = 0; i < PRODUCTS; i++)
    {
        int count = 0;
        for (int j = 0; j < USERS; j++) 
        {
            if (ratings[i][j] == 5)
            {
                count++;
            }
        }
        perfectCount[i] = count;
    }
}
void displayWorstRatedProducts(float avg[PRODUCTS])
{
    float minAvg = avg[0];
    for (int i = 1; i < PRODUCTS; i++)
    {
        if (avg[i] < minAvg)
        {
            minAvg = avg[i];
        }
    }
    cout << endl;
    cout << "Product(s) with the worst average rating (" << minAvg << "):" << endl;
    for (int i = 0; i < PRODUCTS; i++)
    {
        if (avg[i] == minAvg)
        {
            cout << "  Product " << i + 1 << endl;
        }
    }
}
void displayDashboard(float avg[PRODUCTS], int perfectCount[PRODUCTS])
{
    cout << endl;
    cout << "--------Product Rating Dashboard--------" << endl;
    for (int i = 0; i < PRODUCTS; i++) 
    {
        cout << "Product " << i + 1 << " -> Avg Rating: " << avg[i]
            << ", Perfect Ratings: " << perfectCount[i] << endl;
    }
}
int main()
{
    int ratings[PRODUCTS][USERS];
    float avgRatings[PRODUCTS];
    int perfectRatings[PRODUCTS];
    inputRatings(ratings);
    calculateAverageRatings(ratings, avgRatings);
    countPerfectRatings(ratings, perfectRatings);
    displayDashboard(avgRatings, perfectRatings);
    displayWorstRatedProducts(avgRatings);
    return 0;
}
