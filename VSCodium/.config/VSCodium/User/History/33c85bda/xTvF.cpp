#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

int n;
vector<int> input;
int constraintSum;

int dp[105][10100];
int subsetSumMultipleQueries(int level, int sumLeft) {
    // Pruning
    if (sumLeft < 0)
        return 0;
    
    // Base Case
    if (level == n + 1) {
        if (sumLeft == 0) 
            return 1;
        else
            return 0;
    }

    // Cache check
    if (dp[level][sumLeft] != -1) 
        return dp[level][sumLeft];

    // Transition 
    int answer = 0;
    if (subsetSumMultipleQueries(level + 1, sumLeft) == 1)
        answer = 1;
    else if (subsetSumMultipleQueries(level + 1, sumLeft - input[level]))
        answer = 1;
    // Save and Return
    return dp[level][sumLeft] = answer;
}

void printSubset(int level, int sumLeft) {
    if (level == n + 1) 
        return;
    if (subsetSumMultipleQueries(level + 1, sumLeft) == 1)
        printSubset(level + 1, sumLeft);
    else if (subsetSumMultipleQueries(level + 1, sumLeft - input[level])) {
        cout << input[level] << " ";
        printSubset(level + 1, sumLeft - input[level]);
    }
}

int main() {

    freopen("../../../input.txt",  "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt",  "w", stderr);
    
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        input.emplace_back(x);
    }
    
    int queries;
    cin >> queries;
    while(queries-- > 0) {
        cin >> constraintSum;
        if (subsetSumMultipleQueries(0, constraintSum)) {
            printSubset(0, constraintSum);
            cout << "\n";
        }
        else
            cout << "No Solution\n";
    }
    
}