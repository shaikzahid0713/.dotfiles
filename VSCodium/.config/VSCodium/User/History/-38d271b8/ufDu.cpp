#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertices, edges;
vector<vector<int>> unweightedGraph(10);
vector<int> visited(10);
vector<int> bfs;
vector<int> twoColoring;

void graph(int current, int color) {
    
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        unweightedGraph[x].emplace_back(y);
        unweightedGraph[y].emplace_back(x);
    }
    

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (!graphColoring(i, 1)) {
                cout << "Impossible to Color.\n";
                exit(0);
            }
        }
    }
}