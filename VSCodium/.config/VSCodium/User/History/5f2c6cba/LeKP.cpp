#include <iostream>
#include <vector>


using namespace std;

int n;
vector<int> input;
int constraintSum;

int dp[105][10100];
int subsetSumDynamicProgramming(int level, int sum) {
    // Pruning
    if (sum > constraintSum) 
        return 0;
    
    // Base Case
    if (level == n + 1) {
        if (sum == constraintSum) 
            return 1;
        else   
            return 0;
    }
    
    // Cache Check
    if (dp[level][sum] != -1) 
        return dp[level][sum];

    // Transition
    int answer = 0;
    if (subsetSumDynamicProgramming(level + 1, sum) || subsetSumDynamicProgramming(level + 1, sum + input[level]))
        answer = 1;
    
    // Save and Return
    return dp[level][sum] = answer;
}


int subsetSumRecursive(int level, int sum) {
    // Pruning
    if (sum > constraintSum) 
        return 0;

    // Base Case
    if (level == n) {
        if (sum == constraintSum)
            return 1;
        else 
            return 0;
    }

    // Transition
    int answer = 0;
    if (subsetSumRecursive(level + 1, sum)  || subsetSumRecursive(level + 1, sum + input[level]))
        answer = 1;

    // Save and Return
    return answer;
} 

int main() {

    freopen("../../input.txt",  "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt",  "w", stderr);
    
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        input.emplace_back(x);
    }
    
    cin >> constraintSum;

    int sumRecursive = subsetSumRecursive(1, 0);
    cout << sumRecursive << "\n";
}   