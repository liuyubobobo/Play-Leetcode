/// Source : https://leetcode.com/problems/next-greater-element-i/
/// Author : liuyubobobo
/// Time   : 2021-03-08

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


/// Mono Stack
/// Time Complexity: O(|nums2| + |nums1|)
/// Space Complexity: O(|nums2|)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> table;

        stack<int> stack;
        for(int e: nums2){

            while(!stack.empty() && e > stack.top()){
                table[stack.top()] = e;
                stack.pop();
            }

            stack.push(e);
        }

        vector<int> res(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i ++)
            if(table.count(nums1[i])) res[i] = table[nums1[i]];
        return res;
    }
};


int main() {

    return 0;
}
