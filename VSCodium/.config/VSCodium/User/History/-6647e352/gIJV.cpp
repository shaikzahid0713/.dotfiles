#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n; 
int lis[10000];
int dp[10000];

int longestIncreasingSubsequence(int level) {
    
    // Pruning and Base Case
    if (level < 0 || level >= n) 
        return 0;
    
    // Cache Check 
    if (dp[level] != -1) 
        return dp[level];
    
    // Transition
    int answer = 1;
    for (int previousTaken = 0; previousTaken < level; previousTaken++) {
        if (lis[level] > lis[previousTaken]) 
            answer = max(answer, lis[previousTaken] + )
    }
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