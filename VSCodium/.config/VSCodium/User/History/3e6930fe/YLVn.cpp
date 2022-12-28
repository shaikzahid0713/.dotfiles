#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> time(1001);
vector<int> skill(1001);
int timeConstraint, problemLimit;

int dp[105][105][105];

int problemSolvedDynamicProgramming(int level, int timeTaken, int itemTaken) {

    // Pruning

    // Base Case
    if (level == n) 
        return 0;
    
    // Cache check
    if (dp[level][timeTaken][itemTaken] != -1) 
        return dp[level][timeTaken][itemTaken];

    //  Transition
    // 1. Don't Take
    int answer = problemSolvedDynamicProgramming(level + 1, timeTaken, itemTaken);

    // 2. Check and Take
    if (timeTaken + time[level] <= timeConstraint && itemTaken + 1 <= problemLimit) 
        answer = max(answer, problemSolvedDynamicProgramming(level + 1, timeTaken + time[level], itemTaken + 1));
    
    // Save and Return
    return dp[level][timeTaken][itemTaken] = answer;
}

int problemSolvedRecursive(int level, int timeTaken, int itemTaken) {
    if (level == n) 
        return 0;
    
    int answer = problemSolvedRecursive(level + 1, timeTaken, itemTaken);

    if (timeTaken + time[level] <= timeConstraint && itemTaken + 1 <= problemLimit) {
        answer = max(answer, skill[level] + problemSolvedRecursive(level + 1, timeTaken + time[level], itemTaken + 1));
    }

    return answer;
}

int main() {

    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt", "w", stderr);

    cin >> n;
    
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) 
        cin >> time[i] >> skill[i];
    
    cin >> timeConstraint >> problemLimit;
    
    int maxProblems = problemSolvedRecursive(0, 0, 0);
    cout << maxProblems << "\n";
    
}

//  Backtracking Code 

// vector<int> taken(1001);

// bool canTake(int level) {
//     int timeTaken = 0;
//     int itemTaken = 0;

//     for (int i = 0; i < level; i++) {
//         if (taken[i]) {
//             timeTaken += time[i];
//             itemTaken++;
//         }
//     }
//     timeTaken += time[level];
//     itemTaken++;

//     if (timeTaken <= timeConstraint && itemTaken <= problemLimit) 
//         return 1;
//     return 0;
// }

// int problemSolvedRecursiveLong(int level) {
//     // Base Case
//     if (level == n) 
//         return 0;
    
//     // Compute
//     // Choice-1 : Don't Take
//     int answer = problemSolvedRecursive(level + 1);

//     // Choice-2: Take
//     if (canTake(level)) {
        
//         // Place The Change
//         taken[level] = 1;
        
//         //  Move
//         answer = max(answer, skill[level] + canTake(level + 1));
        
//         // Revert
//         taken[level] = 0;
//     }
//     return answer;
// }