/// Source : https://leetcode.com/problems/duplicate-zeros/
/// Author : liuyubobobo
/// Time   : 2019-06-15

#include <iostream>
#include <vector>

using namespace std;


/// Scan from end to start to make sure every position
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        int n = arr.size();
        int j = n + count(arr.begin(), arr.end(), 0);
        for(int i = n - 1; i >= 0; i --){
            if(--j < n)
                arr[j] = arr[i];
            if(!arr[i] && --j < n)
                arr[j] = 0;
        }
    }
};


int main() {

    return 0;
}