class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    void push_on_Stack(queue<int>& qp1, queue<int>& qp2, int x) {
        if(qp1.empty() && qp2.empty()) qp1.push(x);
        if(qp1.empty()) {
            push_on_Stack(qp2,qp1,x);
            return;
        }
        qp1.push(x);
    }
    int pop_from_stack(queue<int>& qp1, queue<int>& qp2) {
        if(qp1.empty() && qp2.empty()) return -1;
        if(qp1.empty()) {
            return pop_from_stack(qp2,qp1);
        }
        while(qp1.size()!=1) {
            qp2.push(qp1.front());
            qp1.pop();
        }
        int x = qp1.front();
        qp1.pop();
        return x;
    }
    int top_from_stack(queue<int>& qp1, queue<int>& qp2) {
        if(qp1.empty() && qp2.empty()) return -1;
        if(qp1.empty()) {
            return top_from_stack(qp2,qp1);
        }
        return qp1.back();
    }
    MyStack() {
        cout<<"Stack INTIALIZED"<<endl;
    }
    
    void push(int x) {
        push_on_Stack(q1,q2,x);
    }
    
    int pop() {
        return pop_from_stack(q1,q2);
        
    }
    
    int top() {
        return top_from_stack(q1,q2);
    }
    
    bool empty() {
       if(q1.empty() && q2.empty()) {
            return true;
       }

       return false;
       
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */