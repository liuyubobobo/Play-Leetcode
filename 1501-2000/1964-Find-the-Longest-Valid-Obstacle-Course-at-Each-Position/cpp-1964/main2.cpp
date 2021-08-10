/// Source : https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>

using namespace std;


/// LIS
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

        vector<int> lis = {obstacles[0]};
        vector<int> res = {1};
        for(int i = 1; i < obstacles.size(); i ++){
            vector<int>::iterator iter = upper_bound(lis.begin(), lis.end(), obstacles[i]);
            int k = iter - lis.begin();
            if(iter == lis.end())
                lis.push_back(obstacles[i]);
            else
                lis[k] = obstacles[i];
            res.push_back(k + 1);
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << endl;
}

int main() {

    vector<int> nums1 = {1,2,3,2};
    print_vec(Solution().longestObstacleCourseAtEachPosition(nums1));
    // 1 2 3 3

    vector<int> nums2 = {2,2,1};
    print_vec(Solution().longestObstacleCourseAtEachPosition(nums2));
    // 1 2 1

    vector<int> nums3 = {3,1,5,6,4,2};
    print_vec(Solution().longestObstacleCourseAtEachPosition(nums3));
    // 1,1,2,3,2,2

    return 0;
}
