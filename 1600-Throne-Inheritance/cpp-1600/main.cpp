/// Source : https://leetcode.com/problems/throne-inheritance/
/// Author : liuyubobobo
/// Time   : 2020-09-26

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;


/// Tree
/// Time Complexity: init: O(1)
///                  birth: O(1)
///                  death: O(1)
///                  getInheritanceOrder: O(n)
/// Space Complexity: O(n)
class ThroneInheritance {

private:
    unordered_set<string> live;
    unordered_map<string, vector<string>> R;
    string king;

public:
    ThroneInheritance(const string& kingName) : king(kingName) {
        live.clear();
        live.insert(kingName);

        R.clear();
    }

    void birth(const string& parentName, const string& childName) {
        R[parentName].push_back(childName);
        live.insert(childName);
    }

    void death(const string& name) {
        live.erase(name);
    }

    vector<string> getInheritanceOrder() {

        vector<string> res;
        dfs(king, res);
        return res;
    }

private:
    void dfs(const string& name, vector<string>& res){

        if(live.count(name)) res.push_back(name);

        if(R[name].empty()) return;

        for(const string& s: R[name]) dfs(s, res);
    }
};


void print_vec(const vector<string>& v){
    for(const string& e: v) cout << e << " "; cout << endl;
}

int main() {

    ThroneInheritance t("king");

    t.birth("king", "andy");
    print_vec(t.getInheritanceOrder());
    // king > andy

    t.birth("king", "bob");
    print_vec(t.getInheritanceOrder());
    // king > andy > bob

    t.birth("king", "catherine");
    print_vec(t.getInheritanceOrder());
    // king > andy > bob > catherine

    t.birth("andy", "matthew");
    print_vec(t.getInheritanceOrder());
    // king > andy > matthew > bob > catherine

    t.birth("bob", "alex");
    print_vec(t.getInheritanceOrder());
    // king > andy > matthew > bob > alex > catherine

    t.birth("bob", "asha");
    print_vec(t.getInheritanceOrder());
    // king > andy > matthew > bob > alex > asha > catherine

    t.death("bob");
    print_vec(t.getInheritanceOrder());
    // king > andy > matthew > bob(death) > alex > asha > catherine

    return 0;
}
