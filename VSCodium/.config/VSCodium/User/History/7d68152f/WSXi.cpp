#include <iostream>
#include <vector>


using namespace std;


int ComputingPowerRecursive(int base, int power) {
    if (power == 0) return 1;

    int temp = ComputingPowerRecursive(base, power / 2);
    temp *= temp;

    if (power % 2 == 0) return base;
    else return temp * base;
}

int ComputingPower(int base, int power) {
    int result = 1;
    while (power > 0) {
        if (power % 2) {
            result *= base;
            
        }
    }
}

int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);

    int base, power;
    cin >> base >> power;

    // ComputingPower(base, power);
    int answer= ComputingPowerRecursive(base, power);
    cout << answer << "\n";
}