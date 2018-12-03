/// Source : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
/// Author : liuyubobobo
/// Time   : 2018-12-03

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Merge Sort
/// Sort (value, index) pair to track every element's index
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int, int>> elements;
        for(int i = 0; i < n; i ++)
            elements.push_back(make_pair(nums[i], i));

        vector<int> res(n, 0);
        vector<pair<int, int>> aux(n);
        merge_sort(elements, 0, n - 1, aux, res);
        return res;
    }

private:
    void merge_sort(vector<pair<int, int>>& arr, int l, int r,
                    vector<pair<int, int>>& aux, vector<int>& res){

        if(l >= r)
            return;

        int mid = (l + r) / 2;
        merge_sort(arr, l, mid, aux, res);
        merge_sort(arr, mid + 1, r, aux, res);
        if(arr[mid] > arr[mid + 1])
             merge(arr, l, mid, r, aux, res);
    }

    void merge(vector<pair<int, int>>& arr, int l, int mid, int r,
               vector<pair<int, int>>& aux, vector<int>& res){

        for(int i = l; i <= r; i ++)
            aux[i] = arr[i];
        int i = l, j = mid + 1;
        for(int k = l; k <= r; k ++)
            if(i > mid)
                arr[k] = aux[j], j ++;
            else if(j > r)
                arr[k] = aux[i], res[aux[i].second] += j - mid - 1, i ++;
            else if(aux[i] <= aux[j])
                arr[k] = aux[i], res[aux[i].second] += j - mid - 1, i ++;
            else
                arr[k] = aux[j], j ++;
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