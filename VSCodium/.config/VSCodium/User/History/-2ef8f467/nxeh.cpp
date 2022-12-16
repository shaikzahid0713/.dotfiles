#include <iostream>
#include <vector>


using namespace std;

int vertices, edges;
vector<vector<int>> graph(10);
vector<int> visited(10);
vector<int> distance(10);
vector<int> bfs;
vector<int> dfs;

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    

int main() {
    cin >> vertices >> edges;

    for (int i = 0; i < edges; i++) {
        int x, y; 
        cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    
}

