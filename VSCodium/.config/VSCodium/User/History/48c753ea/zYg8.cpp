#include <iostream>
#include <vector>
#include <cstring>

using namespace std;




void run_tests() {
    int n; cin >> n;
    long long ans = (n & 1) ? (n * n) - 1 : (n * n);
    cout << ans << "\n";
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("../../input.txt",  "r", stdin);
        freopen("../../output.txt", "w", stdout);
        freopen("../../error.txt",  "w", stderr);
    #endif

    int tests = 1;
    // cin >> tests;

    while(tests-- > 0) {
         run_tests();
    }

}

/*

*/