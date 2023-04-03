/// Source : https://leetcode.com/problems/previous-permutation-with-one-swap/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {

        if(is_sorted(arr.begin(), arr.end())) return arr;

        int n = arr.size();
        for(int i = n - 1; i > 0; i --)
            if(arr[i - 1] > arr[i]){
                auto iter = lower_bound(arr.begin() + i, arr.end(), arr[i - 1]);
                iter --;

                int index = iter - arr.begin();
                int t = *iter;
                while(arr[index - 1] == t) index --;

                swap(arr[i - 1], arr[index]);
                break;
            }
        return arr;
    }
};


int main() {

    return 0;
}
