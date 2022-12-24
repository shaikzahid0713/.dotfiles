#include <iostream>
#include <vector>

#define bts(jimin) cerr << #jimin << " -> "; loveYourself(jimin); cerr << endl;
void loveYourself(int jimin)    { cerr << jimin; }
template <class T> void loveYourself(vector <T> v) { 
    cerr << " [ ";
    for (T suga : v) {
        loveYourself(suga);
        cerr << " ";
    }
    cerr << "]";
}

using namespace std;

vector<int> primeSeive;


void seiveOfEratosthenes(int n) {
    vector<bool> isPrime(n, 1);
    
    for (int i = 2; i * i <= n; i++) {
        if (primeSeive(i)) {
            for (int j = i * 2; j <)
        }
    }
}


int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);

    int n; cin >> n;
    
    seiveOfEratosthenes(n);
    
}