/// Source : https://leetcode.cn/contest/ubiquant2022/problems/uGuf0v/
/// Author : liuyubobobo
/// Time   : 2022-08-25

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Compelxity: O(nlogA)
/// Space Complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& numbers) {

        int n = numbers.size();

        vector<int> two(n, 0), three(n, 0), base(n, 0);
        for(int i = 0; i < n; i ++){
            int x = numbers[i];
            while(x % 2 == 0) two[i] ++, x /= 2;
            while(x % 3 == 0) three[i] ++, x /= 3;
            base[i] = x;
        }

        for(int i = 1; i < n; i ++)
            if(base[i] != base[0]) return -1;

        int res = 0;

        int max_two = *max_element(two.begin(), two.end());
        for(int e: two) res += max_two - e;

        int max_three = *max_element(three.begin(), three.end());
        for(int e: three) res += max_three - e;

        return res;
    }
};


int main() {

    return 0;
}
