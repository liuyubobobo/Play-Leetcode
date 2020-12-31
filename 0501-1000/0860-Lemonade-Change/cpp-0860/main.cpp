/// Source : https://leetcode.com/problems/lemonade-change/description/
/// Author : liuyubobobo
/// Time   : 2018-06-30

#include <iostream>
#include <vector>

using namespace std;


/// Simulation and Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0, ten = 0, twenty = 0;
        for(int bill: bills){
            if(bill == 5)
                five ++;
            else if(bill == 10){
                ten ++;
                if(five == 0)
                    return false;
                else
                    five --;
            }
            else{
                twenty ++;
                if(ten > 0 && five > 0)
                    ten --, five --;
                else if(five >= 3)
                    five -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<int> bills1 = {5, 5, 5, 10, 20};
    print_bool(Solution().lemonadeChange(bills1));

    vector<int> bills2 = {5, 5, 10};
    print_bool(Solution().lemonadeChange(bills2));

    vector<int> bills3 = {10, 10};
    print_bool(Solution().lemonadeChange(bills3));

    vector<int> bills4 = {5, 5, 10, 10, 20};
    print_bool(Solution().lemonadeChange(bills4));

    return 0;
}