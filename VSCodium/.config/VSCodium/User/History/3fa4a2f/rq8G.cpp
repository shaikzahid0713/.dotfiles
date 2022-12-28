#include <iostream>
#include <vector>


using namespace std;


bool setBitRightShift(int number, int position) {
    number >>= position;
    if (number & 1)
        return 1;
    return 0;
}


bool usingLeftShift(int number, int position) {
    int temp =  (1 << position);
    if (number & temp) 
        return 0;
    return 1;
}

int main() {

    freopen("../../input.txt",  "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt",  "w", stderr);

    int n, bit;
    cin >> n >> bit;

    bool usingRightShift = setBitRightShift(n, bit);
    cout << usingRightShift << "\n";

    bool usingLeftShift = setBitLeftShift(n, bit);
    cout << usingLeftShift << "\n";
}