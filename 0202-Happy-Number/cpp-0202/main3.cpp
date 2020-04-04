/// Source : https://leetcode.com/problems/happy-number/
/// Author : liuyubobobo
/// Time   : 2020-04-03

#include <iostream>
#include <set>

using namespace std;

/// The only cycle is 4-16-37-58-89-145-42-20-4
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isHappy(int n) {

        set<int> cycle = {4, 16, 37, 58, 89, 145, 42, 20};
        while(n != 1){
            if(cycle.count(n)) return false;
            n = op(n);
        }
        return true;
    }

private:
    int op(int x){
        int res = 0;
        while(x){
            int t = x % 10;
            res += t * t;
            x /= 10;
        }
        return res;
    }
};


void print_bool(bool res){

    cout << (res ? "True" : "False") << endl;
}

int main() {

    print_bool(Solution().isHappy(19));
    // true

    return 0;
}