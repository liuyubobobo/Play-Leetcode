/// Source : https://leetcode.com/problems/tallest-billboard/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Meet in the middle
/// Time Complexity: O(3 ^ (n/2))
/// Space Complexity: O(3 ^ (n / 2))
class Solution {

private:
    vector<int> pow3;

public:
    int tallestBillboard(vector<int>& rods) {

        pow3 = {1};
        for(int i = 1; i <= 10; i ++) pow3.push_back(pow3.back() * 3);

        int n = rods.size();
        int left = n / 2, right = n - n / 2;

        unordered_map<int, int> ltable, rtable;
        for(int lstate = 0; lstate < pow3[left]; lstate ++){
            int l = lstate, lsum = 0, sum = 0, index = 0;
            while(l){
                int x = l % 3;
                if(x == 1) lsum += rods[index], sum += rods[index];
                else if(x == 2) lsum -= rods[index], sum += rods[index];
                l /= 3;
                index ++;
            }
            ltable[lsum] = sum;
        }
        for(int rstate = 0; rstate < pow3[right]; rstate ++){

            int r = rstate, rsum = 0, sum = 0, index = 0;
            while(r){
                int x = r % 3;
                if(x == 1) rsum += rods[left + index], sum += rods[left + index];
                else if(x == 2) rsum -= rods[left + index], sum += rods[left + index];
                r /= 3;
                index ++;
            }
            rtable[rsum] = sum;
        }

        int res = 0;
        for(const pair<int, int>& p: ltable)
            if(rtable.count(-p.first)) res = max(res, (p.second + rtable[-p.first]) / 2);
        return res;
    }
};


int main() {

    vector<int> rods1 = {243,269,278,237,208,279,229,231,262,256,248,261,232,275,254,224,264};
    cout << Solution().tallestBillboard(rods1) << endl;
    // 2125

    vector<int> rods2 = {1, 2};
    cout << Solution().tallestBillboard(rods2) << endl;
    // 0

    return 0;
}
