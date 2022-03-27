#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {

public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {

        set<long long> data_set;
        string s(intLength, ' ');
        dfs(s, 0, intLength, data_set);

        vector<long long> data(data_set.begin(), data_set.end());
        vector<long long> res(queries.size(), -1);
        for(int i = 0; i < queries.size(); i ++){
            int q = queries[i] - 1;
            if(q < data.size()) res[i] = data[q];
        }
        return res;
    }

private:
    void dfs(string& s, int index, int len, set<long long>& data){

        if(index > len - index - 1){
            data.insert(atoll(s.c_str()));
            return;
        }

        for(int d = (index == 0 ? 1 : 0); d <= 9; d ++){
            s[index] = s[len - index - 1] = (char)('0' + d);
            dfs(s, index + 1, len, data);
        }
    }
};

int main() {

    vector<int> queries1 = {97,902143467,332084633,15,139128663,347073005,167961442,32,15};
    Solution().kthPalindrome(queries1, 11);

    return 0;
}
