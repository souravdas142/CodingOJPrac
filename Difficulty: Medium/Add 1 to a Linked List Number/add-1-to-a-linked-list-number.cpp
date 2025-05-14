//{ Driver Code Starts
// Initial template for C++

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

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    void reversell(Node** head) {
        if((*head) == nullptr || (*head)->next == nullptr) return;
        Node* prev = nullptr;
        Node* cur = *head;
        while(cur!=nullptr) {
            Node* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        *head = prev;
    }
    
    
    Node* addOne(Node* head) {
        // Your Code here
         reversell(&head);
        // return head of list after adding one
        
        int c = 1;
        Node* cur = head;
        Node* prev = nullptr;
        while(cur!=nullptr) {
            int sum = cur->data+c;
            c = sum/10;
            sum = sum%10;
            cur->data = sum;
            prev = cur;
            cur = cur->next;
        }
        if(c) {
            prev->next = new Node(c);
        }
        
        reversell(&head);
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

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends