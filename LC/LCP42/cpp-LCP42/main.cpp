/// Source : https://leetcode-cn.com/problems/vFjcfV/
/// Author : liuyubobobo
/// Time   : 2021-09-10

#include <iostream>
#include <vector>
#include <random>

using namespace std;


/// KDTree
/// Time Complexity: O((n + m) logn)
/// Space Complexity: O(n)
class KDTree{

private:
    class Node{
    public:
        vector<long long> v;
        int k;
        Node *left, *right;

        Node(const vector<long long>& v, int k): v(v), k(k), left(nullptr), right(nullptr){}
    };

    const int K;
    Node* root;

public:
    KDTree(int K) : K(K), root(nullptr){};

    void add(const vector<long long>& data){
        assert(data.size() == K);
        root = add(root, data, 0);
    }

    bool query(const vector<long long>& l, const vector<long long>& r,
               long long x, long long y, long long w){
        assert(l.size() == K);
        assert(r.size() == K);

        return query(root, 0, l, r, x, y, w);
    }

private:
    bool query(Node* node, int k, const vector<long long>& l, const vector<long long>& r,
               long long x, long long y, long long w){

        if(node == nullptr) return false;

        int in = in_range(node->v, l, r);
        if(in == K && (node->v[0] - x) * (node->v[0] - x) + (node->v[1] - y) * (node->v[1] - y) <= w * w)
            return true;

        long long p = node->v[k];
        if(r[k] <= p) return query(node->left, (k + 1) % K, l, r, x, y, w);
        else if(l[k] > p) return query(node->right, (k + 1) % K, l, r, x, y, w);
        else{
            return query(node->left, (k + 1) % K, l, r, x, y, w) ||
                   query(node->right, (k + 1) % K, l, r, x, y, w);
        }
    }

    int in_range(const vector<long long>& data, const vector<long long>& l, const vector<long long>& r){

        int in = 0;
        for(int i = 0; i < K; i ++)
            in += l[i] <= data[i] && data[i] <= r[i];
        return in;
    }

    Node* add(Node* node, const vector<long long>& data, int k){

        if(node == nullptr) return new Node(data, k);

        long long p = node->v[k];
        if(data[k] <= p) node->left = add(node->left, data, (k + 1) % K);
        else node->right = add(node->right, data, (k + 1) % K);
        return node;
    }
};

class Solution {
public:
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {

        shuffle(circles.begin(), circles.end(), default_random_engine());

        KDTree kdtree(2);
        for(const vector<int>& point: circles)
            kdtree.add({point[0], point[1]});

        int res = 0;
        for(const vector<int>& toy: toys){
            long long x = toy[0], y = toy[1], w = r - toy[2];
            if(w < 0) continue;

            if(kdtree.query({x - w, y - w}, {x + w, y + w}, x, y, w))
                res ++;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> toys1 = {{3, 3, 1}, {3, 2, 1}}, circles1 = {{4, 3}};
    cout << Solution().circleGame(toys1, circles1, 2) << endl;
    // 1

    vector<vector<int>> toys2 = {{1, 3, 2}, {4, 3, 1}, {7, 1, 2}}, circles2 = {{1, 0}, {3, 3}};
    cout << Solution().circleGame(toys2, circles2, 4) << endl;
    // 2

    return 0;
}
