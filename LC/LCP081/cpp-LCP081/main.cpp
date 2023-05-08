/// Source : https://leetcode.cn/problems/ryfUiz/
/// Author : liuyubobobo
/// Time   : 2023-05-07

#include <iostream>
#include <vector>

using namespace std;


/// BIT
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
template<typename T>
class BIT{

private:
    int n;
    vector<T> data;
    vector<T> tree;

public:
    BIT(const vector<T>& arr) : n(arr.size()), data(arr.begin(), arr.end()), tree(n + 1){

        for(int i = 0; i < n; i ++)
            tree[i + 1]= data[i];

        for(int i = 1; i <= n; i ++){
            int parent = i + (i & -i);
            if(parent <= n) tree[parent] += tree[i];
        }
    }

    BIT(int n): n(n), data(n, 0), tree(n + 1, 0){}

    void add(int index, T v){
        assert(0 <= index && index < n);

        data[index] += v;

        index ++;
        for(;index <= n; index += (index & -index))
            tree[index] += v;
    }

    T query(int l, int r){
        assert(0 <= l && l < n);
        assert(0 <= r && r < n);
        assert(l <= r);
        return prefix_sum(r + 1) - prefix_sum(l);
    }

    void set(int index, T v){
        assert(0 <= index && index < n);
        add(index, v - data[index]);
    }

private:
    // r is 1-based
    T prefix_sum(int r){

        T res = 0;
        for(; r; r -= (r & -r))
            res += tree[r];
        return res;
    }
};

class Solution {
public:
    int getNandResult(int k, vector<int>& arr, vector<vector<int>>& operations) {

        int n = arr.size();
        vector<BIT<int>> bits(k, BIT<int>(n));
        for(int i = 0; i < n; i ++){
            int e = arr[i];
            for(int p = 0; p < k; p ++)
                bits[p].set(i, (e >> p) & 1);
        }

        int res = 0;
        for(const vector<int>& op: operations){
            int type = op[0];
            if(type == 0){
                int index = op[1], x = op[2];
                for(int p = 0; p < k; p ++)
                    bits[p].set(index, (x >> p) & 1);
            }
            else{
                int cnt = op[1], num = op[2];

                int tres = 0;
                for(int p = 0; p < k; p ++){
                    int len = get_len(n, bits[p]);
                    long long x;
                    if(len == 0) x= 1;
                    else if(len == n){
                        x = 1ll * cnt * n;
                        if((num >> p) & 1) x ++;
                    }
                    else x = len + 1;

                    if(x % 2) tres |= (1 << p);
                }

                res ^= tres;
            }
        }
        return res;
    }

private:
    int get_len(int n, BIT<int>& bit){
        int l = 0, r = n;
        while(l < r){
            int mid = (l + r) / 2;
            if(bit.query(mid, n - 1) == n - mid) r = mid;
            else l = mid + 1;
        }
        return n - l;
    }
};


int main() {

    vector<int> arr1 = {1, 2};
    vector<vector<int>> op1 = {{1, 2, 3}, {0, 0, 3}, {1, 2, 2}};
    cout << Solution().getNandResult(3, arr1, op1) << endl;
    // 2

    return 0;
}
