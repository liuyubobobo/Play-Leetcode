/// Source : https://leetcode.com/problems/maximum-value-after-insertion/
/// Author : liuyubobobo
/// Time   : 2021-05-29

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(|n|)
/// Space Complexity: O(1)
class Solution {
public:
    string maxValue(string n, int x) {

        int i;
        if(n[0] != '-'){
            for(i = 0; i < n.size(); i ++)
                if(n[i] < '0' + x) break;
            return n.substr(0, i) + string(1, '0' + x) + n.substr(i);
        }

        for(i = 1; i < n.size(); i ++)
            if(n[i] > '0' + x) break;
        return n.substr(0, i) + string(1, '0' + x) + n.substr(i);
    }
};


int main() {

    cout << Solution().maxValue("99", 9) << endl;
    // 999

    cout << Solution().maxValue("514", 2) << endl;
    // 5214

    cout << Solution().maxValue("-13", 2) << endl;
    // -123

    cout << Solution().maxValue("-33", 2) << endl;
    // -233

    cout << Solution().maxValue("-11", 2) << endl;
    // -112

    cout << Solution().maxValue("-6484681536456", 5) << endl;
    // -5648468153646

    return 0;
}
