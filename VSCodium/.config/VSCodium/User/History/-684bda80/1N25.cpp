#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> queen(20, -1);

int queenCombinationsRecursive(int row) {
    // Pruning

    // Base Case
    if (row == n) 
        return 1;

    // Compute
    
}

int main() {

    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt", "w", stderr);
    
    cin >> n;
    
    queenCombinationsRecursive(0);

}