#include <iostream>
#include <vector>


using namespace std;

#define bts(jimin) cerr << #jimin << " -> "; loveYourself(jimin); cerr << endl;
void loveYourself(int jimin)    { cerr << jimin; }
template <class T> void loveYourself(vector <T> v) { 
    cerr << "[ ";
    for (T suga : v) {
        loveYourself(suga);
        cerr << " ";
    }
    cerr << "]";
}

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
    
    for (int step = 1; step < 4; step++) {
        if (level + step <= n) {
            int noOfWays = usingDP(level + step);
            answer += noOfWays;
        }
    }
    
    // Save and Return
    return dp[level] = answer;
}


int steppingLadder(int level) {
    //pruning


    //base Case
    if (level == n) 
        return 1;
    
    // Transition
    int answer = 0;
    
    for (int step = 1; step < 4; step++) {
        if (level + step <= n) {
            int noOfWays = steppingLadder(level + step);
            answer += noOfWays;
        }
    }
    // Save and return
    return answer;
}


int main() {

    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt", "w", stderr);
    
    cin >> n;
    
    
    bts(dp);

    cout << n << "\n";
    cout << usingDP(1) << "\n";
    
    bts(dp);
}