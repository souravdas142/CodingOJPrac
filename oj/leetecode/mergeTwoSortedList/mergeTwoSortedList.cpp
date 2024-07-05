#include <bits/stdc++.h>
using namespace std;

class ListNode {

    public:
        int val;
        ListNode* next;

        ListNode(): val(0), next(nullptr) {}
        ListNode(int v): val(v), next(nullptr) {}
        ListNode(int v,ListNode* ptr): val(v), next(ptr) {}



};

class Solution {

    public:
        ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
            
            if(list1==nullptr) return list2;
            if(list2 == nullptr) return list1;

            if(list1 == nullptr || list2 == nullptr) return nullptr;
            
            ListNode* head = nullptr,*ptr = nullptr;
            
            while(list1 != nullptr && list2 != nullptr) {
                
                if(list1->val>list2->val) {
                    ListNode* tmp = new ListNode(list1->val,nullptr);
                    if(head==nullptr) {
                        head = tmp;
                        ptr = head;
                    }
                    else {
                        ptr->next = tmp;
                        ptr=ptr->next;
                    }
                    list1=list1->next;
                }
                else if(list2->val>list1->val) {

                    ListNode* tmp = new ListNode(list2->val,nullptr);
                    if(head==nullptr) {
                        head = tmp;
                        ptr = head;
                    }
                    else {
                        ptr->next = tmp;
                        ptr=ptr->next;
                    }
                    list2=list2->next;
                }
                else if(list2->val ==list1->val) {
                    ListNode *tmp1 = new ListNode(list1->val,nullptr);
                    ListNode *tmp2 = new ListNode(list2->val,nullptr);
                    tmp1->next=tmp2;
                    if(head == nullptr) {
                        head = tmp1;
                        ptr = tmp2;
                    }
                    else {
                        ptr->next = tmp2;
                        ptr = ptr->next;
                    }
                    list2=list2->next;
                    list1=list1->next;

                }
                
                

                
            }
            
            while(list1 != nullptr) {
                ListNode* tmp = new ListNode(list1->val,nullptr);
                ptr->next = tmp;
                ptr=ptr->next;
                list1=list1->next;
            }
            
            while(list2 != nullptr) {
                ListNode *tmp = new ListNode(list2->val,nullptr);
                ptr->next = tmp;
                ptr = ptr->next;
                list2=list2->next;

            }


            return head;
        }



};