#include <iostream>
#include <iomanip>
using namespace std;
const int TEAMS = 6;
const int ROUNDS = 4;
void inputScores(int scores[TEAMS][ROUNDS]) 
{
    cout << "--------ENTER SCORES FOR EACH TEAM AND ROUND--------" << endl;
    for (int i = 0; i < TEAMS; i++) 
    {
        cout << "Team " << i + 1 << " scores:" << endl;
        for (int j = 0; j < ROUNDS; j++) 
        {
            cout << "  Round " << j + 1 << ": ";
            cin >> scores[i][j];
        }
    }
}
void totalScoresPerTeam(int scores[TEAMS][ROUNDS], int totals[TEAMS])
{
    for (int i = 0; i < TEAMS; i++)
    {
        int sum = 0;
        for (int j = 0; j < ROUNDS; j++) 
        {
            sum += scores[i][j];
        }
        totals[i] = sum;
    }
}
void findWinnerRunnerUp(int totals[TEAMS], int& winner, int& runnerUp)
{
    int max1 = -1, max2 = -1;
    winner = -1;
    runnerUp = -1;
    for (int i = 0; i < TEAMS; i++) 
    {
        if (totals[i] > max1) 
        {
            max2 = max1;
            runnerUp = winner;
            max1 = totals[i];
            winner = i;
        }
        else if (totals[i] > max2 && totals[i] != max1) 
        {
            max2 = totals[i];
            runnerUp = i;
        }
    }
}
void displayLowScoringTeams(int scores[TEAMS][ROUNDS])
{
    cout << endl;
    cout << "--------TEAMS WITH ANY ROUND SCORE <= 10--------" << endl;
    bool found = false;
    for (int i = 0; i < TEAMS; i++)
    {
        bool lowScore = false;
        for (int j = 0; j < ROUNDS; j++)
        {
            if (scores[i][j] <= 10)
            {
                lowScore = true;
                break;
            }
        }
        if (lowScore)
        {
            cout << "Team " << i + 1 << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No teams scored 10 or less in any round" << endl;
    }
}
void displayTotalScores(int totals[TEAMS])
{
    cout << endl;
    cout << "--------TOTAL SCORES PER TEAM--------" << endl;
    for (int i = 0; i < TEAMS; i++) 
    {
        cout << "Team " << i + 1 << ": " << totals[i] << endl;
    }
}
void displayWinners(int totals[TEAMS])
{
    int winner = -1, runnerUp = -1;
    findWinnerRunnerUp(totals, winner, runnerUp);
    cout << endl;
    cout << "--------WINNER & RUNNER-UP--------" << endl;
    cout << "Winner: Team " << winner + 1 << " with " << totals[winner] << " points" << endl;
    if (runnerUp != -1)
    {
        cout << "Runner-up: Team " << runnerUp + 1 << " with " << totals[runnerUp] << " points" << endl;
    }
    else
    {
        cout << "No runner-up found (tie or single team)" << endl;
    }
}
int main() 
{
    int scores[TEAMS][ROUNDS];
    int totals[TEAMS];
    inputScores(scores);
    totalScoresPerTeam(scores, totals);
    displayTotalScores(totals);
    displayWinners(totals);
    displayLowScoringTeams(scores);
    return 0;
}
