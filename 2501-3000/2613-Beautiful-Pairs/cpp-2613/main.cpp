#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        vector<tuple<int, int, int>> points(n);
        for(int i = 0; i < n; i ++)
            points[i] = {nums1[i] + nums2[i], nums1[i] - nums2[i], i};


    }
};


int main() {

    return 0;
}
