/// Source : https://leetcode.com/problems/design-search-autocomplete-system/
/// Author : liuyubobobo
/// Time   : 2019-07-30

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Two level HashMap
/// Time Complexity: init: O(n)
///                  input: O(n * l + nlogn) where l is len(cur)
/// Space Complexity: O(n + num_of_#)
class AutocompleteSystem {

private:
    vector<unordered_map<string, int>> map;
    string cur = "";

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {

        map.resize(26);
        for(int i = 0; i < sentences.size(); i ++)
            map[sentences[i][0] - 'a'][sentences[i]] = times[i];
    }

    vector<string> input(char c) {

        if(c == '#'){
            map[cur[0] - 'a'][cur] ++;
            cur = "";
            return {};
        }

        cur += c;
        vector<pair<int, string>> candidates;
        for(const pair<string, int>& p: map[cur[0] - 'a']){
//            cout << p.first.find(cur) << endl;
            if(p.first.find(cur) == 0)
                candidates.push_back(make_pair(p.second, p.first));
        }
        sort(candidates.begin(), candidates.end(),
             [](const pair<int, string>& p1, const pair<int, string>& p2){
            if(p1.first != p2.first) return p1.first > p2.first;
            return p1.second < p2.second;
        });

        vector<string> res;
        for(int i = 0; i < min((int)candidates.size(), 3); i ++)
            res.push_back(candidates[i].second);
        return res;
    }
};


void print_vec(const vector<string>& vec){
    for(const string& e: vec) cout << e << endl;
}

int main() {

    vector<string> sentences = {"i love you","island","iroman","i love leetcode"};
    vector<int> times = {5, 3, 2, 2};
    AutocompleteSystem sys(sentences, times);
    print_vec(sys.input('i'));
    print_vec(sys.input(' '));
    print_vec(sys.input('a'));

    return 0;
}