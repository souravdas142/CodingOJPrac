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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = nullptr, *ans = nullptr;
        int carry = 0;

        while(l1 && l2) {

            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            if(l3==nullptr) {
                l3 = new ListNode(sum);
                ans = l3;
                

            } else {
                l3->next = new ListNode(sum);
                l3 = l3->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {

            int sum = l1->val+carry;
            carry = sum/10;
            sum = sum%10;

            l3->next = new ListNode(sum);
            l3 = l3->next;

            l1=l1->next;
        }

        while(l2) {

            int sum = l2->val+carry;
            carry = sum/10;
            sum = sum%10;

            l3->next = new ListNode(sum);
            l3 = l3->next;

            l2=l2->next;
        }

        if(carry) {
            l3->next = new ListNode(carry);
        }



        return ans;
    }
};