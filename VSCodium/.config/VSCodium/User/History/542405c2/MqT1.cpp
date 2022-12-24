#include <iostream>
#include <vector>


using namespace std;

int usingRecursion(int level) {
    //pruning

    //base case
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