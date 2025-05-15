//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        
                
        Node* prev = nullptr;
        Node* cur = head;
        
        while(cur->next!=head) {
            Node* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        head->next = cur;
        cur->next = prev;
        head = cur;
        return head;
        
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        
        Node* cur = head;
        Node* prev = nullptr;
        bool is_found = false;
        while(cur->next!=head) {
            
            if(cur->data==key) {
                is_found = true;
                break;
            }
            prev = cur;
            cur=cur->next;
        }
        if(cur->data==key) is_found = true;
        
        
        if(!is_found ) return head;
        
        if(prev==nullptr) { // first Node
           
            Node* tmp = head;
            while(tmp->next!=head) {
                tmp=tmp->next;
            }
            tmp->next = head->next;
            head = head->next;
            delete cur;
        }
        
        else if(cur->next==head) { // last node
             Node* tmp = head;
             Node* prev2 = nullptr;
            while(tmp->next!=head) {
                prev2 = tmp;
                tmp=tmp->next;
            }
            prev2->next = head;
            delete tmp;
        }
        else {
            prev->next = cur->next;
            delete cur;
        }
        

        return head;
        
            
        
        // code here
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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends