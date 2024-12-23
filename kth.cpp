#include <iostream>
using namespace std;

char findKthCharacter(int k) {
    string word = "a"; 
    while (word.size() < k) {
        string next_str = "";
        for (char c : word) {
            next_str += (c == 'z' ? 'a' : c + 1); 
        }
        word += next_str; 
    }
    return word[k - 1];  
}

int main() {
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    
    if (k <= 0) {
        cout << "Invalid input! k should be a positive integer." << endl;
        return 0;
    }
    
    cout << "The " << k << "-th character is: " << findKthCharacter(k) << endl;
    return 0;
}
