//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// } Driver Code Ends

/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        unordered_map<int,bool> look;
        if(head == nullptr || head->next == nullptr) return head;
        
        Node* prev = head;
        Node* cur = head->next;
        look.insert({prev->data,true});
        
        while(cur!=nullptr) {
            if(look.find(cur->data)==look.end()) {
                prev->next = cur;
                prev = prev->next;
            }
            look.insert({cur->data,true});
            cur = cur->next;
            
        }
        
        prev->next = nullptr;
        
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
            cout << "empty" << endl;
            continue;
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        for (size_t i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        printList(result);
    }

    return 0;
}

// } Driver Code Ends