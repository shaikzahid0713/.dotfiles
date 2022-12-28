#include <iostream>
#include <vector>


using namespace std;

int n;
vector<int> input;
int constraintSum;

vector<i

int subsetSumRecursive(int level, int sum) {
    // Pruning
    if (sum > constraintSum) 
        return 0;

    // Base Case
    if (level == n) {
        if (sum == constraintSum)
            return 1;
        else 
            return 0;
    }

    // Transition
    int answer = 0;
    if (subsetSumRecursive(level + 1, sum)  || subsetSumRecursive(level + 1, sum + input[level]))
        answer = 1;

    // Save and Return
    return answer;
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