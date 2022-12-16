#include <iostream>
#include <vector>


using namespace std;

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    
}

int vertices, edges;
vector<vector<int>> graph(10);
vector<int> visited(10);
vector<int> distance(10);
vector<int> bfs;
vector<int> dfs;

