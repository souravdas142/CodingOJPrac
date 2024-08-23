//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    int data = arr[0];
    Node* head = new Node(data);
    Node* tail = head;
    for (int i = 1; i < arr.size(); ++i) {
        data = arr[i];
        tail->next = new Node(data);
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
/*
// structure of the node is as follows

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
  private:
  
   void printList(struct Node* head) {
       cout<<endl;
       while(head!=NULL) {
           cout<<head->data<<" ";
           head = head->next;
       }
       cout<<endl;
   }
  
    struct Node* findMiddle(struct Node* head) {
        
        if(head==NULL || head->next == NULL) return head;
        
        struct Node* slow  = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    struct Node* merge(struct Node* left, struct Node* right) {
        
        struct Node* tmpHead = new struct Node(-1);
        struct Node* newHead = tmpHead;
        int back = -1;
        
        while(left!=NULL && right!=NULL) {
            
            if(left->data > right->data) {
                
                if(back!=right->data) {
                    newHead->next = right;
                    back = right->data;
                    newHead=newHead->next;
                    
                }
                right = right->next;
            }
            else if(left->data < right->data) {
                
                if(back!=left->data) {
                    newHead->next = left;
                    back = left->data;
                    newHead=newHead->next;
                    
                }
                left = left->next;
            }
            else if(left->data == right->data) {
                if(back!=left->data) {
                    newHead->next = left;
                    back = left->data;
                    newHead = newHead->next;
                }
                left = left->next;
                right = right->next;
            }
            
        }
        
        while(left!=NULL) {
            if(left->data != back) {
                back = left->data;
                newHead->next = left;
                newHead = newHead->next;
            }
            left=left->next;
        }
        
        while(right!=NULL) {
            if(back!=right->data) {
                newHead->next = right;
                back=right->data;
                newHead = newHead->next;
            }
            right = right->next;
        }
        
        newHead->next = NULL;
        
        return tmpHead->next;
        
        
    }
    
    struct Node* mergeSort(struct Node* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        struct Node* middle = findMiddle(head);
        
        struct Node* right = middle->next;
        middle->next = NULL;
        struct Node* left = head;
        
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        //printList(left);
        //printList(right);
        
        head = merge(left,right);
        
        return head;
        
        
    }
    
    
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        struct Node* ans = NULL;
        ans = merge(head1,head2);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        Node* first = buildList();

        Node* second = buildList();
        Solution obj;
        Node* head = obj.makeUnion(first, second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends