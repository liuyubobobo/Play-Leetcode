/// Source : https://leetcode.com/problems/find-array-given-subset-sums/
/// Author : liuyubobobo
/// Time   : 2021-08-23

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Recursive
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {

        sort(sums.begin(), sums.end());

        vector<int> res;
        assert(dfs(sums, res));
        return res;
    }

private:
    bool dfs(const vector<int>& sums, vector<int>& res){

        if(sums.size() == 2){
            res.push_back(sums[0] == 0 ? sums[1] : sums[0]);
            return true;
        }

        int d = sums[1] - sums[0];

        vector<int> half;
        if(can_split(sums, d, half)){
            res.push_back(d);
            if(dfs(half, res)) return true;
            res.pop_back();
        }

        half.clear();
        if(can_split(sums, -d, half)){
            res.push_back(-d);
            assert(dfs(half, res));
            return true;
        }

        return false;
    }

    bool can_split(const vector<int>& sums, int p, vector<int>& left){

        multiset<int> set;
        for(int e: sums) set.insert(e);
        if(!set.count(p) || !set.count(0)) return false;

        set.erase(set.find(0));
        set.erase(set.find(p));
        left.push_back(0);

        multiset<int>::iterator iter;

        if(p <= 0){
            while(!set.empty()){
                int cur = *set.begin();
                set.erase(set.find(cur));

                iter = set.find(cur - p);
                if(iter == set.end()) return false;
                set.erase(iter);

                left.push_back(cur - p);
            }
        }
        else{
            while(!set.empty()){
                int cur = *set.rbegin();
                set.erase(set.find(cur));

                iter = set.find(cur - p);
                if(iter == set.end()) return false;
                set.erase(iter);

                left.push_back(cur - p);
            }
        }

        assert(left.size() * 2 == sums.size());
        sort(left.begin(), left.end());
        return true;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<int> sums1 = {-3, -2, -1, 0, 0, 1, 2, 3};
    print_vec(Solution().recoverArray(3, sums1));
    // 1 2 -3

    vector<int> sums2 = {0, 0, 0, 0};
    print_vec(Solution().recoverArray(2, sums2));
    // 0 0

    vector<int> sums3 = {0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8};
    print_vec(Solution().recoverArray(4, sums3));
    // -1 0 4 5

    vector<int> sums4 = {-1654,-771,-883,0};
    print_vec(Solution().recoverArray(2, sums4));
    // -771, -883

    vector<int> sums5 = {-574,-394,0,180,-180,-574,-754,0};
    print_vec(Solution().recoverArray(3, sums5));
    // 180 -180 -574

    vector<int> sums6 = {-607,0,-720,105,-502,893,286,-539,-434,998,68,-1327,-1432,391,173,-825};
    print_vec(Solution().recoverArray(4, sums6));
    // 105 -607 -825 893

    return 0;
}
