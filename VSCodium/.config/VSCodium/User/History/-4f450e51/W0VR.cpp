#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, k;
int iceCream[1000];

int subsetDistance() {
    unordered_map<int, vector<int>> uMap;
    for (int i = 0; i < n; i++) {
        uMap[iceCream[i]].emplace_back(i);
    }
    
    for (auto x : uMap) {
        cout << x.first << " : Indexes - ";
        vector<int> current = x.second;
        for (auto y : current) 
            cout << y << " ";
    cout << "\n";
    }

    int count = 0;

    for (auto x : uMap) {
        vector<int> current = x.second;
        for (int i = 0; i < current.size(); i++) {
            for (int j = i + 1; j < current.size(); j++) 
                if (current[j] - current[i] >= k) count++;
        }
    }

    return count;
}

int main() {

    freopen("../../input.txt",  "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt",  "w", stderr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> iceCream[i];
    
    int noOfWays = subsetDistance();
    cout << noOfWays << "\n";

}

/*

5 2 
1 2 2 1 2
*/