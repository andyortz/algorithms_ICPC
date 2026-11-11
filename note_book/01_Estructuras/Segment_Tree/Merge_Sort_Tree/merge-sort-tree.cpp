// Tema: 01_Estructuras/Segment_Tree/Merge_Sort_Tree
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_C9CE48FCD91D6F00
#define NOTEBOOK_GENERADO_C9CE48FCD91D6F00
#include "../../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
// usage 
// vector<node*> nodes;
// tree.query(l, r, nodes);

// returns log(n) sorted segments in a range (l, r)

struct node {
    ll l, r;
    vl nums;
    vl prefix;
};
 
struct segtree {
    int n;
    vector<node> tree;
    void init(int nn, vl& nodes) {
        tree.clear();
        n = nn;
        if (n == 0) return; // build(0, 0, -1) no terminaría
        int size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.resize(size * 2);
        build(0, 0, n - 1, nodes);
    }
 
 
    void query(ll i, ll sl, ll sr, ll l, ll r, vector<node*> &ans) {
        if (l <= sl && sr <= r) {
            ans.pb(&tree[i]);
        } else if (sr < l || r < sl) {
 
        } else {
            int mid = (sl + sr) >> 1;
            query(i * 2 + 1, sl, mid, l, r, ans);
            query(i * 2 + 2, mid + 1, sr, l, r, ans);
        }
    }
 
    void query(ll l, ll r, vector<node*> &ans) { // [l, r]; rango vacío o n == 0 -> nada
        if (n == 0 || l > r) return;
        return query(0, 0, n - 1, l, r, ans);
    }
 
    void build(int nodei, int l, int r, vl &nums) {
        if (l == r) {
            tree[nodei].nums = { nums[l] };
            tree[nodei].prefix = {nums[l]};
            tree[nodei].l = l;
            tree[nodei].r = r;
        } else {
            ll mid = (l + r) >> 1;
            build(nodei * 2 + 1, l, mid, nums);
            build(nodei * 2 + 2, mid + 1, r, nums);
            ll a = tree[nodei*2+1].nums.size();
            ll b = tree[nodei*2+2].nums.size();
            tree[nodei].nums.reserve(a + b);
            tree[nodei].prefix.resize(a+b);
            ll i = 0;
            ll j = 0;
            while (i < a && j < b) {
                ll simon = tree[nodei*2+1].nums[i];
                ll simon2 = tree[nodei*2+2].nums[j];
                if (simon <= simon2) {
                    tree[nodei].nums.pb(simon);
                    i++;
                } else {
                    tree[nodei].nums.pb(simon2);
                    j++;
                }
            }
            while (i < a) {
                tree[nodei].nums.pb(tree[nodei*2+1].nums[i]);
                i++;
            }
            while (j < b) {
                tree[nodei].nums.pb(tree[nodei*2+2].nums[j]);
                j++;
            }
            tree[nodei].prefix[0] = tree[nodei].nums[0];
            for (int i = 1; i < a + b; i++) {
                tree[nodei].prefix[i] = tree[nodei].prefix[i - 1] + tree[nodei].nums[i];
            }
            tree[nodei].l = l;
            tree[nodei].r = r;
        }
    }
};
#endif
