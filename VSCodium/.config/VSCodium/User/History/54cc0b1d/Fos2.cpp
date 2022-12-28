#include <iostream>
#include <vector>


using namespace std;

int setBitCountUsingWhile(int number) {
    int answer = 0;
    while (number) {
        answer += (number & 1);
        number >>= 1;
    }
    return answer;
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