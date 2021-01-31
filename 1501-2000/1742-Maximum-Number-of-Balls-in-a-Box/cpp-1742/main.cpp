/// Source : https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
/// Author : liuyubobobo
/// Time   : 2021-01-30

#include <iostream>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O((h - l) * log(h))
/// Space Complexity: O(h - l)
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {

        unordered_map<int, int> f;
        int res = 0;
        for(int i = lowLimit; i <= highLimit; i ++){
            int k = hash(i);
            f[k] ++;
            res = max(res, f[k]);
        }
        return res;
    }

private:
    int hash(int x){

        int sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};


int main() {

    cout << Solution().countBalls(1, 10) << endl;
    // 2

    cout << Solution().countBalls(5, 15) << endl;
    // 2

    cout << Solution().countBalls(19, 28) << endl;
    // 2

    return 0;
}
