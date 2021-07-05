/// Source : https://leetcode.com/problems/longest-common-subpath/
/// Author : liuyubobobo
/// Time   : 2021-07-04

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Binary Search + Rolling Hash
/// Using unsigned long long to avoid % operation
/// and make MODE = 2^64
/// Time Complexity: O(O(all_path_city * log(min_len)))
/// Space Complexity: O(n)
class Solution {

private:
    unsigned long long BASE = 100003ll;
    vector<unsigned long long> powers;

public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {

        int min_len = INT_MAX;
        for(const vector<int>& path: paths)
            min_len = min(min_len, (int)path.size());

        powers.push_back(1ll);
        for(int i = 1; i <= min_len; i ++)
            powers.push_back(powers.back() * BASE);

        int l = 0, r = min_len;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(ok(paths, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const vector<vector<int>>& paths, int len){

        set<unsigned long long> hashes;
        get_hashes(paths[0], len, hashes);

        for(int i = 1; i < paths.size(); i ++){
            set<unsigned long long> thashes;
            get_hashes(paths[i], len, thashes);

            hashes = intersection(hashes, thashes);

            if(hashes.empty()) return false;
        }
        return true;
    }

    set<unsigned long long> intersection(set<unsigned long long>& a, set<unsigned long long>& b){

        set<unsigned long long> res;
        for(unsigned long long e: a)
            if(b.count(e)) res.insert(e);
        return res;
    }

    void get_hashes(const vector<int>& path, int len, set<unsigned long long>& hashes){

        unsigned long long cur = 0ll;
        for(int i = 0; i < len - 1; i ++)
            cur = cur * BASE + path[i];

        for(int i = len - 1; i < path.size(); i ++){
            cur = cur * BASE + path[i];

            hashes.insert(cur);

            cur -= path[i - (len - 1)] * powers[len - 1];
        }
    }
};


int main() {

    vector<vector<int>> paths1 = {{0,1,2,3,4},{2,3,4},{4,0,1,2,3}};
    cout << Solution().longestCommonSubpath(5, paths1) << endl;
    // 2

    vector<vector<int>> paths2 = {{0},{1},{2}};
    cout << Solution().longestCommonSubpath(3, paths2) << endl;
    // 0

    vector<vector<int>> paths3 = {{0,1,2,3,4},{4,3,2,1,0}};
    cout << Solution().longestCommonSubpath(5, paths3) << endl;
    // 1

    vector<vector<int>> paths4 = {{0,1,0,1,0,1,0,1,0},{0,1,3,0,1,4,0,1,0}};
    cout << Solution().longestCommonSubpath(5, paths4) << endl;
    // 3

    return 0;
}
