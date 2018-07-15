/// Source : https://leetcode.com/problems/random-pick-with-blacklist/description/
/// Author : liuyubobobo
/// Time   : 2018-07-08

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Binary Search the answer
/// Time Complexity: init: O(BlogB), where B is len(blacklist)
///                  pick: O(logB)
/// Space Complexity: O(B)
class Solution {

private:
    vector<int> b;
    unordered_set<int> bset;
    int N;

public:
    Solution(int N, vector<int> blacklist): b(blacklist) {

        sort(b.begin(), b.end());
        this->N = N;

        bset.clear();
        for(int num: b)
            bset.insert(num);

        srand(time(NULL));
    }

    int pick() {
        int limit = N - b.size();
        int res = rand() % limit;

        int l = 0, r = N - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int rb = b.end() - lower_bound(b.begin(), b.end(), mid);
            int lb = b.size() - rb;

            if(bset.find(mid) != bset.end()){
                if(mid - lb > res)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else{
                if(mid - lb == res)
                    return mid;
                else if(mid - lb < res)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return res;
    }
};


int main() {

    Solution solution1(2, {1});
    cout << solution1.pick() << endl; // 0

    Solution solution2(3, {1, 2});
    cout << solution2.pick() << endl; // 0

    Solution solution3(2, {});
    for(int i = 0 ; i < 20 ; i ++)
        cout << solution3.pick() << " "; // half 0, half 1
    cout << endl;

    return 0;
}