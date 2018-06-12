/// Source : https://leetcode.com/problems/happy-number/
/// Author : liuyubobobo
/// Time   : 2017-01-18

#include <iostream>
#include <unordered_set>

using namespace std;

/// Using HashTable
/// Time Complexity: O(?)
/// Space Complexity: O(?)
class Solution {
public:
    bool isHappy(int n) {

        unordered_set<int> record;
        record.insert(n);
        while(n != 1){
            n = op(n);
            if( record.find(n) == record.end() )
                record.insert(n);
            else
                return false;
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

    return 0;
}