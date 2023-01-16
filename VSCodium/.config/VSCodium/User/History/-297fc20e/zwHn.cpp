#include <iostream>
#include <vector>


using namespace std;


void run_tests() {
    int n; 
    cin >> n;

    vector<bool> tests(n + 1);
    vector<int> first, second;
    long long sum = (n * (n + 1)) >> 1;
    sum >>= 1;
    if (sum & 1) cout << "NO" << endl;
    else {
        int i = n;
        while(sum) {
            first.emplace_back(n);
            tests[n] = 1;
            sum -= n;
        }
        if (sum) first.emplace_back(sum);

        for (int i = 0; i <= n; i++) {
            if (!tests[i]) second.emplace_back(i);
        }
    }
    cout << first.size() << "\n";
    for (int i = 0; i < first.size(); i++) 
        cout << first[i] << " ";
    cout << "\n";

    cout << second.size() << "\n";
    for (int i = 0; i < second.size(); i++)
        cout << second[i] << " ";
    cout << "\n";
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