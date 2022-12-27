#include <iostream>
#include <vector>


using namespace std;

int n;
vector<int> time(1001);
vector<int> solve(1001);
vector<int> taken(1001);
int timeConstraint, problemLimit;

int problemSolvedRecursive(int level) {
    // Base Case
    if (level == n) 
        return 0;
    
    // Compute
    int answer = problemSolvedRecursive(level + 1);
    
    
}


int main() {

    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt", "w", stderr);

    cin >> n;

    for (int i = 0; i < n; i++) 
        cin >> time[i] >> solve[i];
    
    cin >> timeConstraint >> problemLimit;
    
    int maxProblems = problemSolvedRecursive(0);
    cout << maxProblems << "\n";
    
}