#include <bits/stdc++.h>
using namespace std;
#define debug(y) cout<<__LINE__<<" : "<<#y<<" = "<<y<<endl
/**
 * Definition for singly-linked list.
 */
 class ListNode {
	 public:
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}

		static ListNode* swapPairs(ListNode* head) {

		    ListNode *fast = head->next, *slow = head;
		    bool hd = false;
			ListNode* prevtmp = NULL;
		    
		    while(fast!=nullptr && fast->next !=nullptr) {
		        
		        ListNode *tmp = fast->next;
		        fast->next = slow;
		        slow->next = tmp;
				if(prevtmp!=NULL)
					prevtmp->next = fast;
				prevtmp = slow;
			
		        if(hd==false) {
		            hd=true;
		            head = fast;
		        }
		        slow = slow->next;
		        fast=slow->next;

		    }

			if(slow!=NULL && fast !=NULL) {

				fast->next = slow;
				slow->next = NULL;
				if(prevtmp!=NULL)
					prevtmp->next = fast;
				if(hd==false) head = fast;
			}

		    
		    return head;
		    
		    
		}

		static void printNodes(ListNode* head) {

			ListNode *tmp = head;

			cout<<"\nPrintNodes---"<<endl;
			while(tmp) {
				cout<<tmp->val<<" ";
				tmp=tmp->next;
			}
			cout<<"\nPrintNodes---"<<endl;

		}

 };
 

int main () {

	ListNode* head = new ListNode(1);
	//head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	//head->next->next->next->next->next = new ListNode(6);


	ListNode::printNodes(head);

	head = ListNode::swapPairs(head);

	ListNode::printNodes(head);

	return 0;
}
