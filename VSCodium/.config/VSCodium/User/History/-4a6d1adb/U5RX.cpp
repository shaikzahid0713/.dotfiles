#include <iostream>
#include <vector>


using namespace std;




void run_tests() {
    long long a, b;
    cout << a << " " << b << endl;
    // while (a > 0) a -= 3;
    // while (b > 0) b -= 3;
    cout << a << " " << b << "\n";
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