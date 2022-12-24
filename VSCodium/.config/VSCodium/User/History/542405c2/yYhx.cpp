#include <iostream>
#include <vector>

using namespace std;

int usingRecursion(int level) {
    // pruning

    // Base case
    if (level == n) return 1;

    // Transition 
    int ans = 0;
    for (int i = 1; i < 4; i++) {
        int
    }
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