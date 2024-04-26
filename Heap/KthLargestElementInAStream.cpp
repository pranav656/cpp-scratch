// LC703 - Kth Largest element in a stream
// minHeap approach: space complexity O(k), timecomplexity: O(nlogk)
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for(int i = 0; i<nums.size(); i++)
        {
            minHeap.push(nums[i]);
        }
        // keep only k elements in the minheap
        while(minHeap.size() > m_k)
        {
            minHeap.pop();
        }
    }
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > m_k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
private: 
    int m_k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};
