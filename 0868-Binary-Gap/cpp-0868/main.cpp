/// Source : https://leetcode.com/problems/binary-gap/description/
/// Author : liuyubobobo
/// Time   : 2018-07-14

#include <iostream>
#include <vector>

using namespace std;


/// Store all the '1''s index
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int binaryGap(int N) {

        vector<int> indexes;
        int index = 0;
        while(N){
            if(N & 1)
                indexes.push_back(index);
            index ++;
            N >>= 1;
        }

        int res = 0;
        for(int i = 1 ; i < indexes.size() ; i ++)
            res = max(res, indexes[i] - indexes[i - 1]);

        return res;
    }
};


int main() {

    cout << Solution().binaryGap(22) << endl;
    cout << Solution().binaryGap(5) << endl;
    cout << Solution().binaryGap(6) << endl;
    cout << Solution().binaryGap(8) << endl;

    return 0;
}