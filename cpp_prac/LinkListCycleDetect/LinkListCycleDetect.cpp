#include <bits/stdc++.h>
using namespace std;

#define newln "\n"
#define debug(x) cout<<#x<<" is : "<<x<<newln;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

class Node {
    public: 
        ll data=0;
        Node *next=nullptr;
        Node() {}
        Node(ll d, Node* nxt):data(d),next(nxt) {}
        Node(ll d): data(d) {}

};

int factory(Node** head, bool needCycle) {

    int size = 20;
    int cyclePoint = rand()%20;
    
    if(cyclePoint<10)
        cyclePoint+=10;

    if(cyclePoint%15<10)
        cyclePoint+=10;
    
    cout<<"cyclePoint:        "<<cyclePoint<<newln;

    Node* prev=nullptr;
    Node* cyclePointNode = nullptr;
    
    
    for(int i= 0;i<size; i++) {
        
        Node* tmpNode = new Node(20);
        if(*head == nullptr) {
            cout<<__LINE__<<newln;
            *head = tmpNode;
            prev = tmpNode;
        } else {
            
            prev->next = tmpNode;
            prev=prev->next;
            
        }
        if(cyclePoint==i) {
            cyclePointNode = tmpNode;
        }
        
    }
    
    if(needCycle) {
        prev->next = cyclePointNode;
        cout<<__FUNCTION__<<newln;
        debug(cyclePoint);
    }

    return 0;


}

int detectCycle(Node** head) {
    
    Node *Tor=*head,*Here=*head,*meetPoint=nullptr,*firstCyclePoint = nullptr;
    bool isCycleFound = false;
    
    //run Tortoise and here
    while(Tor->next !=  nullptr && (Here->next)->next != nullptr) {
        Here = (Here->next)->next;
        Tor = Tor->next;
        
        cout<<__FUNCTION__<<newln;
        if(Here==Tor) {
            meetPoint = Here;
            isCycleFound = true;
            break;
        }
    }

    if(!isCycleFound) {
        cout<<"Cycle is not detected"<<newln;
        return -1;
    }

    // finding out the first cycle point
    firstCyclePoint = *head;
    int i = 0;
    while(firstCyclePoint!=meetPoint) {
        i++;
        firstCyclePoint = firstCyclePoint->next;
        meetPoint= meetPoint->next;
    }

    cout<<"fist Node of cycle at pos : "<<i<<newln;
    return 0;

}

int main() {

    /// main function doesn't aware of any cycle in linked list

    Node* head=nullptr;
    factory(&head,true);
    detectCycle(&head);

    return 0;


}