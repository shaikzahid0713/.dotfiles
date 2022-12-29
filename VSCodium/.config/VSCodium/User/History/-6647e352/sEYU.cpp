#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n; 
int lis[10000];
int dp[10000];

int longestIncreasingSubsequence(int level) {
    
    // Pruning
    if (level < 0 || level >= n) 
        return 0;
}

int main() {

    freopen("../../../input.txt",  "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt",  "w", stderr);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) 
        cin >> lis[i];
    
    memset(dp, -1, sizeof(dp));
    
    int bestLis = 0;
    for (int i = 0; i < n; i++) {
        bestLis = max(bestLis, longestIncreasingSubsequence(i));
    }
    cout << bestLis << "\n";
}