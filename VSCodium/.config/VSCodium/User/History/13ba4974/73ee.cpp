#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void run_tests() {
    int n;
    cin >> n;
    unordered_set<int> result;
    while (n-- > 0) {
        int x; cin >> x;
        result.insert(x);
    }
    cout << result.size() << "\n";
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