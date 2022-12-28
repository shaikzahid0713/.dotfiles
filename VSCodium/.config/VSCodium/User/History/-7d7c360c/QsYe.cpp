#include <iostream>
#include <vector>


using namespace std;


bool usingWhile(unsigned int n) {
    if (n == 0)
        return 0;
    while(n != 1) {
        if (!n % 2)
            return 0;
        n >>= 1;
    }
    return 1;
}

bool usingLog(unsigned int n) {
    
}

int main() {

    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt", "w", stderr);

    unsigned int x;
    cin >> x;

    bool withWhile = usingWhile(x);
    cout << withWhile << "\n";
    
    bool withLog = usingLog(x);
    cout << withLog << "\n";

    bool withBits = usingBits(x);
    cout << withBits << "\n";
}