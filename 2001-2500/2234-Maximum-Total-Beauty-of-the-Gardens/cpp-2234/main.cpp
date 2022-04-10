/// Source : https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/
/// Author : liuyubobobo
/// Time   : 2022-04-10

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Greedy
/// Time Compelxity: O(nlogn + nlogt + n)
/// Space Complexity: O(1)
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers,
                            long long newFlowers, long long t, long long full, long long partial) {

        long long n = flowers.size();
        sort(flowers.begin(), flowers.end(), greater<int>());

        long long full_num = 0;
        for(int i = 0; i < flowers.size(); i ++)
            if(flowers[i] >= t) full_num ++;
            else break;

        long long max_min_height = get_max_min_height(flowers, t - 1, newFlowers);
        long long left = newFlowers;
        for(int e: flowers) left -= max(max_min_height - e, 0ll);

        int index;
        for(index = 0; index < n; index ++)
            if(max_min_height - flowers[index] > 0) break;
        // 从 index 的位置开始使用了 newFlowers

        long long res = f(full, partial, n, full_num, max_min_height);
        for(int i = full_num; i < n; i ++){
            long long need2full = t - max((long long)flowers[i], max_min_height);
            assert(need2full >= 0);

            index = max(index, i + 1);
            if(left >= need2full){
                left -= need2full;
                full_num ++;
                res = max(res, f(full, partial, n, full_num, max_min_height));
            }
            else{
                need2full -= left;
                left = 0;

                while(need2full && index < n){
                    assert(max_min_height >= flowers[index]);
                    long long cur = (long long)(max_min_height - flowers[index]) * (n - index);
                    if(need2full >= cur){
                        need2full -= cur;
                        max_min_height = flowers[index];
                        index ++;
                    }
                    else{
                        long long remove_h = need2full / (n - index);
                        need2full -= remove_h * (n - index);
                        max_min_height -= remove_h;
                        if(need2full){
                            max_min_height --;
                            left = n - index - need2full;
                            need2full = 0;
                        }
                    }
                }

                if(need2full) break;
                full_num ++;
                res = max(res, f(full, partial, n, full_num, max_min_height));
            }
        }
        return res;
    }

private:
    long long get_max_min_height(const vector<int>& flowers, long long r, long long k){

        long long l = min((long long)flowers.back(), r);
        while(l < r){
            long long mid = (l + r + 1) / 2;

            long long sum = 0;
            for(int e: flowers)
                sum += max(mid - e, 0ll);
            if(k >= sum) l = mid;
            else r = mid - 1;
        }
        return l;
    }

    long long f(long long full, long long partial,
                long long n, long long full_num, long long max_min_height){
        return full * full_num + (full_num == n ? 0 : partial * max_min_height);
    }
};


int main() {

    vector<int> flowers1 = {1, 3, 1, 1};
    cout << Solution().maximumBeauty(flowers1, 7, 6, 12, 1) << '\n';
    // 14

    vector<int> flowers2 = {2, 4, 5, 3};
    cout << Solution().maximumBeauty(flowers2, 10, 5, 2, 6) << '\n';
    // 30

    vector<int> flowers3 = {18, 16, 10, 10, 5};
    cout << Solution().maximumBeauty(flowers3, 10, 3, 15, 4) << '\n';
    // 75

    return 0;
}
