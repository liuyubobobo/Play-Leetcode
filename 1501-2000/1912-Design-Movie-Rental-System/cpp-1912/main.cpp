/// Source : https://leetcode.com/problems/design-movie-rental-system/
/// Author : liuyubobobo
/// Time   : 2021-06-27

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


/// Using TreeMap and TreeSet
/// Time Complexity: init: O(nlogn)
///                  search, drop: O(1)
///                  rent, drop: O(logn)
/// Space Complexity: O(n)
class MovieRentingSystem {

private:
    map<pair<int, int>, int> prices;

    vector<set<pair<int, int>>> movies; // movie_id -> price, shop_id
    map<int, map<int, set<int>>> rented; // price -> shop -> movie

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) : movies(10001) {

        for(const vector<int>& e: entries){
            movies[e[1]].insert({e[2], e[0]});
            prices[{e[0], e[1]}] = e[2];
        }

    }

    vector<int> search(int movieid) {

        set<pair<int, int>>::iterator iter = movies[movieid].begin();
        int k = 0;
        vector<int> res;
        while(k < 5 && iter != movies[movieid].end()){
            res.push_back(iter->second);
            k ++;
            iter ++;
        }
        return res;
    }

    void rent(int shopid, int movieid) {

        int price = prices[{shopid,movieid}];
        movies[movieid].erase({price, shopid});

        rented[price][shopid].insert(movieid);
    }

    void drop(int shopid, int movieid) {

        int price = prices[{shopid,movieid}];

        movies[movieid].insert({price, shopid});

        rented[price][shopid].erase(movieid);
        if(rented[price][shopid].empty()) rented[price].erase(shopid);
        if(rented[price].empty()) rented.erase(price);
    }

    vector<vector<int>> report() {

        vector<vector<int>> res;
        for(const pair<int, map<int, set<int>>>& p1: rented){
            int price = p1.first;
            for(const pair<int, set<int>>& p2: p1.second){
                int shopid = p2.first;
                for(int movieid: p2.second){
                    res.push_back({shopid, movieid});
                    if(res.size() == 5) return res;
                }
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
