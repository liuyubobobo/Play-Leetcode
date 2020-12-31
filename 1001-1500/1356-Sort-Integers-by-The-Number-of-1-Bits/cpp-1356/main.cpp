/// Source : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
/// Author : liuyubobobo
/// Time   : 2020-02-22

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlognlog(num))
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        sort(arr.begin(), arr.end(), [](int a, int b){

            int abits = bits_num(a), bbits = bits_num(b);
            if(abits != bbits) return abits < bbits;
            return a < b;
        });
        return arr;
    }

private:
    static int bits_num(int x){

        int res = 0;
        while(x) res += x % 2, x /= 2;
        return res;
    }
};


int main() {

    return 0;
}
