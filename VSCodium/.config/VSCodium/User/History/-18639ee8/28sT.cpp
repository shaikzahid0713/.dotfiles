// AND, OR & XOR OPERATORS

#include <iostream>
#include <vector>


using namespace std;

bool isPowerOFTwo(unsigned int x) {
    return (!(x & (x - 1)));
}


int main() {

    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt", "w", stderr);
    
    int x, y; 
    cin >> x >> y;

    int andOperator = x & y;
    cout << "AND OPERATION " << andOperator << "\n";

    int orOperator = x | y;
    cout << "OR OPERATION " << orOperator << "\n";

    int xorOperator = x ^ y;
    cout << "XOR OPERATION " << xorOperator << "\n";

    cout << endl; 
    
    int rightShift =  x >> 1;
    cout << "Right Shift Operation " << rightShift << "\n";

    int leftShift = x << 1;
    cout << "Left Shift Operation " << leftShift << "\n";
    

    unsigned int z; cin >> z;
    cout << "Z - " << z << "\n";
    int negation = (~z);
    cout << "Negation Operation " << negation << "\n";
   
}