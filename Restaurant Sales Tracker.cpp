#include <iostream>
#include <iomanip>  
using namespace std;
const int ITEMS = 4;
const int DAYS = 7;
void inputSales(float sales[ITEMS][DAYS])
{
    cout << "        ENTER SALES DATA        " << endl;
    for (int i = 0; i < ITEMS; i++)
    {
        for (int j = 0; j < DAYS; j++)
        {
            cout << "Enter sales for Item " << i + 1 << " on Day " << j + 1 << ": ";
            cin >> sales[i][j];
        }
    }
}
void totalSalesPerItem(float sales[ITEMS][DAYS])
{
    cout << endl;
    cout << "        TOTAL SALES PER ITEM        " << endl;
    for (int i = 0; i < ITEMS; i++)
    {
        float total = 0;
        for (int j = 0; j < DAYS; j++)
        {
            total += sales[i][j];
        }
        cout << "Item " << i + 1 << "= " << fixed << setprecision(2) << total << endl;
    }
}
void totalSalesPerDay(float sales[ITEMS][DAYS])
{
    cout << endl;
    cout << "        TOTAL SALES PER DAY        " << endl;;
    for (int j = 0; j < DAYS; j++) 
    {
        float total = 0;
        for (int i = 0; i < ITEMS; i++)
        {
            total += sales[i][j];
        }
        cout << "Day " << j + 1 << "= " << fixed << setprecision(2) << total << endl;
    }
}
void findHighestSalesDay(float sales[ITEMS][DAYS])
{
    float maxSales = -1;
    int maxDayIndex = -1;
    for (int j = 0; j < DAYS; j++)
    {
        float total = 0;
        for (int i = 0; i < ITEMS; i++)
        {
            total += sales[i][j];
        }
        if (total > maxSales)
        {
            maxSales = total;
            maxDayIndex = j;
        }
    }
    cout << endl;
    cout << "        HIGHEST SALES DAY        " << endl;
    cout << "Day " << maxDayIndex + 1 << " had the highest sales= " << fixed << setprecision(2) << maxSales << endl;
}
void findTopSellingItem(float sales[ITEMS][DAYS])
{
    float maxSales = -1;
    int topItemIndex = -1;
    for (int i = 0; i < ITEMS; i++)
    {
        float total = 0;
        for (int j = 0; j < DAYS; j++)
        {
            total += sales[i][j];
        }
        if (total > maxSales)
        {
            maxSales = total;
            topItemIndex = i;
        }
    }
    cout << endl;
    cout << "        TOP SELLING ITEM        ";
    cout << "Item " << topItemIndex + 1 << " was sold the most with total sales= " << fixed << setprecision(2) << maxSales << endl;
}
int main()
{
    float sales[ITEMS][DAYS];
    inputSales(sales);
    totalSalesPerItem(sales);
    totalSalesPerDay(sales);
    findHighestSalesDay(sales);
    findTopSellingItem(sales);
    return 0;
}
