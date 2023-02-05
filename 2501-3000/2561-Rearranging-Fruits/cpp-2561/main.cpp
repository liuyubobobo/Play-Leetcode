/// Source : https://leetcode.com/problems/rearranging-fruits/description/
/// Author : liuyubobobo
/// Time   : 2023-02-05

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;


/// Greedy
/// Time Complexity: O(n1logn1 + n2logn2)
/// Space Complexity: O(n1 + n2)
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        int n = basket1.size();
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int e: basket1) pq.push(e);
        for(int e: basket2) pq.push(e);

        vector<int> target;
        while(!pq.empty()){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a != b) return -1;
            target.push_back(a);
        }

        deque<int> change1 = get_change(n, basket1, target);
        deque<int> change2 = get_change(n, basket2, target);

        if(change1.size() != change2.size()) return -1;
        int len = change1.size();
        if(len == 0) return 0;

        long long res = 0, min_cost = min(basket1[0], basket2[0]);
        while(!change1.empty()){
            if(min_cost * 2ll < min(change1.front(), change2.front())){
                res += min_cost * 2ll;
                change1.pop_back(), change2.pop_back();
            }
            else if(change1.front() <= change2.front()){
                res += change1.front();
                change1.pop_front(), change2.pop_back();
            }
            else{
                res += change2.front();
                change2.pop_front(), change1.pop_back();
            }
        }
        return res;
    }

private:
    deque<int> get_change(int n, const vector<int>& a, const vector<int>& b){

        deque<int> res;
        for(int i = 0, j = 0; i < n;){
            if(j == n) res.push_back(a[i ++]);
            else if(a[i] < b[j]) res.push_back(a[i ++]);
            else if(a[i] == b[j]) i ++, j ++;
            else if(a[i] > b[j]) j ++;
        }
        return res;
    }
};


int main() {

    vector<int> basket1_1 = {4, 4, 4, 4, 3};
    vector<int> basket1_2 = {5, 5, 5, 5, 3};
    cout << Solution().minCost(basket1_1, basket1_2) << '\n';
    // 8

    vector<int> basket2_1 = {84,80,43,8,80,88,43,14,100,88};
    vector<int> basket2_2 = {32,32,42,68,68,100,42,84,14,8};
    cout << Solution().minCost(basket2_1, basket2_2) << '\n';
    // 48

    vector<int> basket3_1 = {3350,1104,2004,1577,1365,2088,2249,1948,2621,750,31,2004,1749,3365,3350,3843,3365,1656,3168,3106,2820,3557,1095,2446,573,2464,2172,1326,2712,467,1104,1446,1577,53,2492,2638,1200,2997,3454,2492,1926,1452,2712,446,2997,2820,750,2529,3847,656,272,3873,530,1749,1743,251,3847,31,251,515,2858,126,2491};
    vector<int> basket3_2 = {530,1920,2529,2317,1969,2317,1095,2249,2858,2636,3772,53,3106,2638,1267,1926,2882,515,3772,1969,3454,2446,656,2621,1365,1743,3557,1656,3447,446,1098,1446,467,2636,1088,1098,2882,1088,1326,644,3873,3843,3926,1920,2464,2088,205,1200,1267,272,925,925,2172,2491,3168,644,1452,573,1948,3926,205,126,3447};
    cout << Solution().minCost(basket3_1, basket3_2) << '\n';
    // 837

    return 0;
}
