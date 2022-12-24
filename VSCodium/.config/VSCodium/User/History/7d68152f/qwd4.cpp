#include <iostream>
#include <vector>


using namespace std;


int ComputingPowerRecursive(int base, int power) {
    if (power == 0) return 1;

    int temp = ComputingPowerRecursive(base, power / 2);
    temp *= temp;

    if (power & 1) return temp * base;
    else return temp;
}

int ComputingPower(int base, int power) {
    int result = 1;
    while (power > 0) {
        if (power % 2)
            result *= base;
        base *= base;
        power >>= 1;
    }
    return result;
}

int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);

    int base, power;
    cin >> base >> power;

    int answer = ComputingPower(base, power);
    cout << "Power of " << base << " is " <<  answer << "\n";
    
    
    int recursive = ComputingPowerRecursive(base, power);
    cout << "Power of " << base << " using Recursion is " << recursive << "\n";
}