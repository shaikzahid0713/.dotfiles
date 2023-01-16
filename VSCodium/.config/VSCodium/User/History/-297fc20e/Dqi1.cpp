#include <iostream>
#include <vector>


using namespace std;


void run_tests() {
    int n; 
    cin >> n;

    vector<bool> tests(n + 1);
    long long sum = (n * (n + 1)) >> 1;
    sum >>= 1;
    if (sum & 1) cout << "NO" << endl;
    else {
        
    }
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
    cin >> tests;

    while(tests-- > 0) {
         run_tests();
    }

}

/*

*/