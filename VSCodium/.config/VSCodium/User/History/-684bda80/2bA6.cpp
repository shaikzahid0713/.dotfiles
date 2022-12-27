#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> queen(20, -1);

bool canPlace(int row, int column) {
    for (int i = 0; i < row; i++) {
        int prevRow = i;
        int prevColumn = queen[i];

        if ()
    }
}

int queenCombinationsRecursive(int row) {
    // Pruning

    // Base Case
    if (row == n) 
        return 1;

    // Compute
    int answer = 0;
    for (int column = 0;  column < n; column++) {
        if (canPlace(row, column)) 
    }
}

int main() {

    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt", "w", stderr);
    
    cin >> n;
    
    queenCombinationsRecursive(0);

}