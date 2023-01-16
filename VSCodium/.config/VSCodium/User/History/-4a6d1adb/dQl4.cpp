#include <iostream>
#include <vector>


using namespace std;




void run_tests() {
    long long a, b;
    cin >> a >> b;
    
    if (abs(a - b) > 1) {
        cout << "NO\n";
        return;
    }
    
    a %= 3, b %= 3;
    if ((a == 0 && b == 0) || (a == 1 && b == 2) || (a == 2 && b == 1)) 
        cout << "YES\n";
    else cout << "NO\n";
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