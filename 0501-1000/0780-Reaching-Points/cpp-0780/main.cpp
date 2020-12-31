/// Source : https://leetcode.com/problems/reaching-points/description/
/// Author : liuyubobobo
/// Time   : 2018-02-11

#include <iostream>
#include <cassert>

using namespace std;

/// Work Backwards
///
/// Time Complexity: O(log(max(tx, ty)))
/// Space Complexity: O(1)
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {

        if(tx == sx && ty == sy)
            return true;

        if(tx < sx || ty < sy)
            return false;

        assert(tx >= sx && ty >= sy);
        while(true){

            if(tx > ty){
                if(ty > sy)
                    tx %= ty;
                else //
                    return ty == sy && (tx - sx) % ty == 0;
            }
            else{ // tx <= ty
                if(tx > sx)
                    ty %= tx;
                else
                    return tx == sx && (ty - sy) % tx == 0;
            }
        }

        assert(false);
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    printBool(Solution().reachingPoints(1, 1, 3, 5));
    printBool(Solution().reachingPoints(1, 1, 2, 2));
    printBool(Solution().reachingPoints(1, 1, 1, 1));

    return 0;
}