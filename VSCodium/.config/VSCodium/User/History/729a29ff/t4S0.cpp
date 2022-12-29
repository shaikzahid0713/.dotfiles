#include <iostream>
#include <vector>
#include <string.h>


using namespace std;

int n;
vector<int> weights, value;
int capacity, maxWeight;


int knapsackRecursive(int level, int weightLeft, int maxWeight) {

    // Pruning
    if (weightLeft <= 0) 
        return 0;
    
    // Base Case;
    if (level == n) 
        return maxWeight;
    
    // Compute
    // 1. Don't Take
    int answer = knapsackRecursive(level + 1, weightLeft, maxWeight);
    
    // 2.Take
    answer = max(answer, knapsackRecursive(level + 1, weightLeft - value[level], maxWeight + weights[level]));

    // Return
    return answer;
}

int knapsackRecursiveShort(int level, int weightTaken) {

    // Pruning
    
    // Base Case
    if (level == n)
        return 0;
    
    // Compute
    // 1. Don't Take
    int answer = knapsackRecursiveShort(level + 1, weightTaken);

    // 2. Check And Take
    if (weightTaken + value[level] <= capacity)
        answer = max(answer, weights[level] + knapsackRecursiveShort(level + 1, weightTaken + value[level]));

    // Return
    return answer;
}

int dp[100][100100];

int knapsack(int level, int weightLeft) {
    //  Pruning

    // Base Case
    if (level == n) 
        return 0;
    
    // Cache Check
    if (dp[level][weightLeft] != -1)
        return dp[level][weightLeft];
    
    // Transition
    // 1. Don't Take
    int answer = knapsack(level + 1, weightLeft);

    // 2. Check and Take
    if (weightLeft >= value[level]) 
        answer = max(answer, weights[level] + knapsack(level + 1, weightLeft - value[level]));
    
    // Save and Return
    return dp[level][weightLeft] = answer;
}



void printKnapsack(int level, int weightLeft) {
    
    // Base Case
    if (level == n + 1)
        return;
    
    // Compute
    // 1. Don't Take
    if (knapsack(level + 1, weightLeft))
        printKnapsack(level + 1, weightLeft);
    
    // 2. Take
    if (knapsack(level + 1, weightLeft - value[level])) {
        cout << weights[level + 1] << " ";
        printKnapsack(level + 1, weightLeft - value[level]);
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
        value.emplace_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        weights.emplace_back(x);
    }
    
    cin >> capacity;

    int maxWeightRecursive = knapsackRecursiveShort(0, 0);
    cout << maxWeightRecursive << "\n";
    
    int queries;
    cin >> queries;
    
    while (queries-- > 0) {
        int w; cin >> w;
        
        int maxWeight = knapsack(0, w);
        
        if (maxWeight)  {
            cout << w << "- " <<  maxWeight << ": ";
            printKnapsack(0, w);
            cout << "\n";
        }
        else
            cout << "No Solution\n";
    }
}

// 3
// 3 4 5
// 30 50 60
// 8
// 3
// 8
// 9
// 7