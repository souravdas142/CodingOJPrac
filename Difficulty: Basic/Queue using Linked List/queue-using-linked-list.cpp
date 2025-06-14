/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        if(rear==nullptr) {
            rear = new QueueNode(x);
            front = rear;
            return;
        }
        rear->next = new QueueNode(x);
        rear = rear->next;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code
        if(front==nullptr) return -1;
        if(front==rear) {
            rear = nullptr;
        }
        QueueNode* tmp = front;
        front = front->next;
        int x = tmp->data;
        delete tmp;
        return x;
}
