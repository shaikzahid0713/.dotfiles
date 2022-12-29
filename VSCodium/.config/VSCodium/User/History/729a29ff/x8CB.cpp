#include <iostream>
#include <vector>


using namespace std;

int n;
vector<int> weights, value;
int capacity, maxWeight;


int knapsackRecursive(int level, int weightLeft, int maxWeight) {

    // Pruning
    if (weightLeft < 0) 
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

int knapsackRecursiveShort(int level, int weightLeft) {
    // Pruning
    
    
    // Base Case
    if (level == n)
        return 0;
    
    // Compute
    // 1. Don't Take
    int answer = knapsackRecursiveShort(level + 1, weightLeft);

    // 2. Check And Take
    if (weightLeft >= value[level])
        answer = max(answer, weights[level] + knapsackRecursiveShort(level + 1, weightLeft - value[level]));

    // Return
    return answer;
}

int dp[100][100];

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

    int maxWeightRecursive = knapsackRecursiveShort(0, capacity);
    cout << maxWeightRecursive << "\n";
    
    int maxWeight = knapsack(0, capacity);
    cout << maxWeight << "\n";
}