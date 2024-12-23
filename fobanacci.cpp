#include <iostream>
using namespace std;

int fibonacci(int n) {
    
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;

    cout << "Enter a number for Fibonacci calculation: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    cout << "F(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}
