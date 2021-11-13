#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class KthLargest {
public:
    KthLargest(int k_, vector<int> &nums) {
        k = k_;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */