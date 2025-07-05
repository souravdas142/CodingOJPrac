/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        auto comp = [](Node* a, Node*b)->bool {
            return a->data>=b->data;
        };
        priority_queue<Node*, vector<Node*>,decltype(comp)> pq(comp);
        
        for(auto nd:arr) pq.push(nd);
        
        Node* head = new Node(0);
        Node* ans = head;
        
        while(!pq.empty()) {
            Node* tmp = pq.top();
            //cout<<tmp->data<<endl;
            pq.pop();
            head->next = tmp;
            tmp = tmp->next;
            head = head->next;
            head->next = nullptr;
            if(tmp)
                pq.push(tmp);
        }
        
        return ans->next;
    }
};