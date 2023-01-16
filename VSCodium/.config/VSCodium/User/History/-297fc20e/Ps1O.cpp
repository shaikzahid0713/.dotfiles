#include <iostream>
#include <vector>


using namespace std;




void run_tests() {
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {   
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    
    }

    cout << sum << endl;
    
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