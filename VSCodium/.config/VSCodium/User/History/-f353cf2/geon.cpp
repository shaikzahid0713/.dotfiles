#include <iostream>
#include <queue>

using namespace std;

int v, e;
vector<int> graph(10);
vector<int> visited(10);
vector<int> bfs;

void breadthFirstSearch(int current) {
    queue<int> bfsQueue;
    bfsQueue.push(current);
    visited[current] = 1;
    while(!bfsQueue.empty()) {
        int parent = bfsQueue.top();
        bfsQueue.pop();
        bfs.emplace_back(parent);
        for (auto child : graph[parent]) {
            if (!visited[child]) {
                bfsQueue.push(child);
                bfs.emplace_back(child);
            }
        }
    }
}

int main() {

    freopen("input.txt", 'r', stdin);
    freopen("output.txt", 'w', stdout);
    
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    
    breadthFirstSearch(0);
}