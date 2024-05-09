// LC232 - Implement Queue using Stacks
// The The key idea is to realize that popping
// elements from one stack and inserting into the
// the second stack can lead to FIFO ordering. 
// Whenever you want to pop elements or peek,
// we can pop elements from one stack and insert
// into the other.
class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                int x = stack1.top();
                stack1.pop();
                stack2.push(x);
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }
    
    int peek() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                int x = stack1.top();
                stack1.pop();
                stack2.push(x);
            }
        }
        return stack2.top();
    }
    
    bool empty() {
        return max(stack1.size(), stack2.size()) == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
