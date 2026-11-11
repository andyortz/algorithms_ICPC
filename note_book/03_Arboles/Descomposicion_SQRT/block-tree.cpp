// Tema: 03_Arboles/Descomposicion_SQRT
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_42D0110980810465
#define NOTEBOOK_GENERADO_42D0110980810465
#include "../../_base/template-simple.hpp"
using ll = long long;
/*
SQRT on Trees. 
For having queries and updates online to subtrees or sub forests. 
See: https://codeforces.com/blog/entry/46843
Solution to: https://codeforces.com/gym/100589/problem/A
Properties:
  - Each node will have atmost SQRT children nodes in Block Tree
  - There will be atmost SQRT Blocks 
  - There will be atmost SQRT nodes belongs to a block
  - Not completely sure, but for merging answers of childs it should be fast
*/

struct Block { // Block storing info depending of problem!!!
    // O(n) memory here is possible, but better O(sqrt n) to BlockTree creation be O(n)
    vector<int> depthCnt;
    ll sum = 0;

    void update(int lvl, ll v) { // !!! depends of problem
        if (lvl >= depthCnt.size()) return;
        sum += v * depthCnt[lvl];
    }

    ll query() { return sum; }
};
struct BlockTree {
    const int SQRT = 320; // sqrt of max N
    ll n;
    vector<Block> blocks; 
    vector<vector<int>> child; // if node < n,then normal node, otherwise block node
    vector<int> depth;
    vector<int> leader; // for the sqrt group of nodes the first ancestor that is not in the group
    vector<int> blockId;

    // ===== depends of the problem!!!
    vector<ll> sum;
    // =====

    BlockTree(ll n, vector<vector<ll>> &adj) : n(n), child(2*n+5), depth(2*n+5), 
                                                       leader(2*n+5), blockId(2*n+5) {
        sum = vector<ll>(n);
        build(adj); // adjacency should be x -> y, and y -> x
    }

    bool is_block(ll x) { return x >= n; }

    void build(vector<vector<ll>> &adj, ll root = 0) {
        auto dfs = [&](ll x, ll p, auto &&dfs) -> void {
            for (auto y : adj[x]) if (y != p) {
                depth[y] = depth[x]+1;
                dfs(y,x,dfs);
            }
        };
        dfs(root, -1, dfs); // !!! Don't forget
        
        ll idNewBlock = n;
        auto createBlock = [&](int parent, const vector<ll> &nodes) {
            ll id = idNewBlock++;
            if (parent != -1) {
                child[parent].push_back(id);
                depth[id] = depth[parent]+1;
            }

            Block block; // Modify the creation of your block here!!!
            leader[id] = parent;
            blockId[id] = id;
            block.depthCnt = vector<int>(n);

            auto dfsOverBlock = [&](ll x, auto &&dfsOverBlock)->void {
                leader[x] = parent;
                blockId[x] = id;
                block.depthCnt[depth[x]]++;
                for (auto y : child[x]) {
                    if (!is_block(y)) dfsOverBlock(y, dfsOverBlock);
                    else child[id].push_back(y); // depending of the problem, you can add 
                    // relationship between block node -> node or block node -> block node, like this
                }    
            };
            for (auto & x : nodes) dfsOverBlock(x, dfsOverBlock);
            blocks.push_back(block);
        };

        vector<vector<ll>> byDepth(n); // counting sort
        for (int i =0;i<n;i++) byDepth[n-1-depth[i]].pb(i);
        vector<ll> sz(n);
        for (auto & nodes : byDepth) {
            for (int x : nodes) {
                ll blockSz = 0;
                vector<ll> curBlock;
                sz[x] = 1;

                for (int y : adj[x]) if (depth[x] < depth[y]) {
                    sz[x] += sz[y];
                    blockSz += sz[y];
                    curBlock.pb(y);
                    if (blockSz > SQRT) {
                        createBlock(x, curBlock);
                        sz[x] -= blockSz;
                        blockSz = 0;
                        curBlock.clear();
                    }
                }
                child[x].insert(child[x].end(), curBlock.begin(), curBlock.end());
            }
        }
        createBlock(-1, { root }); 
    }

    void update(int lvl, ll v) {
        sum[lvl] += v;
        for (auto & block : blocks) {
            block.update(lvl, v);
        }
    }

    ll query(ll x) { // dfs over node blocks and non node blocks
        ll ans = is_block(x) ? blocks[x-n].query() : sum[depth[x]];
        for (auto & y : child[x]) 
            ans += query(y);
        return ans;
    }
};
#endif
