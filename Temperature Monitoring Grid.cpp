#include <iostream>
#include <iomanip>
using namespace std;
const int SIZE = 5;
void inputTemperature(float temp[SIZE][SIZE])
{
    cout << "--------ENTER TEMPERATURE DATA (in °C)--------" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++
            ) {
            cout << "Zone [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> temp[i][j];
        }
    }
}
void averageTemperaturePerRow(float temp[SIZE][SIZE])
{
    cout << endl;
    cout << "--------AVERAGE TEMPERATURE PER ROW (ZONE)--------" << endl;
    for (int i = 0; i < SIZE; i++) 
    {
        float sum = 0;
        for (int j = 0; j < SIZE; j++)
        {
            sum += temp[i][j];
        }
        float avg = sum / SIZE;
        cout << "Zone " << i + 1 << ": " << fixed << setprecision(2) << avg << " °C" << endl;
    }
}
void findExtremeSpots(float temp[SIZE][SIZE])
{
    float maxTemp = temp[0][0], minTemp = temp[0][0];
    int maxRow = 0, maxCol = 0, minRow = 0, minCol = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (temp[i][j] > maxTemp)
            {
                maxTemp = temp[i][j];
                maxRow = i;
                maxCol = j;
            }
            if (temp[i][j] < minTemp)
            {
                minTemp = temp[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    cout << endl;
    cout << "--------EXTREME TEMPERATURE SPOTS--------" << endl;
    cout << "HOTTEST Spot: " << maxTemp << " °C at [" << maxRow + 1 << "][" << maxCol + 1 << "]" << endl;
    cout << "COLDEST Spot: " << minTemp << " °C at [" << minRow + 1 << "][" << minCol + 1 << "]" << endl;
}
int main()
{
    float temp[SIZE][SIZE];
    inputTemperature(temp);
    averageTemperaturePerRow(temp);
    findExtremeSpots(temp);
    return 0;
}
