class KthLargest {
private:
    int kth;
    priority_queue<int, vector<int>, greater<int>> heap;

public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;

        for (int i = 0; i < nums.size(); i++) {
            if (heap.size() < k) {
                heap.push(nums[i]);
            }
            else if (heap.top() < nums[i]) {
                heap.pop(); 
                heap.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > kth) heap.pop();
 
        return heap.top();
    }
};
