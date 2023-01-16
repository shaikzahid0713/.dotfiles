#include <iostream>
#include <vector>


using namespace std;


void run_tests() {
    long long n; 
    cin >> n;

    vector<bool> tests(n + 1);
    long long sum = (n * (n + 1)) >> 1;
    if (sum % 2) cout << "NO" << "\n";
    else {
        int count = 0;
        sum >>= 1;
        while(sum > n) {
            tests[n] = 1;
            sum -= n;
            n--;
        }
        if (sum > 0) {
            tests[sum] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (!tests[i]) second.emplace_back(i);
        }

        cout << "YES" << "\n";
        cout << first.size() << "\n";
        for (int i = 0; i < first.size(); i++) 
            cout << first[i] << " ";
        cout << "\n";

        cout << second.size() << "\n";
        for (int i = 0; i < second.size(); i++)
            cout << second[i] << " ";
        cout << "\n";       
        
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
    // cin >> tests;

    while(tests-- > 0) {
         run_tests();
    }

}

/*

*/