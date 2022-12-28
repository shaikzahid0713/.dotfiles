#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>


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
    if (n == 0)
        return 0;
    return floor(log2(n)) == ceil(log2(n));
}

float logn(unsigned int x, int r) {
    return log (x) / log (r);
}

bool powerOfAnyBase(unsigned int n, int base) {
    if (n == 0) 
        return 0;
    return floor(logn(n, base)) == ceil(logn(n, base));
}

bool usingBits(unsigned int n) {
    if (n == 0)
        return 0;
    return (!(n & (n - 1)));
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
    
    int base; cin >> base;
    bool usingAnyBase = powerOfAnyBase(x, base);
    cout << "Power OF " << base << " " << usingAnyBase << "\n";
}