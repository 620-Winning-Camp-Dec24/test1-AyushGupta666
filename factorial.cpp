#include <iostream>
using namespace std;

int factorial(int n) {
    
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;

    
    cout << "Enter a number : ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    cout << n << "! = " << factorial(n) << endl;

    return 0;
}
