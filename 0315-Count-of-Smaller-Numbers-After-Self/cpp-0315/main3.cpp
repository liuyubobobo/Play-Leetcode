/// Source : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
/// Author : liuyubobobo
/// Time   : 2018-12-03

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Merge Sort
/// Using indexes arr to track every element's index
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int> indexes(n); // indexes[i] : 在排序过程中，nums第i个元素
                                //              对应初始nums中indexes[i]的位置
                                // indexes[2] = 5 表示现在nums中第2个元素，在初始nums中索引为5的位置
        for(int i = 0; i < n; i ++)
            indexes[i] = i;

        vector<int> res(n, 0);
        vector<int> aux(n);
        merge_sort(nums, 0, n - 1, indexes, aux, res);
        return res;
    }

private:
    void merge_sort(vector<int>& arr, int l, int r,
                    vector<int>& indexes, vector<int>& aux, vector<int>& res){

        if(l >= r)
            return;

        int mid = (l + r) / 2;
        merge_sort(arr, l, mid, indexes, aux, res);
        merge_sort(arr, mid + 1, r, indexes, aux, res);
        if(arr[mid] > arr[mid + 1])
            merge(arr, l, mid, r, indexes, aux, res);
    }

    void merge(vector<int>& arr, int l, int mid, int r,
               vector<int>& indexes, vector<int>& aux, vector<int>& res){

        for(int i = l; i <= r; i ++)
            aux[i] = arr[i];

        vector<int> new_indexes(r - l + 1);
        int i = l, j = mid + 1;
        for(int k = l; k <= r; k ++)
            if(i > mid)
                arr[k] = aux[j], new_indexes[k - l] = indexes[j], j ++;
            else if(j > r)
                arr[k] = aux[i], new_indexes[k - l] = indexes[i], res[indexes[i]] += j - mid - 1, i ++;
            else if(aux[i] <= aux[j])
                arr[k] = aux[i], new_indexes[k - l] = indexes[i], res[indexes[i]] += j - mid - 1, i ++;
            else
                arr[k] = aux[j], new_indexes[k - l] = indexes[j], j ++;

        for(int k = l; k <= r; k ++)
            indexes[k] = new_indexes[k - l];
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {5, 2, 6, 1};
    print_vec(Solution().countSmaller(nums1));
    // 2 1 1 0

    vector<int> nums2 = {2, 0, 1};
    print_vec(Solution().countSmaller(nums2));
    // 2 0 0

    return 0;
}