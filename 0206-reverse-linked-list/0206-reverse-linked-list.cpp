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
public:
    ListNode* reverseListll(ListNode* head, ListNode* prev, ListNode* cur) {
        if(cur==nullptr) return prev;
        ListNode* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur= tmp;
        return reverseListll(head,prev,cur);

    }
    ListNode* reverseList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* cur = head;
        return reverseListll(head,prev,cur);
        
    }
};