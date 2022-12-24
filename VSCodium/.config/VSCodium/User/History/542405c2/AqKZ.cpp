#include <iostream>
#include <vector>


using namespace std;

string path = "/home/shaik/Programming/DSA/Data-Structuers";
int n;
vector<int> dp(100, -1);

int usingDP(int level) {
    // Pruning

    // Base Case
    if (level == n) 
        return 1;

    // State Check
    if (dp[level] != -1) 
        return dp[level];

    // Transition
    int answer = 0;

    for (int step = 1;  step < 4; step++) {
        if (level + step <= n) {
            int noOfWays = usingDP(level + step);
            answer += noOfWays;
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
            int noOfWays= usingRecursion(level + i);
            ans += noOfWays;
        }
    }
    return ans;
}

int main() {
    
    string input = path + "/input.txt";

    freopen( , "r", stdin);
    freopen( path + "/output.txt", "w", stdout);
    freopen( path + "/error.txt", "w", stderr);

    cin >> n;

    int recursive = usingRecursion(n);
    cout << recursive << "\n";

    int dp = usingDP(n);
    cout << dp << "\n";
}