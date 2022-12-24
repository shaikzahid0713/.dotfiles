#include <iostream>
#include <vector>
#include <math.h>


using namespace std;



int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);

    int n; cin >> n;

    int usingWhile = 0;
    
    int k = n;
    while (k != 0) {
        k /= 10;
        usingWhile++;
    }
    
    cout << usingWhile << "\n";

    int usingLog = floor(log10(n)) + 1;
    cout << usingLog << "\n";


    int i = 1, trailingZeros = 0;
    while (pow(5, i) <= n) {
        trailingZeros +=  floor(n / pow(5, i));
        i++;
    }
    cout << trailingZeros << "\n";
}