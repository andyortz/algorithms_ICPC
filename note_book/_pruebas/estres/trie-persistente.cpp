// prueba: 01_Estructuras/Trie_persistente/persistent-trie.cpp
// Máximo x XOR y entre los valores insertados en las versiones (vl, vr] usando frec.
#include "../../01_Estructuras/Trie_persistente/persistent-trie.cpp"
#include "comun.hpp"
ll maxXor(PersistentTrie& T, int vl, int vr, ll y) {
    ll a = T.root[vl], b = T.root[vr], res = 0;
    for (int i = T.tao - 1; i >= 0; i--) {
        ll want = ((y >> i) & 1) ^ 1;
        ll nb = T.trie[want][b], na = T.trie[want][a];
        ll cb = nb ? T.frec[nb] : 0, ca = na ? T.frec[na] : 0;
        if (cb - ca > 0) res |= 1LL << i, a = na, b = nb;
        else a = T.trie[want ^ 1][a], b = T.trie[want ^ 1][b];
    }
    return res;
}
signed main() {
    for (int it = 0; it < 300; it++) {
        int bits = rnd(1, 12);
        PersistentTrie T(bits); vector<ll> v;
        for (int k = 0; k < 100; k++) {
            if (v.empty() || rnd(0, 1)) { ll x = rnd(0, (1LL << bits) - 1); T.insert(x); v.pb(x); }
            else {
                int vl = rnd(0, v.size() - 1), vr = rnd(vl + 1, v.size()); ll y = rnd(0, (1LL << bits) - 1), best = 0;
                for (int i = vl; i < vr; i++) best = max(best, v[i] ^ y);
                CHECK(maxXor(T, vl, vr, y) == best);
            }
        }
    }
    FIN("persistent-trie");
}
