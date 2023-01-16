#include <iostream>
#include <vector>


using namespace std;




void run_tests() {
    int n; 
    cin >> n;
    int ans = 0;
    for (int i = 5; i <= n; i += 5) {
        ans += (n / i);
    }
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