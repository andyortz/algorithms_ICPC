// prueba: 01_Estructuras/Colas_monotonas/min-queue.cpp
#include "../../01_Estructuras/Colas_monotonas/min-queue.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        mnque<ll> mq; deque<ll> d;
        for (int k = 0; k < 400; k++) {
            if (d.empty() || rnd(0, 2)) { ll x = rnd(-5, 5); mq.push(x); d.pb(x); }
            else { mq.pop(); d.pop_front(); }
            if (!d.empty()) CHECK(mq.min() == *min_element(d.begin(), d.end()));
        }
    }
    FIN("min-queue");
}
