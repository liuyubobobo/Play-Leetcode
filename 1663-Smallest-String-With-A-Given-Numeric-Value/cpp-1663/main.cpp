/// Source : https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
/// Author : liuyubobobo
/// Time   : 2020-11-21

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string getSmallestString(int n, int k) {

        string res(n, 'a');
        int sum = n;

        int i = n - 1;
        while(sum != k){
            if(k - sum >= 25)
                res[i] = 'z', sum += 25;
            else
                res[i] += (k - sum), sum = k;

            i --;
        }
        return res;
    }
};


int main() {

    cout << Solution().getSmallestString(3, 27) << endl;
    // aay

    cout << Solution().getSmallestString(5, 73) << endl;
    // aaszz

    return 0;
}
