/// Source : https://leetcode.cn/contest/autox2023/problems/TcdlJS/
/// Author : liuyubobobo
/// Time   : 2022-08-29

#include <iostream>
#include <vector>
#include <complex>
#include <cassert>

#define X real()
#define Y imag()

using namespace std;

typedef complex<long long> P;


/// 线段与圆相交，使用线段的参数方程
/// x = t * x1 + (1 - t) * x2
/// y = t * y1 + (1 - t) * y2
/// t 在 [0, 1] 之间
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)

long long cross_product(P a, P b){
    return (conj(a) * b).Y; // a.X * b.Y - b.X * a.Y
}

// 1  : left
// 0  : touch
// -1 : right
int test_point_loc(P p, P s1, P s2){
    double res = cross_product(p - s1, p - s2);
    if(res == 0ll) return 0;
    return res > 0 ? 1 : -1;
}

bool seg_intersect(long long x1, long long y1, long long x2, long long y2,
                   long long x3, long long y3, long long x4, long long y4){

    P p1 = {x1, y1}, p2 = {x2, y2};
    P p3 = {x3, y3}, p4 = {x4, y4};

    int loc1 = test_point_loc(p1, p3, p4), loc2 = test_point_loc(p2, p3, p4);
    int loc3 = test_point_loc(p3, p1, p2), loc4 = test_point_loc(p4, p1, p2);
    if(loc1 == 0 && min(x3, x4) <= x1 && x1 <= max(x3, x4)
       && min(y3, y4) <= y1 && y1 <= max(y3, y4)){
        return true;
    }
    if(loc2 == 0 && min(x3, x4) <= x2 && x2 <= max(x3, x4)
       && min(y3, y4) <= y2 && y2 <= max(y3, y4)){
        return true;
    }
    if(loc3 == 0 && min(x1, x2) <= x3 && x3 <= max(x1, x2)
       && min(y1, y2) <= y3 && y3 <= max(y1, y2)){
        return true;
    }
    if(loc4 == 0 && min(x1, x2) <= x4 && x4 <= max(x1, x2)
       && min(y1, y2) <= y4 && y4 <= max(y1, y2)){
        return true;
    }

    if(!loc1 || !loc2 || !loc3 || !loc4){
        return false;
    }

    if(loc1 * loc2 > 0 || loc3 * loc4 > 0)
        return false;

    return true;
}

class UF{

private:
    vector<int> parent;

public:
    UF(int n) : parent(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool is_connected(int p, int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
    }
};

class Solution {
public:
    vector<bool> antPass(vector<vector<int>>& geometry, vector<vector<int>>& path) {

        int n = geometry.size();
        UF uf(n);

        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++){

                if(uf.is_connected(i, j)) continue;

                vector<int> v1 = geometry[i];
                vector<int> v2 = geometry[j];
                if(v1.size() > v2.size()) swap(v1, v2);

                // v1.size() <= v2.size()
                if(intersect(v1, v2))
                    uf.union_elements(i, j);
            }

        vector<bool> res(path.size());
        for(int i = 0; i < path.size(); i ++)
            res[i] = uf.is_connected(path[i][0], path[i][1]);
        return res;
    }

private:
    bool intersect(const vector<int>& v1, const vector<int>& v2){

        if(v1.size() == 3 && v2.size() == 3)
            return circle_intersect(v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);

        if(v1.size() == 4 && v2.size() == 4)
            return seg_intersect(v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3]);

        return circle_seg_intersect(v1[0], v1[1], v1[2], v2[0], v2[1], v2[2], v2[3]);
    }

    int sign(long long x){
        if(x > 0) return 1;
        if(x == 0) return 0;
        return -1;
    }

    bool circle_seg_intersect(long long x0, long long y0, long long r0,
                              long long x1, long long y1, long long x2, long long y2){

        long long a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        long long b = 2ll * (x1 - x2) * (x2 - x0) + 2ll * (y1 - y2) * (y2 - y0);
        long long c = (x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0) - r0 * r0;

        if(a == 0 && b == 0) return c == 0;

        if(a == 0){
            if(b < 0) b = -b, c = -c;
            return 0 <= -c && -c <= b;
        }

        if(a < 0){
            a = -a, b = -b, c = -c;
        }

        long double delta = (long double)b * b - 4.0 * (long double)a * c;
        if(delta < 0) return false;

        long double t1 = ((long double)(-b) - sqrt(delta)) / (2.0 * (long double)a);
        if(0.0 <= t1 && t1 <= 1.0) return true;

        long double t2 = ((long double)(-b) + sqrt(delta)) / (2.0 * (long double)a);
        if(0.0 <= t2 && t2 <= 1.0) return true;

        return false;
    }

    bool circle_intersect(long long x1, long long y1, long long r1,
                          long long x2, long long y2, long long r2){

        long long d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        return (r1 - r2) * (r1 - r2) <= d2 && d2 <= (r1 + r2) * (r1 + r2);
    }
};


void print_vec(const vector<bool>& res){
    for(bool e: res) cout << e << ' '; cout << '\n';
}

int main(){

    vector<vector<int>> g1 = {{2, 5, 7, 3}, {1, 1, 4, 2}, {4, 3, 2}};
    vector<vector<int>> p1 = {{0, 1}, {1, 2}, {0, 2}};
    print_vec(Solution().antPass(g1, p1));
    // 1 1 1

    vector<vector<int>> g2 = {{4, 1, 1}, {3, 2, 1}, {1, 4, 5, 4}};
    vector<vector<int>> p2 = {{0, 1}, {2, 0}};
    print_vec(Solution().antPass(g2, p2));
    // 1 0

    vector<vector<int>> g3 = {{5, 6, 5, 8}, {4, 3, 6, 4}, {2, 6, 5, 6}, {0, 5, 0, 6}, {4, 0, 6, 0}};
    vector<vector<int>> p3 = {{2, 0}, {2, 4}};
    print_vec(Solution().antPass(g3, p3));
    // 1 0

    vector<vector<int>> g4 = {{3, 2, 6, 2}, {9, 0, 10, 0}, {3, 0, 6, 0}, {7, 2, 9, 3}, {4, 1, 5, 2}};
    vector<vector<int>> p4 = {{0, 1}, {3, 4}, {0, 3}};
    print_vec(Solution().antPass(g4, p4));
    // 0 0 0

    vector<vector<int>> g5 = {{8, 8, 6}, {1, 1, 1, 2}, {1, 1, 3, 2}, {4, 3, 4, 4}, {2, 1, 5, 3}};
    vector<vector<int>> p5 = {{0, 4}, {3, 1}};
    print_vec(Solution().antPass(g5, p5));
    // 1 0

    return 0;
}
