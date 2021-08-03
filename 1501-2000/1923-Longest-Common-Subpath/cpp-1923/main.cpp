/// Source : https://leetcode.com/problems/longest-common-subpath/
/// Author : liuyubobobo
/// Time   : 2021-08-02

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;


/// RK
/// Time Complexity: O(O(all_path_city * log(min_len)))
/// Space Complexity: O(n)
class StringHash{

private:
    int n;
    unsigned long long B, MOD;
    vector<unsigned long long> h, p;

public:
    StringHash(const vector<int>& s, unsigned long long B = 128, unsigned long long MOD = 1e9+ 7) :
    n(s.size()), h(n + 1, 0), p(n + 1, 1ll), B(B), MOD(MOD){

        for(int i = 0; i < n; i ++){
            h[i + 1] = (h[i] * B + s[i]) % MOD;
            p[i + 1] = p[i] * B % MOD;
        }
    }

    unsigned long long get_hash(int l, int r){
        //        assert(l >= 0 && l < n);
        //        assert(r >= 0 && r < n);
        return (h[r + 1] - h[l] * p[r - l + 1] % MOD + MOD) % MOD;
    }
};

class StringHashU{

private:
    int n;
    unsigned long long B;
    vector<unsigned long long> h, p;

public:
    StringHashU(const vector<int>& s, unsigned long long B = 128) :
    n(s.size()), h(n + 1, 0), p(n + 1, 1ll), B(B){

        for(int i = 0; i < n; i ++){
            h[i + 1] = h[i] * B + s[i];
            p[i + 1] = p[i] * B;
        }
    }

    unsigned long long get_hash(int l, int r){
        //        assert(l >= 0 && l < n);
        //        assert(r >= 0 && r < n);
        return h[r + 1] - h[l] * p[r - l + 1];
    }
};

class Solution {

private:
    vector<StringHash> hash1/*, hash2*/;
    vector<StringHashU> hash3;

public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {

        int min_len = INT_MAX, maxv = 0;
        for(const vector<int>& path: paths){
            min_len = min(min_len, (int)path.size());
            maxv = max(maxv, *max_element(path.begin(), path.end()));
        }

        hash1.clear(), /*hash2.clear(),*/ hash3.clear();
        for(int i = 0; i < paths.size(); i ++){
            hash1.push_back(StringHash(paths[i], 911382323, 972663749));
            //            hash2.push_back(StringHash(paths[i], 1e9 + 5e8 + 7, 3e9 + 19));
            hash3.push_back(StringHashU(paths[i], maxv + 7));
        }

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

        unordered_set<unsigned long long> hash1_set, hash2_set, hash3_set;
        for(int i = 0; i + len <= paths[0].size(); i ++){
            hash1_set.insert(hash1[0].get_hash(i, i + len - 1));
            //            hash2_set.insert(hash2[0].get_hash(i, i + len - 1));
            hash3_set.insert(hash3[0].get_hash(i, i + len - 1));
        }

        for(int i = 1; i < paths.size(); i ++){

            unordered_set<unsigned long long> t_hash_set1, /*t_hash_set2, */t_hash_set3;
            for(int j = 0; j + len <= paths[i].size(); j ++){
                t_hash_set1.insert(hash1[i].get_hash(j, j + len - 1));
                //                t_hash_set2.insert(hash2[i].get_hash(j, j + len - 1));
                t_hash_set3.insert(hash3[i].get_hash(j, j + len - 1));
            }

            hash1_set = intersection(hash1_set, t_hash_set1);
            //            hash2_set = intersection(hash2_set, t_hash_set2);
            hash3_set = intersection(hash3_set, t_hash_set3);

            if(hash1_set.empty() || /*hash2_set.empty() ||*/ hash3_set.empty())
                return false;
        }
        return true;
    }

    unordered_set<unsigned long long> intersection(unordered_set<unsigned long long>& a,
                                                   unordered_set<unsigned long long>& b){

        unordered_set<unsigned long long> res;
        for(long long e: a)
            if(b.count(e)) res.insert(e);
            return res;
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
