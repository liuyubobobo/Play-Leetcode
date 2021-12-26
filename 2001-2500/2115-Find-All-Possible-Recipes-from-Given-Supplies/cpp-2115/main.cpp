/// Source : https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
/// Author : liuyubobobo
/// Time   : 2021-12-26

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Brute Force DFS
/// Directed Graph Cycle Finding
/// Time Complexity: O(q(n + m))
/// Space Compplexity: O(n + m)
class Solution {

private:
    // 0-recipes; 1-ingredients
    map<string, int> str2index;
    vector<string> index2str;
    vector<int> is_ing;

public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        for(const string& recipe: recipes)
            if(!str2index.count(recipe)){
                str2index[recipe] = index2str.size();
                index2str.push_back(recipe);
                is_ing.push_back(0);
            }

        for(const vector<string>& v: ingredients)
            for(const string& ing: v)
                if(!str2index.count(ing)){
                    str2index[ing] = index2str.size();
                    index2str.push_back(ing);
                    is_ing.push_back(1);
                }

        vector<vector<int>> g(str2index.size(), vector<int>());
        for(int i = 0; i < ingredients.size(); i ++){
            assert(str2index.count(recipes[i]));
            int u = str2index[recipes[i]];
            for(const string& ing: ingredients[i]){
                assert(str2index.count(ing));
                int v = str2index[ing];
                g[u].push_back(v);
            }
        }

        set<string> all(supplies.begin(), supplies.end());

        vector<string> res;
        for(const string& recipe: recipes){
            assert(str2index.count(recipe));
            int s = str2index[recipe];
            vector<bool> visited(g.size(), false);
            vector<bool> instack(g.size(), false);
            if(!dfs(g, s, visited, instack)) continue;

            bool ok = true;
            for(int i = 0; i < g.size(); i ++)
                if(visited[i] && is_ing[i] && !all.count(index2str[i])){
                    ok = false;
                    break;
                }
            if(ok) res.push_back(recipe);
        }
        return res;
    }

private:
    bool dfs(const vector<vector<int>>& g, int u,
             vector<bool>& visited, vector<bool>& instack){

        assert(0 <= u && u < visited.size());
        visited[u] = true;
        instack[u] = true;
        for(int v: g[u])
            if(!visited[v]){
                if(!dfs(g, v, visited, instack)) return false;
            }
            else if(instack[v]) return false;
        instack[u] = false;
        return true;
    }
};


void print_vec(const vector<string>& v){
    for(const string& s: v) cout << s << ' '; cout << endl;
}

int main() {

    vector<string> recipes1 = {"bread","sandwich","burger"};
    vector<vector<string>> ingredients1 = {{"yeast","flour"},{"bread","meat"},{"sandwich","meat","bread"}};
    vector<string> supplies1 = {"yeast","flour","meat"};
    print_vec(Solution().findAllRecipes(recipes1, ingredients1, supplies1));
    // "bread","sandwich","burger"

    vector<string> recipe2 = {"ju","fzjnm","x","e","zpmcz","h","q"};
    vector<vector<string>> ingredients2 = {
            {"d"},
            {"hveml","f","cpivl"},
            {"cpivl","zpmcz","h","e","fzjnm","ju"},
            {"cpivl","hveml","zpmcz","ju","h"},
            {"h","fzjnm","e","q","x"},
            {"d","hveml","cpivl","q","zpmcz","ju","e","x"},
            {"f","hveml","cpivl"}
    };
    vector<string> supplies2 = {"f","hveml","cpivl","d"};
    print_vec(Solution().findAllRecipes(recipe2, ingredients2, supplies2));
    // ju fzjnm q

    return 0;
}
