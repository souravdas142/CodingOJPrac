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
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head, *fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void print(ListNode* head) {
        cout<<endl;
        while(head!=nullptr) {
            cout<<head->val<<" ";
            head = head->next;

        }
        cout<<endl;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* tmp = dummyNode;
        while(left!=nullptr && right!=nullptr) {
            if(left->val > right->val) {
                tmp->next = right;
                tmp = tmp->next;
                right = right->next;
            }
            else {
                tmp->next = left;
                tmp = tmp->next;
                left = left->next;
            }

            
            
        }
        if(left!=nullptr) tmp->next = left;
        if(right!=nullptr) tmp->next = right;
        print(dummyNode->next);
        return dummyNode->next;
    }
public:
    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next == nullptr) return head;

        ListNode* mid = findMid(head);
        ListNode* right= mid->next;
        mid->next = nullptr;
        ListNode* left = head;
       // print(left);
        //print(right);
        left = sortList(left);
        right = sortList(right);
        head = merge(left,right);

        return head;
        
    }
};