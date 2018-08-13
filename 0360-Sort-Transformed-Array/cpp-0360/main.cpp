/// Source : https://leetcode.com/problems/sort-transformed-array/description/
/// Author : liuyubobobo
/// Time   : 2016-12-26

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;


/// Mathematics
/// Based on the middle axis -b/(2a) to get the proper order of the transformation
/// Need to pay attention when a == 0
///
/// Time Complexity:  O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sortTransformedArray(const vector<int>& nums, int a, int b, int c) {

        vector<int> res;

        if(a == 0){
            // If a == 0, the result of the transform is linear
            for(int i = 0 ; i < nums.size() ; i ++)
                res.push_back(applyTransform(nums[i], a, b, c));

            // If b < 0, we need to reverse the result to make the res be sorted
            // from small elements to large elements
            if(b < 0)
                reverseArray(res);
        }
        else{
            // If a != 0, we need to find the middle axis first
            // which can be calculated as - b / 2*a
            double m = - double(b) / double(2 * a);
            //cout<<"m = "<<m<<endl;

            // Then, find the first element index which is larger or equal than m
            int r = bsearch(nums, m);
            int l = r - 1;
            //cout<<"l = "<<l<<" , r = "<<r<<endl;

            // Similar to merge process,
            // we use the two pointers tecnique to make the transform in order
            while(l >= 0 || r < nums.size()){
                if(l == -1)
                    res.push_back(applyTransform(nums[r++], a, b, c));
                else if(r == nums.size())
                    res.push_back(applyTransform(nums[l--], a, b, c));
                else if(m - double(nums[l]) <= double(nums[r]) - m)
                    res.push_back(applyTransform(nums[l--], a, b, c));
                else // m - double(nums[l]) > double(nums[r]) - m
                    res.push_back(applyTransform(nums[r++], a, b, c));
            }

            // If a < 0, we need to reverse the result to make the res be sorted
            if(a < 0)
                reverseArray(res);
        }

        return res;
    }

private:
    int applyTransform(int x, int a, int b, int c){
        return a * x * x + b * x + c;
    }

    void reverseArray(vector<int> &v){
        int i = 0, j = v.size() - 1;
        while(i < j)
            swap(v[i ++] , v[j --]);
        return;
    }

    // Find the index of first element >= target
    int bsearch(const vector<int> &vec, double target){

        int l = 0, r = vec.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(vec[m] < target)
                l = m + 1;
            else // vec[m] >= target
                r = m;
        }

        assert(l == r);
        return r;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums = {-4, -2, 2, 4};
    print_vec(Solution().sortTransformedArray(nums, 1, 3, 5));
    print_vec(Solution().sortTransformedArray(nums, -1, 3, 5));

    return 0;
}