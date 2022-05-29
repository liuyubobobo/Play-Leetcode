/// Source : https://leetcode.com/problems/apply-discount-to-prices/
/// Author : liuyubobobo
/// Time   : 2022-05-29

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string discountPrices(string sentence, int discount) {

        vector<string> words;
        for(int start = 0, i = 1; i <= sentence.size(); i ++)
            if(i == sentence.size() || sentence[i] == ' '){
                words.push_back(sentence.substr(start, i - start));
                start = i + 1;
                i = start;
            }

        for(string& word: words)
            if(is_price(word)){
                long long price = atoll(word.substr(1).c_str());
                price *= (100 - discount);

                string new_s = to_string(price);
                while(new_s.size() < 3)  new_s = "0" + new_s;

                int len = new_s.size();
                word = "$" + new_s.substr(0, len - 2) + "." + new_s.substr(len - 2);
            }

        string res = "";
        for(int i = 0; i < words.size(); i ++){
            res += words[i];
            if(i + 1 != words.size()) res += " ";
        }
        return res;
    }

private:
    bool is_price(const string& s){

        if(s.size() == 1) return false;

        if(s[0] != '$') return false;

        for(int i = 1; i < s.size(); i ++)
            if(!isdigit(s[i])) return false;

        return true;
    }
};


int main() {

    return 0;
}
