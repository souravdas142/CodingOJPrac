#include<bits/stdc++.h>
using namespace std;
#define newln "\n"

class ListNode {
    public:
        int value;
        ListNode* next;
        ListNode(int param,ListNode* ptr):value(param), next(ptr) {}
        ListNode(int param):value(param) {}
        ListNode(ListNode* ptr):next(ptr) {}
        ListNode():value(0),next(nullptr) {}

        static ListNode* convert2ll(const vector<int>& arr) {
            int cnt = 0;
            ListNode* prev = nullptr;
            ListNode* head = nullptr;
            for(int a:arr) {
                cnt++;
                ListNode *tmp = new ListNode(a);
                if(cnt == 1) {
                    head = tmp;
                }
                if(cnt>1) {
                    prev->next = tmp;
                }
                prev = tmp;
            }
            return head;
        }

        static void print(ListNode* head) {
            ListNode *tmp = head;
            cout<<newln;
            while(tmp!=nullptr) {
                cout<<tmp->value<<" ";
                tmp=tmp->next;
            }
            cout<<newln;
        }
        
        static ListNode* deleteNodeByPos(ListNode* head, int pos) {
           //if there is no node 
            if(head==nullptr) return head;
            // if first Node
            if(pos == 1) {
                ListNode* tmp = head;
                head=head->next;
                delete tmp;
                return head;

            }
            
            ListNode *tmp = head, *prev = nullptr;

            int cnt = 0;
            while(tmp!=nullptr) {

                cnt++;
                if(cnt==pos) {
                    
                    prev->next = prev->next->next;
                    delete tmp;
                    return head;

                }
                prev = tmp;
                tmp=tmp->next;
            }
            
            return head;
            
            
        }
        static ListNode* deleteNodeByVal(ListNode* head, int val) {
           //if there is no node 
            if(head==nullptr) return head;
            // if first Node
            if(head->value == val) {
                ListNode* tmp = head;
                head=head->next;
                delete tmp;
                return head;

            }
            
            ListNode *tmp = head, *prev = nullptr;

            while(tmp!=nullptr) {

                if(tmp->value==val) {
                    
                    prev->next = prev->next->next;
                    delete tmp;
                    return head;

                }
                prev = tmp;
                tmp=tmp->next;
            }
            
            return head;
            
            
        }
        
        static ListNode* insertNode(ListNode* head,int pos, int val) {
            
            
            if(pos==1 || head==nullptr) {
                ListNode* tmp = new ListNode(val,head);
                return tmp;
            }
            
            ListNode *tmp = head, *prev = nullptr;
            int cnt  = 0;
            
            while(tmp!=nullptr) {
                cnt++;
                if(cnt==pos-1) {
                    ListNode *nd = new ListNode(val,tmp->next);
                    tmp->next= nd;
                    return head;
                }
                prev = tmp;
                tmp=tmp->next;
            }

            return head;
            
        }
        
        static ListNode* reversell(ListNode* head) {

            ListNode *prev = nullptr, *cur = head;

            while(cur!=nullptr) {
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;

            }
            head = prev;
            return head;
        }

};



int main() {


    vector<int> arr = {3,2,6,4,5};
    ListNode* head = ListNode::convert2ll(arr);
    ListNode::print(head);
    //ListNode *dHead = ListNode::deleteNodeByPos(head,6);
    //ListNode *dHead = ListNode::deleteNodeByVal(head,5);
    ListNode *iHead = ListNode::insertNode(head,4,5);
    ListNode::print(iHead);
    ListNode *hd = ListNode::reversell(iHead);
    ListNode::print(hd);
    return 0;

}