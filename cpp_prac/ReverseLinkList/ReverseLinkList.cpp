#include<bits/stdc++.h>
using namespace std;

#define newln "\n"
#define debug(x) cout<<#x<<" is: "<<x<<newln
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);

class Node_t {
    public:
        int data;
        Node_t* nextNode=nullptr;
        Node_t(int x,Node_t* iter):data(x), nextNode(iter) {}
};

void print(Node_t* head) {
    Node_t* ptr = head; 
    while(ptr!=nullptr) {
        cout<<" data is: "<<ptr->data<<" ";
        
        ptr = ptr->nextNode;
    }
}

int main() {
    fio;
    
    Node_t* head = nullptr,*iter = nullptr;
    int size; cin>>size;
    while(size--) {

        int dat; cin>>dat;
        Node_t* ptr = new Node_t(dat,nullptr);
        if (head==nullptr) {
            head = ptr;
            iter = ptr;
        }
        else {
            iter->nextNode = ptr;
            iter=iter->nextNode;
        }

    }

    print(head);

    return 0;
}