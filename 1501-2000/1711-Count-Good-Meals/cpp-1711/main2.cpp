/// Source : https://leetcode.com/problems/count-good-meals/
/// Author : liuyubobobo
/// Time   : 2021-01-02

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Two Sum + HashMap
/// Time Complexity: O(n)
/// Space Complextiy: O(n)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int countPairs(vector<int>& data) {

        vector<int> pow2(22, 1);
        for(int i = 1; i < pow2.size(); i ++) pow2[i] = pow2[i - 1] * 2;

        unordered_map<int, int> map;
        int res = 0;
        for(int e: data){
            for(int sum: pow2)
                if(map.count(sum - e))
                    res = (res + map[sum - e]) % MOD;
            map[e] ++;
        }
        return res;
    }
};


int main() {

    vector<int> data1 = {1, 3, 5, 7, 9};
    cout << Solution().countPairs(data1) << endl;
    // 4

    vector<int> data2 = {1,1,1,3,3,3,7};
    cout << Solution().countPairs(data2) << endl;
    // 15

    vector<int> data3 = {149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234};
    cout << Solution().countPairs(data3) << endl;
    // 12

    return 0;
}
