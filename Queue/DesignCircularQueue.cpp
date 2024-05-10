// LC 622 - Design circular queue
typedef struct Node
{
    public:
        int val;
        Node *next;
        Node(int _val)
        {
            val = _val;
            next = nullptr;
        }
};

class MyCircularQueue {
    private:
    int m_size = 0, m_curr_size = 0;
    Node* front = nullptr, *rear = nullptr;
public:
    MyCircularQueue(int k) {
        m_size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        Node* newNode = new Node(value);
        // When no nodes are present,
        // front and rear are the same
        if(!front)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        m_curr_size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        Node* tmp = front;
        front = front->next;
        delete tmp;
        m_curr_size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return front->val;
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return (m_curr_size == 0);
    }
    
    bool isFull() {
        return (m_curr_size == m_size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
