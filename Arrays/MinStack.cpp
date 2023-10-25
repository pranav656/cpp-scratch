// LC155 - Min Stack
// The minimum element must be retreived 
// in constant time. 
// You could solve this problem with two data structures.
// one to track the minimum values and one to track the
// actual stacks. In the min stack, you track the minimum
// value upto the given point. This can also be done with 
// a single data structure containing a stack/array of pairs
class MinStack {

public:
    stack<int> st, min_st;

    MinStack() {
        
    }
    
    void push(int val) {
     st.push(val);
     if(!min_st.empty())
     {
         // push the minimum element into
         // the stack
         val = min(val, min_st.top());
     } 
     min_st.push(val);
    }
    
    void pop() {
        // pop both the stacks
        // to maintain consistency of mins
        min_st.pop();
        st.pop();
    }
    
    int top() {
        // return the actual top
        return st.top();
    }
    
    int getMin() {
        // return the minium val
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
