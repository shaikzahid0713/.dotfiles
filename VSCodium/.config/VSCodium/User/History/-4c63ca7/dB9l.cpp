#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
int grid[1000][1000];
bool visited[1000][1000];
int dp[1000][1000];

int gridSum(int row, int column) {
    
    // Pruning
    if (row < 0 || column < 0) 
        return -1e9;
    
    // Base Case
    if (row == 0 && column == 0)
        return grid[0][0];
    
    // Cache Check
    if (done[row][column]) 
        return dp[row][column];
    
    // Transition 
    int answer = -1e9;
    answer = grid[row][column] + max(gridSum(row - 1, column), gridSum(row, column - 1));

    // Save and Return
    
}

int gridSumRecursive(int row, int column) {

    // Pruning 
    if (row < 0 || column < 0)
        return -1e9;
    
    // Base case
    if (row == 0 && column == 0)
        return grid[row][column];

    // Compute
    int answer = -1e9;
    answer = max(gridSumRecursive(row - 1, column) + grid[row][column], gridSumRecursive(row, column - 1) + grid[row][column]);

    // Return
    return answer;
}

int main() {

    freopen("../../input.txt",  "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt",  "w", stderr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];
    
    memset(dp, -1, sizeof(dp));

    int maxSumRecursive = gridSumRecursive(n - 1, m - 1);
    cout << maxSumRecursive << "\n";
}