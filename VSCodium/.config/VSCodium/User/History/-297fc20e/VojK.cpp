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
        long long count = 0, k = n;
        sum >>= 1;
        while(sum > k) {
            count++;
            tests[k] = 1;
            sum -= k;
            k--;
        }
        if (sum > 0) tests[sum] = 1;

        cout << "YES" << "\n";
        cout << count << "\n";
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