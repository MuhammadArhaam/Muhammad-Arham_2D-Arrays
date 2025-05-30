#include <iostream>
using namespace std;
const int STATIONS = 6;
const int CANDIDATES = 4;
void inputVotes(int votes[STATIONS][CANDIDATES])
{
    cout << "Enter votes for 4 candidates from 6 polling stations:" << endl;
    for (int i = 0; i < STATIONS; i++) 
    {
        cout << "Polling Station " << i + 1 << ":" << endl;
        for (int j = 0; j < CANDIDATES; j++)
        {
            cout << "  Candidate " << j + 1 << ": ";
            cin >> votes[i][j];
        }
    }
}
void totalVotesPerCandidate(int votes[STATIONS][CANDIDATES], int candidateTotal[CANDIDATES])
{
    for (int j = 0; j < CANDIDATES; j++) 
    {
        candidateTotal[j] = 0;
        for (int i = 0; i < STATIONS; i++)
        {
            candidateTotal[j] += votes[i][j];
        }
    }
}
void totalVotesPerStation(int votes[STATIONS][CANDIDATES], int stationTotal[STATIONS])
{
    for (int i = 0; i < STATIONS; i++) 
    {
        stationTotal[i] = 0;
        for (int j = 0; j < CANDIDATES; j++) 
        {
            stationTotal[i] += votes[i][j];
        }
    }
}
void findWinners(int candidateTotal[CANDIDATES])
{
    int maxVotes = 0;
    for (int i = 0; i < CANDIDATES; i++)
    {
        if (candidateTotal[i] > maxVotes)
        {
            maxVotes = candidateTotal[i];
        }
    }
    cout << endl;
    cout << "Winner(s) with " << maxVotes << " votes:" << endl;
    for (int i = 0; i < CANDIDATES; i++) 
    {
        if (candidateTotal[i] == maxVotes)
        {
            cout << "  Candidate " << i + 1 << endl;
        }
    }
}
void detectLowTurnoutStations(int stationTotal[STATIONS]) 
{
    cout << endl;
    cout << "Polling Station(s) with voter turnout < 100:" << endl;
    bool found = false;
    for (int i = 0; i < STATIONS; i++)
    {
        if (stationTotal[i] < 100) 
        {
            cout << "  Station " << i + 1 << " (Total votes: " << stationTotal[i] << ")" << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "  None" << endl;
    }
}
void displayCandidateTotals(int candidateTotal[CANDIDATES])
{
    cout << endl;
    cout << "Total Votes Per Candidate:" << endl;
    for (int i = 0; i < CANDIDATES; i++) 
    {
        cout << "  Candidate " << i + 1 << ": " << candidateTotal[i] << " votes" << endl;
    }
}
void displayStationTotals(int stationTotal[STATIONS])
{
    cout << endl;
    cout << "Total Votes Per Polling Station:" << endl;
    for (int i = 0; i < STATIONS; i++)
    {
        cout << "  Station " << i + 1 << ": " << stationTotal[i] << " votes" << endl;
    }
}
int main()
{
    int votes[STATIONS][CANDIDATES];
    int candidateTotal[CANDIDATES] = { 0 };
    int stationTotal[STATIONS] = { 0 };
    inputVotes(votes);
    totalVotesPerCandidate(votes, candidateTotal);
    totalVotesPerStation(votes, stationTotal);
    displayCandidateTotals(candidateTotal);
    displayStationTotals(stationTotal);
    findWinners(candidateTotal);
    detectLowTurnoutStations(stationTotal);
    return 0;
}
