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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head==nullptr || head->next == nullptr || left==right ) return head;

        ListNode* leftnd = head, *preleft=nullptr;
        int cnt = 0;
        while(leftnd!=nullptr) {
            cnt++;
            if(left==cnt)break;
            preleft = leftnd;
            leftnd=leftnd->next;
        }
        cout<<"count = "<<cnt<<"leftnd = "<<leftnd->val<<endl;

        ListNode *cur = leftnd;
        ListNode *prev = nullptr;
        while(cur!=nullptr) {
            ListNode *bak = cur->next;
            cur->next = prev;
            prev = cur;
            cur = bak;
            if(cnt==right) break;
            cnt++;
        }
        leftnd->next = cur;
        if(preleft!=nullptr && cur==nullptr) preleft->next = prev;
        else if(preleft!=nullptr) preleft->next = prev;
        else if(cur == nullptr) head = prev;
        else if(preleft==nullptr) head = prev;

        return head;

        
    }
};