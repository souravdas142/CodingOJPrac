/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    int size(ListNode* head) {

        if(head==nullptr) return 0;
        return 1+size(head->next);
    
    }

   

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;

        int sz = size(head);
        k = k%sz;

        if(k==0) return head;

        int lftr = sz-k;
        
        ListNode* tmp = head,*point = nullptr;
        while(tmp->next !=nullptr) {
            lftr--;
            if(lftr==0) {
                point = tmp;
            }
            tmp = tmp->next;
        }
        ListNode *tmpHead = point->next;
        point->next = nullptr;
        tmp->next = head;
        head = tmpHead;



        return head;
        
    }
};