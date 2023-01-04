#include <iostream>
#include <vector>
#include <set>

using namespace std;




void run_tests() {
    int n, x; cin >> n >> x;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ms.emplace(x);
    }
    
    vector<int> arr;
    for (auto x : ms) 
        arr.emplace_back(x);
    
    int count = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] <= x) count++;
        else {
            count++'
        }
    }
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