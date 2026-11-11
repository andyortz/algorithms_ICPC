// Tema: 08_Strings/Aho_Corasick
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_C211C809CEA26F1A
#define NOTEBOOK_GENERADO_C211C809CEA26F1A
#include "../../_base/template-simple.hpp"

// El trie (o prefix tree) guarda un diccionario de 
// strings como un arbol enraizado.
// Aho corasick permite encontrar las ocurrencias 
// de todos los strings del trie en un 
// string s O(n*sqrt(n))

const int alpha = 26;
const char L = 'a';

struct node {
    int next[alpha], end;
    // link -> back-edge, exit -> super link, 
    // cnt -> saber para conteo de posibles
    // a lo mucho es: n*sqrt(n)
    int link = 0, exit = 0, cnt; // para aho corasick
    int& operator [] (int i) { return next[i]; }
};

vector<node> trie = {node()};

void add_str(string &s, int id = 1) {
    int u = 0;
    for (auto ch : s) {
        int c = ch-L;
        if (!trie[u][c]) {
            trie[u][c] = trie.size();
            trie.pb(node());
        }
        u = trie[u][c];
    }
    trie[u].end = id; // con id > 0
    // trie[u].cnt++; // para aho corasick
}

// aho corasick
void build_ac() {
    queue<int> q; q.push(0);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int c = 0; c < alpha; ++c) {
            int v = trie[u][c];
            if (!v) trie[u][c] = trie[trie[u].link][c];
            else q.push(v);
            if (!u || !v) continue;
            trie[v].link = trie[trie[u].link][c];
            trie[v].exit = trie[trie[v].link].end ? 
              trie[v].link : trie[trie[v].link].exit;
            trie[v].cnt += trie[trie[v].link].cnt;
        }
    }
}

// cantidad de ocurrencias en s para cada patron
vector<int> cnt; 

void run_ac(string &s) {
    int u = 0, sz = s.size();
    for (int i = 0; i < sz; ++i) {
        int c = s[i]-L;
        while (u && !trie[u][c]) u = trie[u].link;
        u = trie[u][c];
        int x = u;
        while (x) {
            int id = trie[x].end;
            if (id) cnt[id-1]++;
            x = trie[x].exit;
        }
    }
}
#endif
