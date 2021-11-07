/// Source : https://leetcode.com/problems/multiply-strings/
/// Author : liuyubobobo
/// Time   : 2021-11-07

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0") return "0";

        vector<int> v1, v2;
        for(int i = num1.size() - 1; i >= 0; i --) v1.push_back(num1[i] - '0');
        for(int i = num2.size() - 1; i >= 0; i --) v2.push_back(num2[i] - '0');

        vector<int> res = {0};
        for(int i = 0; i < v1.size(); i ++){
            vector<int> tres = mul(v2, v1[i]);
            reverse(tres.begin(), tres.end());
            for(int j = 0; j < i; j ++) tres.push_back(0);
            reverse(tres.begin(), tres.end());

            add(res, tres);
        }

        while(res.back() == 0) res.pop_back();
        assert(res.size());

        string s = "";
        for(int i = res.size() - 1; i >= 0; i --) s += string(1, '0' + res[i]);
        return s;
    }

private:
    void add(vector<int>& res, vector<int>& tres){

        while(res.size() < tres.size()) res.push_back(0);
        while(tres.size() < res.size()) tres.push_back(0);

        int carry = 0;
        for(int i = 0; i < tres.size(); i ++){
            int t = res[i] + tres[i] + carry;
            res[i] = t % 10;
            carry = t >= 10;
        }
        if(carry) res.push_back(1);
    }

    vector<int> mul(const vector<int>& v, int m){
        assert(0 <= m && m < 10);

        vector<int> res;
        int carry = 0;
        for(int i = 0; i < v.size(); i ++){
            res.push_back((v[i] * m + carry) % 10);
            carry = (v[i] * m + carry) / 10;
        }
        if(carry) res.push_back(carry);
        return res;
    }
};


int main() {

    cout << Solution().multiply("2", "3") << endl;
    // 6

    cout << Solution().multiply("123", "456") << endl;
    // 56088

    return 0;
}
