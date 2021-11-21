/// Source : https://leetcode.com/problems/sum-of-k-mirror-numbers/
/// Author : liuyubobobo
/// Time   : 2021-11-20

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(sqrt(max_num) * logn)
/// Space Complexity: O(log(max_num) + logn)
class Solution {
public:
    long long kMirror(int k, int n) {

        long long sum = 0;
        vector<int> numk(1000);
        for(int sz = 1;n;sz ++){
            vector<int> num(sz);
            dfs(sz, num, numk, 0, k, n, sum);
        }
        return sum;
    }

private:
    void dfs(int sz, vector<int>& num, vector<int>& numk,
             int index, int k, int& n, long long& sum){

        if(n == 0) return;

        if(index >= ((sz + 1) >> 1)){
            long long a = 0ll;
            for(int e: num) a = a * 10 + e;
            if(ok(a, k, numk)) sum += a, n --;
            return;
        }

        for(int i = (index == 0 ? 1 : 0); i <= 9 && n; i ++){
            num[index] = num[sz - 1 - index] = i;
            dfs(sz, num, numk, index + 1, k, n, sum);
        }
    }

    bool ok(long long a, int k, vector<int>& numk){

        int w = 0;
        while(a) numk[w ++] = a % k, a /= k;

        int half = w / 2;
        for(int i = 0; i < half; i ++)
            if(numk[i] != numk[w - 1 - i]) return false;
        return true;
    }
};


int main() {

    cout << Solution().kMirror(2, 5) << endl;
    // 25

    cout << Solution().kMirror(3, 7) << endl;
    // 499

    cout << Solution().kMirror(4, 30) << endl;
    // 53393239260

    for(int k = 2; k <= 9; k ++)
        cout << Solution().kMirror(k, 30) << endl;

    return 0;
}
