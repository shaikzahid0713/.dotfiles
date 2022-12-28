#include <iostream>
#include <vector>


using namespace std;

int n;
vector<int> time(1001);
vector<int> skill(1001);
vector<int> taken(1001);
int timeConstraint, problemLimit;

bool cantake(int level) {
    int timetaken = 0;
    int itemtaken = 0;

    for (int i = 0; i < level; i++) {
        if (taken[i]) {
            timetaken += time[i];
            itemtaken++;
        }
    }
    timetaken += time[level];
    itemtaken++;

    if (timetaken <= timeconstraint && itemtaken <= problemlimit) 
        return 1;
    return 0;
}

int problemsolvedrecursivelong(int level) {
    // base case
    if (level == n) 
        return 0;
    
    // compute
    // choice-1 : don't take
    int answer = problemsolvedrecursive(level + 1);

    // choice-2: take
    if (cantake(level)) {
        
        // place the change
        taken[level] = 1;
        
        //  move
        answer = max(answer, skill[level] + cantake(level + 1));
        
        // revert
        taken[level] = 0;
    }
    return answer;
// }


int main() {

    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
    freopen("../../../error.txt", "w", stderr);

    cin >> n;

    for (int i = 0; i < n; i++) 
        cin >> time[i] >> skill[i];
    
    cin >> timeConstraint >> problemLimit;
    
    int maxProblems = problemSolvedRecursiveLong(0);
    cout << maxProblems << "\n";
    
}