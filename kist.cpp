#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = nullptr, *curr = slow;
    while (curr) {
        ListNode* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    
    ListNode* left = head, *right = prev;
    while (right) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    
    return true;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;
    
    if (n == 0) {
        cout << "List is empty." << endl;
        return 0;
    }
    
    cout << "Enter the values for the linked list: ";
    int value;
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        cin >> value;
        temp->next = new ListNode(value);
        temp = temp->next;
    }

    cout << (isPalindrome(head) ? "true" : "false") << endl;
    return 0;
}
