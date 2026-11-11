// Tema: 08_Strings/Palindromic_Tree
// Base: Template/simple.cpp (int = long long).
// Adaptación: min/max con argumentos enteros mixtos tipados explícitamente como long long para la plantilla.
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_F0DEC90D9A74BB54
#define NOTEBOOK_GENERADO_F0DEC90D9A74BB54
#include "../../_base/template-simple.hpp"

const int alfa = 26;
const char L = 'a';

struct node {
  int next[alfa], link, len;
  int cnt;
  node(int x, int l = 0, int c = 1) {
    len = x, link = l, cnt = c;
    memset(next, 0, sizeof next);
  }
  int& operator [] (int i) { return next[i]; }
};

struct palindromic_tree {
  vector<node> tree;
  string s;
  int n;
  int last;
  palindromic_tree(string t = "") {
    n = last = 0;
    tree.pb(node(-1));
    tree.pb(node(0));
    for (auto &c: t)add_char(c);
  }

  int getlink(int p) {
    while (s[n - tree[p].len - 1] != s[n])
      p = tree[p].link;
    return p;
  }

  void add_char(char ch) {
    s.pb(ch);
    int p = getlink(last), c = ch - L;
    if (!tree[p][c]) {
      int link = getlink(tree[p].link);
      link = max<long long>(1, tree[link][c]);
      tree[p][c] = static_cast<long long>((tree).size());
      tree.pb(node(tree[p].len + 2, link, 0));
    }
    last = tree[p][c];
    tree[last].cnt++;
    n++;
  }
};
#endif
