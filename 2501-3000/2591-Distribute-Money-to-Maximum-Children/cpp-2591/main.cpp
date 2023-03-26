/// Source : https://leetcode.com/problems/distribute-money-to-maximum-children/description/
/// Author : liuyubobobo
/// Time   : 2023-03-25

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(min(money / 8, children))
/// Space Complexity: O(1)
class Solution {
public:
    int distMoney(int money, int children) {

        for(int res = min(money / 8, children); res >= 0; res --){

            int left_money = money - res * 8;
            int left_children = children - res;
            if(left_money && !left_children) continue;
            if(left_children == 1 && left_money == 4) continue;
            if(left_money < left_children) continue;
            return res;
        }
        return -1;
    }
};

int main() {

    return 0;
}
