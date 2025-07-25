// https://leetcode.com/problems/last-stone-weight/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone : stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a - b != 0) pq.push(a - b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};