class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        while (heap.size() > 1) {
            int y = heap.top(); heap.pop();
            cout << heap.size() << endl;
            int x = heap.top(); heap.pop();
            cout << heap.size();
            if (x < y) {
                y = y - x;
                heap.push(y);
            }
        }
        if (heap.size() == 0) return 0;
        return heap.top();
    }
};
/*
        [2,2]
         y x

    Input: stones = [2,3,6,2,4],    Output: 1 (remaining stone)
    [6,4,3,2,2]
     y
       x
    1) 4 < 6: yes, y = 2 [3,2,2,2]
                          y x
    2) 2 < 3: yes, y = 1 [2,2,1]
                          y x
    3) 2 == 2            [1]

*/





