#include <iostream>
#include <vector>
#include <unordered_set>
#include <deque>
#include <priority_queue>


using namespace std;

void run_tests() {
    int n;
    cin >> n;
    deque<int> temp;
    priority_queue<int> pq;
    while (n-- > 0) {
        int x; cin >> x;
        temp.emplace_front(x);
        pq.emplace(x);
    }
    
    cout << "DEQUE: \n";
    while(!temp.empty()) {
        cout << temp.front() << "\n";
        temp.pop_front();
        cout << temp.back() << "\n";
        temp.pop_back();
    }
    
    cout << "Priority Queue: \n";
    while (!pq.empty()) {
        cout << pw
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("../../input.txt",  "r", stdin);
        freopen("../../output.txt", "w", stdout);
        freopen("../../error.txt",  "w", stderr);
    #endif

    int tests = 1;
    // cin >> tests;

    while(tests-- > 0) {
         run_tests();
    }

}

/*

*/