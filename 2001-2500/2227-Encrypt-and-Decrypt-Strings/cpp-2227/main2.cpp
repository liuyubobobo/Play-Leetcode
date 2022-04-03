/// Source : https://leetcode.com/problems/encrypt-and-decrypt-strings/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Reverse Thinking, Store all encrypt result in dictionary
/// Time Complexity: init: O(|keys| + |values| + |dictionary|)
///                  encrypt: O(|word1|)
///                  decrypt: O(|word2|)
/// Space Compelxity: O(|keys| + |values| + |dictionary|)
class Encrypter {

private:
    vector<int> char2index;
    vector<string> index2values;
    map<string, int> table;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) :
            char2index(256, -1), index2values(values){

        for(int i = 0; i < keys.size(); i ++)
            char2index[keys[i]] = i;

        for(const string& s: dictionary)
            table[encrypt(s)] ++;
    }

    string encrypt(string word1) {

        string res = "";
        for(char c: word1)
            res += index2values[char2index[c]];
        return res;
    }

    int decrypt(string word2) {
        return table[word2];
    }
};


int main() {

    return 0;
}
