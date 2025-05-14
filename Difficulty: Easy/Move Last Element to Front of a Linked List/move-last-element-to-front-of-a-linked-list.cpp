//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    Node *moveToFront(Node *head) {
        // code here
        if(head == nullptr || head->next == nullptr) return head;
        
        Node* prev = nullptr;
        Node* cur = head;
        
        while(cur->next!=nullptr) {
            prev = cur;
            cur = cur->next;
        }
        
        Node* tmp = prev->next;
        prev->next = nullptr;
        tmp->next = head;
        head = tmp;
        
        return head;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }
        Solution ob;
        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        head = ob.moveToFront(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends