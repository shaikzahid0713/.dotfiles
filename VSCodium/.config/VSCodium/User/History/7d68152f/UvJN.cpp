#include <iostream>
#include <vector>


using namespace std;



int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);

    int base, power;
    cin >> base >> power;

    ComputingPower(base, power);
}