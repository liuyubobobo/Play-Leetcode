/// Source : https://leetcode.com/problems/beautiful-arrangement-ii/
/// Author : liuyubobobo
/// Time   : 2021-01-03

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> constructArray(int n, int k) {

        vector<int> arr(n);

        int l = 1, r = n;
        for(int i = 0; i < k; i += 2){
            arr[i] = l ++;
            if(i + 1 == k){
                for(int j = k; j < n; j ++) arr[j] = l ++;
                break;
            }

            arr[i + 1] = r --;
            if(i + 2 == k){
                for(int j = k; j < n; j ++) arr[j] = r --;
                break;
            }
        }

        return arr;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    print_vec(Solution().constructArray(3, 1));
    // 1 2 3

    print_vec(Solution().constructArray(3, 2));
    // 1 3 2

    return 0;
}
