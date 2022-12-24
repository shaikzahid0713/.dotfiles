#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define bts(jimin) cerr << #jimin << " -> "; loveYourself(jimin); cerr << "\n";
void loveYourself(int jimin)    { cerr << jimin; }
template <class T> void loveYourself(vector <T> v) { 
    cerr << "[ ";
    for (T suga : v) {
        loveYourself(suga);
        cerr << " ";
    }
    cerr << "]";
}

int vertices, edges;
vector<vector<int>> graph(10);
vector<int> visited(10);
vector<int> bfs;
vector<int> dfs;

bool hasCycle(int current, int parent) {
    visited[current] = 1;
    for (auto next : graph[current]) {
        if (!visited[next])
            return hasCycle(next, current);
        return current != parent;
    }
    return false;
}

int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);
    
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int x, y; cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
}