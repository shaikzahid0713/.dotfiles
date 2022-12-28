#include <iostream>
#include <vector>


using namespace std;

int n;
vector<int> input;
int constraintSum;

int subsetSumRecursive(int level, int sum) {
    // Pruning

    // Base Case
    if (level == n)
        return 0;

    // Transition
    

    // Save and Return
} 

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

    int sumRecursive = subsetSumRecursive(1, 0);
    cout << sumRecursive << "\n";
}   