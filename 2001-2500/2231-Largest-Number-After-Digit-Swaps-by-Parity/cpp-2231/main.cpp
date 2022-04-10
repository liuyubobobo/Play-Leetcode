/// Source : https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
/// Author : liuyubobobo
/// Time   : 2022-04-10

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(logn * log(logn))
/// Space Compelxity: O(logn)
class Solution {
public:
    int largestInteger(int num) {

        vector<int> even, odd;
        vector<bool> is_even;
        for(int i = 0; num; i ++){
            int d = num % 10; num /= 10;
            if(d % 2){
                odd.push_back(d);
                is_even.push_back(false);
            }
            else{
                even.push_back(d);
                is_even.push_back(true);
            }
        }

        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());
        int even_p = 0, odd_p = 0, res = 0;
        for(int i = is_even.size() - 1; i >= 0 ; i --){
            if(is_even[i]) res = res * 10 + even[even_p ++];
            else res = res * 10 + odd[odd_p ++];
        }
        return res;

    }
};


int main() {

    return 0;
}
