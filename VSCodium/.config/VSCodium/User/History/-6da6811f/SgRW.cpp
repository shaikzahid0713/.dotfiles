#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n, m, o;
string a, b, c;

int dp[100][100][100];
int longestCommonSubsequence(int i, int j, int k) {
    // Pruning

    // Base Case
    if (i >= n || j >= m || k >= o) 
        return 0;
    
    // Cache Check
    if (dp[i][j][k] != -1) 
        return dp[i][j][k];
    
    int answer = 0;
    if (a[i] == b[j] && b[j] == c[k])
        answer = max(answer, )
}

int longestCommonSubsequenceRecursive(int i, int j, int k) {
    // Pruning 

    // Base Case
    if (i >= n || j >= m || k >= o) 
        return 0;

    // Compute
    int answer = 0;
    if (a[i] == b[j] && b[j] == c[k])
        answer = max(answer, 1 + longestCommonSubsequenceRecursive(i + 1, j + 1, k + 1));
    answer = max(answer, longestCommonSubsequenceRecursive(i, j + 1, k));
    answer = max(answer, longestCommonSubsequenceRecursive(i + 1, j, k));
    answer = max(answer, longestCommonSubsequenceRecursive(i, j, k + 1));
    
    return answer;
}
int main() {

    freopen("../../../input.txt",  "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt",  "w", stderr);

    cin >> n >> m >> o;
    cin >> a >> b >> c;

    int lcsRecursive = longestCommonSubsequenceRecursive(0, 0, 0);
    cout << lcsRecursive << "\n";

}