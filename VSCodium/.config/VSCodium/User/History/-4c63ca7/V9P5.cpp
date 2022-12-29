#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
int grid[1000][1000];
bool visited[1000][1000];
int dp[1000][1000];

int gridSumRecursive(int row, int column) {

    // Pruning 
    if (row < 0 || column < 0)
        return -1e9;
    
    // Base case

    // Compute
    

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