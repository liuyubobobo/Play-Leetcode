/// Source : https://leetcode.com/problems/closest-fair-integer/
/// Author : liuyubobobo
/// Time   : 2022-10-12

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(logn)
/// Space Complexity: O(logn)
class Solution {
public:
    int closestFair(int n) {

        string s = to_string(n);
        int len = s.size();

        int start = n;
        if(len % 2) start = (int)pow(10, len);

        int i;
        for(i = start; to_string(i).size() % 2 == 0; i ++)
            if(good(i)) return i;
        return closestFair(i);
    }

private:
    bool good(int x){

        vector<int> f(2, 0);
        while(x){
            int d = x % 10;
            f[d & 1] ++;
            x /= 10;
        }
        return f[0] == f[1];
    }
};


int main() {

    cout << Solution().closestFair(2) << '\n';

    return 0;
}
