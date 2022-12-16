/// Source : https://leetcode.com/problems/minimum-penalty-for-a-shop/description/
/// Author : liuyubobobo
/// Time   : 2022-12-02

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Compelxity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int bestClosingTime(string customers) {

        int res = 0, p = 0;
        for(char c: customers) p += c == 'Y';

        int best = p;
        for(int i = 0; i < customers.size(); i ++){
            char c = customers[i];
            if(c == 'Y') p --;
            else p ++;
            if(p < best) best = p, res = i + 1;
        }
        return res;
    }
};


int main() {

    return 0;
}
