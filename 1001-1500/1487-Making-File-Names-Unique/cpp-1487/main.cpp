/// Source : https://leetcode.com/problems/making-file-names-unique/
/// Author : liuyubobobo
/// Time   : 2020-06-20

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n?)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

        unordered_map<string, int> table;
        vector<string> res(names.size());
        string e, t;
        for(int k = 0; k < names.size(); k ++){
            e = names[k];
            if(table.count(e)){
                for(int i = table[e]; ; i ++){
                    t = e + "(" + to_string(i) + ")";
                    if(!table.count(t)) break;
                    else table[e] ++;
                }
                table[t] ++;
                res[k] = t;
            }
            else {
                table[e] ++;
                res[k] = e;
            }
        }
        return res;
    }
};


void print_vec(const vector<string>& v){
    for(const string& e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<string> names1 = {"pes","fifa","gta","pes(2019)"};
    print_vec(Solution().getFolderNames(names1));
    // "pes","fifa","gta","pes(2019)"

    vector<string> names2 = {"gta","gta(1)","gta","avalon"};
    print_vec(Solution().getFolderNames(names2));
    // "gta","gta(1)","gta(2)","avalon"

    vector<string> names3 = {"onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece"};
    print_vec(Solution().getFolderNames(names3));
    // "onepiece","onepiece(1)","onepiece(2)","onepiece(3)","onepiece(4)"

    vector<string> names4 = {"wano","wano","wano","wano"};
    print_vec(Solution().getFolderNames(names4));
    // "wano","wano(1)","wano(2)","wano(3)"

    vector<string> names5 = {"kaido","kaido(1)","kaido","kaido(1)"};
    print_vec(Solution().getFolderNames(names5));
    // "kaido","kaido(1)","kaido(2)","kaido(1)(1)"

    return 0;
}