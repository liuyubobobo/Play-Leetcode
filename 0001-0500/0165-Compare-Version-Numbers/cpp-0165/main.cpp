/// Source : https://leetcode.com/problems/compare-version-numbers/
/// Author : liuyubobobo
/// Time   : 2021-08-31

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(|v1| + |v2|)
/// Space Complexity: O(|v1| + |v2|)
class Solution {
public:
    int compareVersion(string version1, string version2) {

        vector<int> v1 = get_ver(version1), v2 = get_ver(version2);

        while(v1.size() < v2.size()) v1.push_back(0);
        while(v2.size() < v1.size()) v2.push_back(0);
        return v1 == v2 ? 0 : (v1 < v2 ? -1 : 1);
    }

private:
    vector<int> get_ver(string s){

        vector<int> res;
        while(true){
            int p = s.find('.');
            if(p == string::npos){
                res.push_back(atoi(s.c_str()));
                break;
            }

            res.push_back(atoi(s.substr(0, p).c_str()));
            s = s.substr(p + 1);
        }
        return res;
    }
};


int main() {

    return 0;
}
