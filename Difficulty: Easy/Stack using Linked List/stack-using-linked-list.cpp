class MyStack {
  private:
    StackNode *top;
    StackNode *head;
    

  public:
    void push(int x) {
        // code here
        StackNode *node = new StackNode(x);
        node->next= head;
        head = node;
        
    }

    int pop() {
        
        // code here
        if(head == nullptr) return -1;
        StackNode *del = head;
        head = head->next;
        int x = del->data;
        delete del;
        return x;
       
    }

    MyStack() { 
        top = NULL;
        head = nullptr;
        
    }
};