/// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
/// Author : liuyubobobo
/// Time   : 2019-04-08

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Sorting and Two Pointers
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;

        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){

            if(nums1[i] == nums2[j]) res.push_back(nums1[i]), i ++, j ++;
            else if(nums1[i] < nums2[j]) i ++;
            else j ++;
        }

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    print_vec(Solution().intersect(nums1, nums2));

    return 0;
}