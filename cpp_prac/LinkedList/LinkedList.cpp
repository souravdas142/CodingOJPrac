#include<bits/stdc++.h>
using namespace std;
#define newln "\n"

class node {
    public:
        int x;
        node* nxt = nullptr;
        node(int param,node* ptr):x(param), nxt(ptr) {}
        node(node* ptr):nxt(ptr) {}
        node() {}

};

void push_back(node** nd,int data) {

    node* tmp = new node(data,nullptr);
    if(!(*nd)) {
        *nd = tmp;
        return;
    }
    node* iter = *nd;
    while(iter->nxt) {
        iter = iter->nxt;
    }
    iter->nxt = tmp;
    
}

void push_front(node** nd,int data) {
    node* tmp = new node(data,*nd);
    *nd = tmp;

}

void insert(node** head, int data, int pos) {
    
    if(!(*head)) {
       return; 
    }
    node* iter = *head;
    node* prev = nullptr;
    int count = 0;
    while(iter->nxt) {
        prev = iter;
        iter = iter->nxt;
        count++;
        if(count==pos) {

            node* tmp = new node(data,iter->nxt);
            prev->nxt = tmp;
            break;
        }
        
    }
    if(count!=pos) {
        cout<<pos<<" not available "<<endl;
        return;
    }
    
}

void print(node* head) {
    node *tmp = head;
    while(tmp!=nullptr) {
        cout<<tmp->x<<" ";
        tmp = tmp->nxt;
    }
    cout<<endl;
}

void usage() {
    cout<<newln<<"press 0  for print"<<newln;
    cout<<"press 1 for push_back"<<newln;
    cout<<"press 2 for push_front"<<newln;
    cout<<"press 3 for insert"<<newln;
    cout<<"press 4 for pop_back"<<newln;
    cout<<"press 5 for pop_front"<<newln;
    cout<<"press 6 for delete"<<newln<<newln;
}

int main () {
    node* head = nullptr;
    node *iter = head;
    int size;
    cin>>size;
    while(size--) {
        
        int x; cin>>x;
        node* tmp = new node(x,nullptr);
        if (!head){ 
            head = tmp;
            iter = tmp;
        } else {
            iter->nxt=tmp;
            iter = iter->nxt;
        }

        
    }
    print(head);
    
    int data,pos;
    do {
        usage();
        cout<<"Do you want to do something? : ";
        int option; cin>>option;
        switch(option) {
            case 1:
                cout<<"Enter data: ";
                cin>>data;
                push_back(&head,data);
                break;
                
            case 2:
                cout<<"Enter data: ";
                cin>>data;
                push_front(&head,data);
                break;
            case 3:
                cout<<"Enter data & Pos: ";
                cin>>data>>pos;

                insert(&head,data,pos);
                break;
            //case 4:
            //    pop_back();
            //    break;
            //case 5:
            //    pop_front();
            //    break;
            //case 6:
            //    delete();
            //    break;
            case 0:
                print(head);
                break;
            default:
                usage();
                break;
            
        }
    } while(true);

    return 0;
}