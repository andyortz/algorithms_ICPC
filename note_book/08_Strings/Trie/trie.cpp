// Requisito de selección: Contiene dominios distintos (letras, bits y comodines) con nombres repetidos y errores de índice/typos del original; requiere separar namespaces, inicializar contadores y completar go/ter.
// Tema: 08_Strings/Trie
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_D66923ADF1C4EB47
#define NOTEBOOK_GENERADO_D66923ADF1C4EB47
#include "../../_base/template-simple.hpp"

const int MAXSIZE = 26;
struct node {
	int end;
	int grafo[MAXSIZE]
	node() {
		for (int i =0 ; i<MAXSIZE; i++) grafo[i] = 0;
	}
};
vector<node> v(1);
node ini;
void insert(string &s, int i = 0, int j = 0) {
	if (j>size(s)) {
		v[i].end = 1;
		return;
	}
	int to = s[j]-'a';
	if (!v[i].grafo[to]) v[i].grafo[to] = v.size(), v.pb(ini);
	insert(s, v[i].grafo[to], j+1);
}
void erase(string &s, int i = 0, int j = 0) {
	if (j>size(s)) {v[i].end = 0; return;}
	int to = s[j]-'a';
	if (!v[i].grafo[to]) return;
	return erase(s, v[i].grafo[to], j+1);
}
int get(string &s, int i = 0, int j = 0) {
	if (j>size(s)) return v[i].end;
	int to = s[j]-'a';
	if (v[i].grafo[to]) return get(s, v[i].grafo[to], j+1);
}

/*FOR BITS:*/
const int MAXSIZE = 2;
struct node {
    int c;
    int grafo[MAXSIZE];
    node() {grafo[0] = grafo[1] = 0;}
};
vector<node> v(1);
node ini;
void insert(int x, int i = 0, int j = 30) {
    v[i].c++;
    if (j==-1) return;
    int to = (x>>j)&1;
    if (!v[i].grafo[to]) 
        v[i].grafo[to] = v.size(), v.pb(ini);
    insert(x, v[i].grafo[to], j-1);
}
void erase(int x, int i = 0, int j = 30) {
    v[i].c--;
    if (j==-1) return;
    int to = (x>>j)&1;
    erase(x, v[i].grafo[to], j-1);
}
int get(int x, int i = 0, int j = 30) {
	// modify this function based on the problem.
    if (j==-1) return 0;
    int to = 1^((x>>j)&1);
    if (!v[i].grafo[to] || !v[v[i].grafo[to]].c) to ^= 1;
    if (!v[i].grafo[to] || !v[v[i].grafo[to]].c) return 0;
    return (to<<j) + get(x, v[i].grafo[to], j-1);
}

/* potente: */
struct node;
extern vector<node> trie;
struct node {
    int v[MAXSIZE];
    int end;
    node() {
		for (int i =0 ; i<MAXSIZE; i++) v[i] = 0; end =0 ;
	}
    int go(char c) {return (!v[c-'a']? -1: v[c-'a']);}
    void set(char c) {
        v[c-'a'] = (int)trie.size();
        trie.emplace_back(node());
    }
};
vector<node> trie(1);

void add(string &s, int j) {
    int i = 0;
    for (auto &c: s) {
        if (trie[i].go(c) == -1) trie[i].set(c);
        i = trie[i].go(c);
    }
    trie[i].ter = j;
}
vector<int> find (string &s) {
    vector<int> res;

    auto dfs = [&](int i, int j, auto &&dfs) {
        if (j == s.size()) {
            res.push_back(trie[i].ter);
            return ;
        }
        int go = trie[i].go(s[j]);
        if (go != -1) dfs(go, j+1, dfs);
        if (s[j] != '_') {
            go = trie[i].go();
            if (go != -1) dfs(go, j+1, dfs);
        }
    };

    dfs(0, 0, dfs);

    return res;
}
#endif
