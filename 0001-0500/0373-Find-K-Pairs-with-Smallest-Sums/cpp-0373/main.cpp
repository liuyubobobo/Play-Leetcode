/// Source : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
/// Author : liuyubobobo
/// Time   : 2018-11-09

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Using Priority Queue
/// Time Complexity: O(k * log(len(nums1)))
/// Space Complexity: O(len(nums1))
class Solution {
public:
    vector<vector<int>> kSmallestPairs( vector<int>& nums1, vector<int>& nums2, int k) {

        if(!nums1.size() || !nums2.size())
            return {};

        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i < nums1.size(); i ++)
            pq.push(make_pair(nums1[i] + nums2[0], make_pair(i, 0)));

        while(k-- && !pq.empty()){
            pair<int, int> p = pq.top().second;

            res.push_back({nums1[p.first], nums2[p.second]});
            pq.pop();

            if(p.second + 1 < nums2.size()){
                p.second ++;
                pq.push(make_pair(nums1[p.first] + nums2[p.second], p));
            }
        }

        return res;
    }
};


void print_vec(const vector<vector<int>>& vec){
    for(const vector<int>& p: vec)
        cout << "(" << p[0] << "," << p[1] << ") ";
    cout << endl;
}

int main() {

    vector<int> A1 = {1, 7, 11};
    vector<int> B1 = {2, 4, 6};
    print_vec(Solution().kSmallestPairs(A1, B1, 3));
    // (1, 2) (1, 4) (1, 6)

    vector<int> A2 = {1, 1, 2};
    vector<int> B2 = {1, 2, 3};
    print_vec(Solution().kSmallestPairs(A2, B2, 2));
    // (1, 1) (1, 1)

    vector<int> A3 = {1, 2};
    vector<int> B3 = {3};
    print_vec(Solution().kSmallestPairs(A3, B3, 3));
    // (1, 3) (2, 3)

    vector<int> A4 = {1, 1, 2};
    vector<int> B4 = {1, 2, 3};
    print_vec(Solution().kSmallestPairs(A4, B4, 10));
    // (1, 1) (1, 1) (2, 1) (1, 2) (1, 2) (2, 2) (1, 3) (1, 3) (2, 3)

    vector<int> A5 = {1, 2, 4};
    vector<int> B5 = {-1, 1, 2};
    print_vec(Solution().kSmallestPairs(A5, B5, 100));
    // (1, -1) (2, -1) (1, 1) (4, -1) (2, 1) (1, 2) (2, 2) (4, 1) (4, 2)

    vector<int> A6 = {-10, -4, 0, 0, 6};
    vector<int> B6 = {3, 5, 6, 7, 8, 100};
    print_vec(Solution().kSmallestPairs(A6, B6, 10));
    // (-10, 3) (-10, 5) (-10, 6) (-10, 7) (-10, 8) (-4, 3) (-4, 5) (-4, 6) (-4, 7) (0, 3)

    return 0;
}