#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertices, edges;
vector<vector<int>> unweightedGraph(10);
vector<int> visited(10);
vector<int> twoColoring(10);
vector<int> bfs;

void graphColoring(int current, int color) {
    visited[current] = 1;
    twoColoring[current] = color;
    for (auto next : unweightedGraph[current]) {
        if (!visited[next])
            return graphColoring(next, color ^ 3);
        return 
    }
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
            bool isBipartite = graphColoring(i, 1);
            if (!isBipartite) {
                cout << "Impossible to Color.\n";
                exit(0);
            }
        }
    }
}