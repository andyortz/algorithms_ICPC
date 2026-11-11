// Utilidades de las pruebas de estrés: aleatorios reproducibles y CHECK.
// Se incluye DESPUÉS del archivo del notebook que se prueba.
#pragma once
#include "../../_base/template-simple.hpp"
using ll = long long;

static mt19937_64 rngEstres(20261105);
static long long rnd(long long l, long long r) { return l + (long long)(rngEstres() % (unsigned long long)(r - l + 1)); }
static long long checksEstres = 0;

#define CHECK(c) do { ++checksEstres; if (!(c)) { cerr << "FALLO " << __FILE__ << ":" << __LINE__ << ": " #c << endl; exit(1); } } while (0)
#define FIN(nombre) (cerr << nombre << ": " << checksEstres << " comprobaciones OK" << endl)
