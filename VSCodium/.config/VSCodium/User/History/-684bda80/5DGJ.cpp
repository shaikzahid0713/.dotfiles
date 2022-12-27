#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int n;
vector<int> queen(20, -1);

bool canPlace(int row, int column) {
    for (int i = 0; i < row; i++) {
        int prevRow = i;
        int prevColumn = queen[i];

        if (prevColumn == column || abs(prevColumn - column) == abs(prevRow - row)) 
            return 0;
    }
    return 1;
}

int queenCombinationsRecursive(int row) {
    // Pruning

    // Base Case
    if (row == n) 
        return 1;

    // Compute
    int answer = 0;
    for (int column = 0;  column < n; column++) {
        if (canPlace(row, column)) {
            queen[row] = column;
            answer += canPlace(row + 1);
            queen[row] = -1;
        }
    }
    return answer;
}

int main() {

    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt", "w", stderr);
    
    cin >> n;
    
    int noOfWays = queenCombinationsRecursive(0);
    cout << noOfWays << "\n";

}