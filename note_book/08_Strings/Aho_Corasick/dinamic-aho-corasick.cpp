// Tema: 08_Strings/Aho_Corasick
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_D9718957EBDEF1F6
#define NOTEBOOK_GENERADO_D9718957EBDEF1F6
#include "../../_base/template-simple.hpp"

const int alpha = 26;
int node[20][tam][alpha];
struct ahoCorasick
{
    int root, nnode;
    int link[tam], cnt[tam], id;
    bool dead;

    void init(int idx)
    {
        dead = false; id = idx; root = 0; nnode = 0;
        mem(node[id][root], 0);
        for (int i=(0), nb_fin_1=(nnode + 1); i<nb_fin_1; ++i) cnt[i] = 0;
    }
    void clear()
    {
        dead = true;
    }
    void insert(string &s, int val)
    {
        int len = s.size();
        int now = root;

        for (int i=(0), nb_fin_3=(len); i<nb_fin_3; ++i)
        {
            int nxt = s[i] - 'a';
            if(!node[id][now][nxt])
            {
                node[id][now][nxt] = ++nnode;
                mem(node[id][nnode],0);
                cnt[nnode] = 0;
            }

            now=node[id][now][nxt];
        }
        cnt[now] += val;
    }
    void insertdict(vector<string> &dict, vector<int> &vals)
    {
        for (int i=(0), nb_fin_5=(sz(dict)); i<nb_fin_5; ++i) insert(dict[i], vals[i]);
    }
    void pushLinks()
    {
        queue<int> Q; link[root]=-1;
        Q.push(root);
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();

            for (int i=(0), nb_fin_7=(alpha); i<nb_fin_7; ++i)
            {
                if(!node[id][u][i]) continue;
                int v = node[id][u][i];
                int l = link[u];

                while(l != -1 && !node[id][l][i]) l = link[l];
                if(l!=-1) link[v] = node[id][l][i];
                else link[v] = 0;
                cnt[v] += cnt[link[v]];
                Q.push(v);
            }
        }
    }
    int query(string &p)
    {
        int u = root, ret = 0;
        for(char ch : p)
        {
            int nxt = ch - 'a';
            while(u != -1 && !node[id][u][nxt]) u = link[u];
            if(u == -1) u = 0;
            else u = node[id][u][nxt];
            ret += cnt[u];
        }
        return ret;
    }
} aho[20];

vector<string> dict[20];
vector<int> vals[20];

void add(string &s, int val)
{
    dict[0].pb(s);
    vals[0].pb(val);
    for (int i=(0), nb_fin_9=(20); i<nb_fin_9; ++i)
    {
        if(sz(dict[i]) > (1<<i))
        {
            for(auto it : dict[i]) dict[i + 1].pb(it);
            for(auto it : vals[i]) vals[i + 1].pb(it);
            dict[i].clear();
            vals[i].clear();
            aho[i].clear();
        }
        else
        {
            aho[i].init(i);
            aho[i].insertdict(dict[i], vals[i]);
            aho[i].pushLinks();
            break;
        }
    }
}
#endif
