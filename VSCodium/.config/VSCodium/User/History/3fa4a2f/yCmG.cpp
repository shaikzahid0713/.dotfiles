#include <iostream>
#include <vector>


using namespace std;



int main() {

    freopen("../../input.txt",  "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt",  "w", stderr);

    int n, bit;
    cin >> n >> bit;

    bool isSet = setBit(n, bit);
    cout << isSet << ""
}