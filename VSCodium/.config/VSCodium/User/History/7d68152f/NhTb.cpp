#include <iostream>
#include <vector>


using namespace std;


int ComputingPowerRecursive(int base, int power) {
    if (power == 0) return 1;

    int temp = ComputingPowerRecursive(base, power >> 1);
    temp *= temp;

    if (power % 2) return temp * base;
    else return base;
}


int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);

    int base, power;
    cin >> base >> power;

    ComputingPower(base, power);
    ComputingPowerRecursive(base, power);
}