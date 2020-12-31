/// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Hash Map
/// Time Complexity: O(len(nums1) + len(nums2)*log(len(nums1)))
/// Space Complexity: O(len(nums1))
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        multiset<int> record;
        for(int num: nums1)
            record.insert(num);

        multiseSt<int> result;
        for(int num: nums2){
            multiset<int>::iterator iter = record.find(num);
            if( iter != record.end()){
                result.insert(num);
                record.erase(iter);
            }
        }

        return vector<int>(result.begin(), result.end());
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