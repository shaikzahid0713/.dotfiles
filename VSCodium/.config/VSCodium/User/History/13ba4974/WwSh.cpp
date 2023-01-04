#include <iostream>
#include <vector>
#include <unordered_set>
#include <deque>

using namespace std;

void run_tests() {
    int n;
    cin >> n;
    deque<int> temp;
    while (n-- > 0) {
        int x; cin >> x;
        temp.emplace_front(x);
    }
    
    cout << temp.front() << "\n";
    cout << temp.back() << "\n";
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