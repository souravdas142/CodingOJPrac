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
    ListNode *deleteFirst(ListNode* head,int actpos) {
        if(head==nullptr) return nullptr;
        return head->next;
    }

    void deleteLast(ListNode* head,int actpos) {
        if(head==nullptr) return;
        ListNode* tmp = head;
        while(tmp->next->next!=nullptr) tmp= tmp->next;
        tmp->next = nullptr;
        
    }

    void deleteInterm(ListNode* head,int actpos) {
        ListNode* tmp = head,*prev = nullptr;
        if(head==nullptr) return ;

        int counter = 1;
        while(tmp!=nullptr) {
            counter++;
            
            prev = tmp;
            tmp = tmp->next;
            if(counter==actpos) break;
        }
        cout<<prev->val<<endl;
        prev->next = prev->next->next;
        
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int sz = size(head);
        int actpos = sz-n+1;
        ListNode* newHd = head;
        if(actpos==1) {
            newHd = deleteFirst(head,actpos);
        }
        else if(actpos==sz) {
            deleteLast(head,actpos);
        }
        else {
            deleteInterm(head,actpos);
        }

        return newHd;
        
    }
};