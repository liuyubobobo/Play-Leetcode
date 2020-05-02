/// Source : https://leetcode.com/problems/counting-elements/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int countElements(vector<int>& arr) {

        int res = 0;
        for(int e: arr)
            if(find(arr.begin(), arr.end(), e + 1) != arr.end())
                res ++;
        return res;
    }
};


int main() {

    return 0;
}