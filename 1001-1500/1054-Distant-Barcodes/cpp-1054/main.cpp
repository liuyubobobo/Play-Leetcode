/// Source : https://leetcode.com/problems/distant-barcodes/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        int n = barcodes.size();
        map<int, int> f;
        for(int barcode : barcodes) f[barcode]++;

        vector<pair<int, int>> v;
        for(const pair<int, int>& p: f) v.push_back(p);

        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<int> res(n);
        for(int i = 0; i < n; i += 2){
            res[i] = v.back().first;
            v.back().second --;
            if(v.back().second == 0) v.pop_back();
        }
        for(int i = 1; i < n; i += 2){
            res[i] = v.back().first;
            v.back().second --;
            if(v.back().second == 0) v.pop_back();
        }
        return res;
    }
};


int main() {

    return 0;
}
