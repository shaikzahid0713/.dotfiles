#include <iostream>
#include <vector>
#include <set>

using namespace std;




void run_tests() {
    int n; cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.emplace(x);
    }
    
    vector<int> 
}

int32_t main() {

    ios::sync_with_stdio(false)
    cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("../../input.txt",  "r", stdin);
        freopen("../../output.txt", "w", stdout);
        freopen("../../error.txt",  "w", stderr);
    #endif

    int tests = 1;

    while(tests-- > 0) {
         run_tests();
    }

}

/*

*/