#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> dp(100, -1);

int usingDP(int level) {
    // Pruning

    // Base Case
    if (level == n) return 1;

    // State Check
    if (dp[level] != -1) return dp[level];

    // Transition
    int answer = 0;
    for (int step = 1;  step < 4; step++) {
        if (level + step <= n) {
            int dp = usingDP(level + step);
            answer += dp;
        }
    }
    
    // Save and Move
    return dp[level] = answer;
}

int usingRecursion(int level) {
    // pruning

    // Base case
    if (level == n) return 1;

    // Transition 
    int ans = 0;
    for (int i = 1; i < 4; i++) {
        if (level + i <= n) {
            int recursive = usingRecursion(level + i);
            ans += recursive;
        }
    }
    return ans;
}

int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);

    int n; cin >> n;

    int recursive = usingRecursion(n);
    cout << recursive << "\n";

    int dp = usingDP(n);
    cout << dp << "\n";
}