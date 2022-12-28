#include <iostream>
#include <vector>


using namespace std;

int n;
vector<int> input;
int constraintSum;

int 

int main() {

    freopen("../../input.txt",  "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt",  "w", stderr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        input.emplace_back(x);
    }
    
    cin >> constraintSum;

    int sum = subsetSum(1, 0);
}   