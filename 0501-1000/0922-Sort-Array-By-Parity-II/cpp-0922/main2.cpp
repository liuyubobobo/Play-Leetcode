/// Source : https://leetcode.com/problems/sort-array-by-parity-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-10-13

#include <iostream>
#include <vector>

using namespace std;


/// Two pass to deal with odd and even elements seperately
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {

        vector<int> ret(A.size());
        int p_even = 0;
        for(int a: A)
            if(a % 2 == 0){
                ret[p_even] = a;
                p_even += 2;
            }

        int p_odd = 1;
        for(int a: A)
            if(a % 2){
                ret[p_odd] = a;
                p_odd += 2;
            }
        return ret;
    }
};


int main() {

    return 0;
}