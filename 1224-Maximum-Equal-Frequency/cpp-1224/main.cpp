/// Source : https://leetcode.com/problems/maximum-equal-frequency/
/// Author : liuyubobobo
/// Time   : 2019-10-12

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map to record freq and the freq of freq number
/// Time Complexity: O(|nums|)
/// Space Complexity: O(|nums|)
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {

        if(nums.size() <= 3) return nums.size();

        map<int, int> freq;
        for(int i = 0; i < 3; i ++)
            freq[nums[i]] ++;

        map<int, int> freqnum;
        for(const pair<int, int>& p: freq)
            freqnum[p.second] ++;

        int res = 3;
        for(int i = 3; i < nums.size(); i ++){
            int o_f = freq[nums[i]];
            if(o_f) {
                freqnum[o_f]--;
                if (freqnum[o_f] == 0) freqnum.erase(o_f);
            }
            freq[nums[i]] ++;
            int new_f = freq[nums[i]];
            freqnum[new_f] ++;

//            cout << i << " : ";
//            for(const pair<int, int>& p: freqnum) cout << "(" << p.first << "," << p.second << ")";
//            cout << endl;

            if(freqnum.size() == 1 && (freqnum.begin()->first == 1 || freqnum.begin()->second == 1)) res = i + 1;
            else if(freqnum.size() == 2){

                map<int, int>::iterator iter1 = freqnum.begin();
                map<int, int>::iterator iter2 = freqnum.begin();
                iter2 ++;
                if((iter1->first == 1 && iter1->second == 1) ||
                   (iter2->second == 1 && iter2->first - iter1->first == 1)) res = i + 1;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2,2,1,1,5,3,3,5};
    cout << Solution().maxEqualFreq(nums1) << endl;
    // 7

    vector<int> nums2 = {1,1,1,2,2,2,3,3,3,4,4,4,5};
    cout << Solution().maxEqualFreq(nums2) << endl;
    // 13

    vector<int> nums3 = {1,1,1,2,2,2};
    cout << Solution().maxEqualFreq(nums3) << endl;
    // 5

    vector<int> nums4 = {10,2,8,9,3,8,1,5,2,3,7,6};
    cout << Solution().maxEqualFreq(nums4) << endl;
    // 8

    vector<int> nums5 = {1,2,3,4,5,6,7,8,9};
    cout << Solution().maxEqualFreq(nums5) << endl;
    // 9

    vector<int> nums6 = {1,1,1,1,1,1};
    cout << Solution().maxEqualFreq(nums6) << endl;
    // 6

    vector<int> nums7 = {2,2,1,1,5,3,3,5};
    cout << Solution().maxEqualFreq(nums7) << endl;
    // 7

    return 0;
}