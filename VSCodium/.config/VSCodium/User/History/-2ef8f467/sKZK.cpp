#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertices, edges;
vector<vector<int>> graph(10);
vector<int> visited(10);
vector<int> distance(10);
vector<int> bfs;
vector<int> dfs;

   

void breadthFirstSearch(int current) {
    queue<int> bfsQueue;
    bfsQueue.emplace(current);
    bfs.emplace_back(current);
    visited[current] = 1;
    
    while(!bfsQueue.empty()) {
        int parent = bfsQueue.front();
        bfsQueue.pop();
        for (auto child : graph[parent]) {
            if (!visited[child]) {
                visited[child] = 1;
                bfsQueue.emplace(child);
                bfs.emplace_back(child);
            }
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int x, y; 
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    
    breadthFirstSearch(0);
    
    for (auto x : bfs) 
        cout << x << " ";
    cout << "\n";

}

