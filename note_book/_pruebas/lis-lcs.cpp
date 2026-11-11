// Compilar desde note_book: g++ -std=gnu++17 -O2 -Wall -Wextra _pruebas/lis-lcs.cpp -o <ruta_temporal.exe>
#include "../04_DP/LIS/longest-increasing-subsequence.cpp"
#include "../04_DP/LCS_y_distancia_edicion/lcs-lis.cpp"
#include "../04_DP/LCS_y_distancia_edicion/lcs-bitset.cpp"

template<class Secuencia>
int lcs_dp(const Secuencia& a, const Secuencia& b) {
    vector<vi> dp(a.size() + 1, vi(b.size() + 1));
    for (int i = 1; i <= (int)a.size(); ++i)
        for (int j = 1; j <= (int)b.size(); ++j)
            dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
    return dp.back().back();
}

int casos_lcs = 0, casos_lis = 0;
void comprobar_strings(const string& a, const string& b) {
    int esperado = lcs_dp(a, b);
    assert(lcs_lis(a, b) == esperado);
    assert(lcs_bitset(a, b) == esperado);
    assert(lcs_bitset(b, a) == esperado);
    ++casos_lcs;
}

signed main() {
    vector<string> binarios;
    for (int len = 0; len <= 5; ++len) {
        for (int mask = 0; mask < (1LL << len); ++mask) {
            string s(len, 'a');
            for (int j = 0; j < len; ++j) s[j] += (mask >> j) & 1;
            binarios.pb(s);
        }
    }
    for (const auto& a : binarios) for (const auto& b : binarios) comprobar_strings(a, b);

    mt19937_64 rng(20261022);
    for (int k = 0; k < 500; ++k) {
        string a(rng() % 180, ' '), b(rng() % 180, ' ');
        for (char& c : a) c = static_cast<char>(rng() % (k % 2 ? 256 : 4));
        for (char& c : b) c = static_cast<char>(rng() % (k % 2 ? 256 : 4));
        comprobar_strings(a, b);
    }
    for (int len : {0, 1, 63, 64, 65, 127, 128, 129, 255, 256, 257}) {
        string a(len, 'a');
        comprobar_strings(a, a);
        comprobar_strings(a, string(len + 70, 'a'));
        comprobar_strings(a, string(len + 1, 'b'));
        string b;
        for (int i = 0; i < len + 65; ++i) b.pb(i % 2 ? 'a' : 'b');
        comprobar_strings(a, b);
    }
    for (int k = 0; k < 500; ++k) {
        vi a(rng() % 40), b(rng() % 40);
        for (int& x : a) x = ((int)(rng() % 9) - 4) * (1LL << 40);
        for (int& x : b) x = ((int)(rng() % 9) - 4) * (1LL << 40);
        assert(lcs_lis(a, b) == lcs_dp(a, b));
        ++casos_lcs;
        vi dp(a.size(), 1);
        int esperado = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            for (int j = 0; j < i; ++j) if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
            esperado = max(esperado, dp[i]);
        }
        assert(lis(a) == esperado);
        ++casos_lis;
    }
    vi p(100000); iota(all(p), 0);
    assert(lis(p) == (int)p.size());
    assert(lcs_lis(p, p) == (int)p.size());
    vi q = p; reverse(all(q));
    assert(lis(q) == 1);
    assert(lcs_lis(p, q) == 1);
    assert(lcs_bitset(string(20000, 'a'), string(18000, 'a')) == 18000);
    cout << "OK: " << casos_lcs << " casos LCS contra DP; " << casos_lis
         << " casos LIS contra DP; permutaciones de 100000 y strings repetidos de 20000/18000.\n";
}
