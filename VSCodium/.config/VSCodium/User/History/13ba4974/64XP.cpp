#include <iostream>
#include <vector>
#include <set>

using namespace std;

void run_tests() {
    int n;
    cin >> n;
    set<int> result;
    while (n-- > 0) {
        int x; cin >> x;
        result.insert(x);
    }
    cout << result.size() << "\n";
}

int32_t main() {

        freopen("../../../input.txt",  "r", stdin);
        freopen("../../../output.txt", "w", stdout);
        freopen("../../../error.txt",  "w", stderr);

    int tests = 1;
    cin >> tests;

    while(tests-- > 0) {
         run_tests();
    }

}

/*

*/