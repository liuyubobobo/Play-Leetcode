/// Source : https://leetcode.com/problems/create-sorted-array-through-instructions/
/// Author : liuyubobobo
/// Time   : 2020-11-17

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Merge Sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int createSortedArray(vector<int>& instructions) {

        int n = instructions.size();
        vector<int> aux(n), indice(n), left(n);
        for(int i = 0; i < n; i ++) indice[i] = i;

        merge_sort(instructions, indice, 0, n - 1, aux, left);
//        cout << "indice : "; for(int e: indice) cout << e << " "; cout << endl;
//        cout << "left : ";   for(int e: left) cout << e << " "; cout << endl;
        int res = 0;
        unordered_map<int, int> f;
        for(int i = 0; i < n; i ++){
            f[instructions[i]] ++;
            int right = left[i], left = i + 1 - f[instructions[i]] - right;
            res += min(left, right);
            res %= MOD;
        }
        return res;
    }

private:
    void merge_sort(const vector<int>& nums, vector<int>& indice, int l, int r,
                    vector<int>& aux, vector<int>& left){

        if(l >= r) return;

        int mid = (l + r) / 2;
        merge_sort(nums, indice, l, mid, aux, left);
        merge_sort(nums, indice, mid + 1, r, aux, left);
        if(nums[indice[mid]] > nums[indice[mid + 1]])
            merge(nums, indice, l, mid, r, aux, left);
    }

    void merge(const vector<int>& nums, vector<int>& indice, int l, int mid, int r,
               vector<int>& aux, vector<int>& left){

        for(int i = l; i <= r; i ++) aux[i] = indice[i];

        int i = l, j = mid + 1;
        for(int k = l; k <= r; k ++){
            if(i > mid) indice[k] = aux[j ++];
            else if(j > r) indice[k] = aux[i ++];
            else if(nums[aux[i]] <= nums[aux[j]]) indice[k] = aux[i ++];
            else indice[k] = aux[j ++], left[indice[k]] += (mid - i + 1);
        }
    }
};


int main() {

    vector<int> ins1 = {1,5,6,2};
    cout << Solution().createSortedArray(ins1) << endl;
    // 1

    vector<int> ins2 = {1,2,3,6,5,4};
    cout << Solution().createSortedArray(ins2) << endl;
    // 3

    vector<int> ins3 = {1,3,3,3,2,4,2,1,2};
    cout << Solution().createSortedArray(ins3) << endl;
    // 4

    return 0;
}
