/// Source : https://leetcode.com/problems/maximize-the-beauty-of-the-garden/
/// Author : liuyubobobo
/// Time   : 2021-03-11

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Presum + Greedy
/// A little optimization
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {

        int n = flowers.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + (flowers[i] > 0 ? flowers[i] : 0);

        map<int, int> index;
        int res = INT_MIN;
        for(int i = 0; i < flowers.size(); i ++){
            if(index.count(flowers[i])){
                int end = flowers[i], maxi = i, mini = index[end];
                if(maxi != mini){
                    int tres = 2 * end;
                    mini ++, maxi --;
                    if(mini <= maxi) tres += presum[maxi + 1] - presum[mini];
                    res = max(res, tres);
                }
            }
            else
                index[flowers[i]] = i;
        }
        return res;
    }
};


int main() {

    vector<int> flowers1 = {1, 2, 3, 1, 2};
    cout << Solution().maximumBeauty(flowers1) << endl;
    // 8

    vector<int> flowers2 = {100, 1, 1, -3, 1};
    cout << Solution().maximumBeauty(flowers2) << endl;
    // 3

    vector<int> flowers3 = {-1, -2, 0, -1};
    cout << Solution().maximumBeauty(flowers3) << endl;
    // -2

    return 0;
}
