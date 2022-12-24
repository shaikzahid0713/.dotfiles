#include <iostream>
#include <vector>


using namespace std;


void ComputingPowerRecursive(int base, int power) {
    if (power == 0) return 1;

    int temp = ComputingPowerRecursive(base, power >> 1);
    temp *= temp;

    if (power % 2) return base;
    else return 
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