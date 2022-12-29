#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, o;
string a, b, c;

int dp[]

int main() {

    freopen("../../input.txt",  "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt",  "w", stderr);

    cin >> n >> m >> o;
    cin >> a >> b >> c;

    int lcsRecursive = longestCommonSubsequenceRecursive(0, 0, 0);
    cout << lcsRecursive << "\n";

}