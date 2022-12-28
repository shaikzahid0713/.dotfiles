#include <iostream>
#include <vector>


using namespace std;

int setBitCountUsingWhile(int number) {
    int answer = 0;
    while (number) {
        
    }
}


int main() {

    freopen("../../input.txt",  "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt",  "w", stderr);

    int n; 
    cin >> n;

    int usingWhile = setBitCountUsingWhile(n);
    cout << usingWhile << "\n";
}