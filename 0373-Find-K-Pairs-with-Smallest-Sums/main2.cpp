/// Source : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
/// Author : liuyubobobo
/// Time   : 2018-11-10

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Using Binary Search
/// Time Complexity: O(nums1 * log(nums2) * log(maxnum))
/// Space Complexity: O(1)
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(
            vector<int>& nums1, vector<int>& nums2, int k) {

        if(nums1.size() == 0 || nums2.size() == 0)
            return {};

        int low = nums1[0] + nums2[0], high = nums1.back() + nums2.back();
        while(low != high){
            int mid = low + high;
            if(mid >= 0 || mid % 2 == 0) mid /= 2;
            else mid = (mid - 1) / 2; // very tricky here!
                                      // since C++ doesn't make floor division for minus number!

            int num = get_num(nums1, nums2, mid);
            if(num >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return get_res(nums1, nums2, low, k);
    }

private:
    vector<pair<int, int>> get_res(const vector<int>& nums1, const vector<int>& nums2, int sum, int k){

        vector<pair<int, int>> res;
        for(int e1: nums1){
            for(int e2: nums2)
                if(e1 + e2 < sum)
                    res.push_back(make_pair(e1, e2));
                else
                    break;
        }

        sort(res.begin(), res.end(),
             [nums1, nums2](const pair<int, int>& p1, const pair<int, int>& p2){

                 int sum1 = p1.first + p1.second;
                 int sum2 = p2.first + p2.second;
                 if(sum1 != sum2)
                     return sum1 < sum2;
                 return p1 < p2;
             });

        if(res.size() > k){
            while(res.size() > k)
                res.pop_back();
        }
        else
            for(int e1: nums1){
                int l = lower_bound(nums2.begin(), nums2.end(), sum - e1) - nums2.begin();
                if(l >= 0 && l < nums2.size())
                    while(l < nums2.size() && nums2[l] == sum - e1 && res.size() < k)
                        res.push_back(make_pair(e1, nums2[l++]));
                if(res.size() == k)
                    break;
            }

        return res;
    }

    int get_num(const vector<int>& nums1, const vector<int>& nums2, int sum){

        int num = 0;
        for(int e: nums1)
            if(e + nums2[0] <= sum){
                int index = lower_bound(nums2.begin(), nums2.end(), sum - e) - nums2.begin();
                if(nums2[index] > sum - e)
                    index --;
                num += index + 1;
            }

        return num;
    }
};


void print_vec(const vector<pair<int, int>>& vec){
    for(const pair<int, int>& p: vec)
        cout << "(" << p.first << "," << p.second << ") ";
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

    vector<int> A7 = {1,2,4,5,6};
    vector<int> B7 = {3,5,7,9};
    print_vec(Solution().kSmallestPairs(A7, B7, 10));

    vector<int> A8 = {3,22,35,56,76};
    vector<int> B8 = {3,22,35,56,76};
    print_vec(Solution().kSmallestPairs(A8, B8, 25));

    vector<int> A9 = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<int> B9 = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    print_vec(Solution().kSmallestPairs(A9, B9, 1000));

    return 0;
}