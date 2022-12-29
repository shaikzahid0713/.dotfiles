#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n; 
int lis[10000];
int dp[10000];

int longestIncreasingSubsequenceFirstForm(int level, int lastIndex) {
    // Base Case
    if (level == n) 
        return 0;
    
    // Transition
    int answer = longestIncreasingSubsequenceFirstForm(level + 1, lastIndex);
    if (lis[level] > lis[lastIndex])
        answer = max(answer, lis[level] + longestIncreasingSubsequenceFirstForm(level + 1, level));

    return answer;
}

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
            answer = max(answer, 1 + longestIncreasingSubsequence(previousTaken));
    }
    
    // Save and Return
    return dp[level] = answer;
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
    
    for (int i = 0; i < n; i++)
        cout <<  dp[i] << " ";
    cout << "\n";
    
    int firstForm = longestIncreasingSubsequenceFirstForm(0, 0);
    cout << firstForm << "\n";

}



// 10
// 3 2 5 4 5 7 8 1 11 9