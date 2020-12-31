/// Source : https://leetcode.com/problems/duplicate-zeros/
/// Author : liuyubobobo
/// Time   : 2019-06-15

#include <iostream>
#include <vector>

using namespace std;


/// Using another array to construct the result
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        vector<int> res;
        for(int e: arr)
            if(e) res.push_back(e);
            else res.push_back(0), res.push_back(0);

        for(int i = 0; i < arr.size(); i ++)
            arr[i] = res[i];
    }
};


int main() {

    return 0;
}