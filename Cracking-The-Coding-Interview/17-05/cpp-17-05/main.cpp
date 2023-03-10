/// Source : https://leetcode.cn/problems/find-longest-subarray-lcci/
/// Author : liuyubobobo
/// Time   : 2023-03-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {

        int n = array.size();
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            v[i] = (isdigit(array[i][0]) ? 1 : -1);

        map<int, int> m;
        m[0] = -1;
        int cur = 0, best = 0, resl = -1, resr = -1;
        for(int i = 0; i < n; i ++) {
            cur += v[i];

            auto iter = m.find(-cur);
            if(iter != m.end()){
                int len = i - iter->second;
                if(len > best){
                    best = len;
                    resl = iter->second + 1;
                    resr = i;
                }
            }
            else m[-cur] = i;
        }

        return best == 0 ? vector<string>() : vector<string>(array.begin() + resl, array.begin() + resr + 1);
    }
};


int main() {

    return 0;
}
