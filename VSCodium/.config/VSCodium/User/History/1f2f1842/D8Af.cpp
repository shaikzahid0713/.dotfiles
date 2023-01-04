#include <iostream>
#include <vector>

using namespace std;

#define bts(jimin) cerr << #jimin << " -> "; loveYourself(jimin); cerr << endl;
void loveYourself(int jimin)    { cerr << jimin; }
template <class T> void loveYourself(vector <T> v) { 
    cerr << " [ ";
    for (T suga : v) {
        loveYourself(suga);
        cerr << " ";
    }
    cerr << "]";
}

int n;
vector<int> dp(100, -1);

int diceCombinations(int level) {
    if (level == n) 
        return 1;
    
    if (dp[level] != -1) 
        return dp[level];
    
    int answer = 0;

    for (int dice = 1; dice < 7; dice++) {
        if (level + dice <= n) {
            int noOfWays = diceCombinations(level + dice);
            answer += noOfWays;
        }
    }
    return dp[level] = answer;
}

int main() {

    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt", "w", stderr);
    
    cin >> n;

    int noOfWays = diceCombinations(1);
    cout << noOfWays << "\n";
    
    bts(dp);
}