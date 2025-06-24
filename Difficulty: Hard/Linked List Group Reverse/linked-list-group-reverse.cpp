/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

void printChain(Node* node) {
    cout<<endl;
    while(node!=nullptr) {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}

class Solution {
  public:
            Node *reverseKGroup(Node *head, int k) {
        // code here
            if(head == nullptr) return head;
        
            int len = 0;
            Node* curHead = head;
            while(curHead!=nullptr) {
                len++;
                curHead = curHead->next;
            }
        
            curHead = head;
            Node *prevTail = head,  *curTail = head;
            int grpCnt = 0;
            int cnt = 0;
            Node* prev = nullptr;
        
            if((grpCnt*k)+k>len) {

                    // TODO: do something and then break;
                    return head;
            }
        
            while(curHead!=nullptr) {




                Node* temp = curHead->next;
                curHead->next = prev;
                prev = curHead;
                curHead = temp;
                cnt++;
            
                if(cnt==k) {

                    grpCnt++;

                    //curTail = curHead;

                    if(grpCnt<=1) {
                        head = prev;

                    }
                    else {
                        prevTail->next = prev;
                        prevTail = curTail;
                    }
                    //printLL(curTail);
                    curTail = curHead;
                    prev = nullptr;


                    cnt = 0;
                }


                
            }
            if(len%k!=0)
                prevTail->next = prev;
            if(k>len) return prev;
            return head;
        }
};