    #include <iostream>
using namespace std;

int recur_sum(int n) {
    if (n == 0)  
        return 0;
    else
        return n + recur_sum(n - 1); 
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;  
    cout << "Sum of first " << n << " natural numbers is: " << recur_sum(n) << endl;
    return 0;
}

