#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<vector<int>> graph(10);
vector<int> visited(10);
vector<int> bfs;
vector<int> dfs;


void depthFirstSearch(int current) {
    visited[current] = 1;
    dfs.emplace_back(current);
    for (auto next : graph[current]) {
        if (!visited[next]) {
            depthFirstSearch(next);
        }
    }
}


void breadthfirstsearch(int current) {
    queue<int> bfsqueue;
    bfsqueue.emplace(current);
    visited[current] = 1;
    bfs.emplace_back(current);
    while(!bfsqueue.empty()) {
        int parent = bfsqueue.front();
        bfsqueue.pop();
        for (auto &child : graph[parent]) {
            if (!visited[child]) {
                visited[child] = 1;
                bfsqueue.push(child);
                bfs.emplace_back(child);
            }
        }
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int x, y; cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    
    breadthFirstSearch(0);
}