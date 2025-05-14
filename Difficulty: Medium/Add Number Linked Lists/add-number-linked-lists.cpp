//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    void reversell(Node** num1) {
        
        if((*num1)==nullptr || (*num1)->next == nullptr) return;
        
        Node* prev = nullptr;
        Node* cur = *num1;
        
        while(cur!=nullptr) {
            Node* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        *num1 = prev;
        
    }
    
    void removeLeadingZeros(Node** num1) {
        if((*num1)==nullptr || (*num1)->next==nullptr) return;
        
        
        Node* cur = *num1;
        Node* prev = nullptr;
        
        while(cur!=nullptr) {
            if(cur->data>=1 && cur->data<=9) {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if(cur == nullptr) {
            *num1 = prev;
            return;
        }
        *num1 = cur;
        
        
    }
  
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        
        removeLeadingZeros(&num1);
        removeLeadingZeros(&num2);
        
       
        
        reversell(&num1);
        reversell(&num2);
        
        
        Node* newNode = new Node(0);
        Node* prev3 = newNode;
        
        Node* prev1 = nullptr, *prev2 = nullptr;
        Node* cur1 = num1, *cur2 = num2;
        int c = 0;
        
        while(cur1!=nullptr && cur2!=nullptr) {
            int sum = cur1->data + cur2->data + c;
            c = sum/10;
            sum = sum%10;
            
            
            prev3->next = new Node(sum);
            prev3 = prev3->next;
            
            
            prev1 = cur1;
            prev2 = cur2;
            cur1 = cur1->next;
            cur2=cur2->next;
        }
        
        while(cur1!=nullptr) {
            int sum = cur1->data+c;
            c = sum/10;
            sum = sum%10;
            prev3->next = new Node(sum);
            prev3 = prev3->next;
            cur1=cur1->next;
        }
        
        while(cur2!=nullptr) {
            int sum = cur2->data+c;
            c = sum/10;
            sum = sum%10;
            prev3->next = new Node(sum);
            prev3 = prev3->next;
            cur2=cur2->next;
        }
        
        if(c) {
            prev3->next = new Node(c);
        }
        
        
        //reversell(&num1);
        //reversell(&num2);
        
        Node* ans = newNode->next;
        reversell(&ans);
        return ans;
        
        
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends