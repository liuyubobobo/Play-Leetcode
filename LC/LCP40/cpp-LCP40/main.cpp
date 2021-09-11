/// Source : https://leetcode-cn.com/problems/uOAnQW/
/// Author : liuyubobobo
/// Time   : 2021-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Greedy + Presum
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {

        vector<int> odd, even;
        for(int e: cards)
            if(e % 2) odd.push_back(e);
            else even.push_back(e);

        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());

        int oddn = odd.size();
        vector<int> presum1(oddn + 1, 0);
        for(int i = 0; i < oddn; i ++) presum1[i + 1] = presum1[i] + odd[i];

        int evenn = even.size();
        vector<int> presum2(evenn + 1, 0);
        for(int i = 0; i < evenn; i ++) presum2[i + 1] = presum2[i] + even[i];

        int res = 0;
        for(int oddnum = 0; oddnum <= oddn && oddnum <= cnt; oddnum += 2){
            int evennum = cnt - oddnum;
            if(evennum > evenn) continue;

            res = max(res, presum1[oddnum] + presum2[evennum]);
        }
        return res;
    }
};


int main() {

    vector<int> cards1 = {1, 2, 8, 9};
    cout << Solution().maxmiumScore(cards1, 3) << endl;
    // 18

    vector<int> cards2 = {3, 3, 1};
    cout << Solution().maxmiumScore(cards2, 1) << endl;
    // 0

    return 0;
}
