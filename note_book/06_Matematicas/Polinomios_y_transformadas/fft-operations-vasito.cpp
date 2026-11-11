// Requisito de selección: Necesita proveedor con API poly/multiply/fft del mismo diseño; no basta pegar la FFT de Alex por nombre.
// Tema: 06_Matematicas/Polinomios_y_transformadas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_378F6B30BDEC9889
#define NOTEBOOK_GENERADO_378F6B30BDEC9889
#include "../../_base/template-simple.hpp"

// Polynomial division: O(n*log(n))
// Multi-point polynomial evaluation for arbitrarily large points: O(n+k*log^2(k))
// Multi-point polynomial evaluation for all points in [0, MOD): O((n+MOD)*log(n+MOD))
// Polynomial interpolation: O(n*log^2(n))
// Inverse: O(n*log(n))
// Log: O(n*log(n))
// Exp: O(n*log(n))

//Works with NTT. For FFT, just replace addmod,submod,mulmod,inv
poly add(const poly &a, const poly &b){
	int n=static_cast<long long>((a).size()),m=static_cast<long long>((b).size());
	poly ans(max(n,m));
	for (int i=(0), nb_fin_3=(max(n,m)); i<nb_fin_3; ++i) ans[i]=addmod(i<static_cast<long long>((a).size())?a[i]:0, i<static_cast<long long>((b).size())?b[i]:0);
	while(static_cast<long long>((ans).size())>1&&!ans.back())ans.pop_back();
	return ans;
}

// derivative of p
poly derivative(const poly &p){
	poly ans(max(1, static_cast<long long>((p).size())-1));
	for (int i=(1), nb_fin_9=(static_cast<long long>((p).size())); i<nb_fin_9; ++i) ans[i-1]=mulmod(p[i],i);
	return ans;
}

// integral of p
poly integrate(const poly &p){
	int n=static_cast<long long>((p).size());
	poly ans(n+1);
	if(!n) return ans;
	poly pre(n+1); pre[0]=1;
	for (int i=(1), nb_fin_12=(n+1); i<nb_fin_12; ++i) pre[i]=mulmod(pre[i-1],i);
	tf iv=inv(pre[n]);
	for(int i=n;i>=1;i--){
		ans[i]=mulmod(p[i-1], mulmod(iv,pre[i-1]));
		iv=mulmod(iv,i);
	}
	return ans;
}

// p % (x^n)
poly takemod(const poly &p, int n){
	poly res=p;
	res.resize(min(static_cast<long long>((res).size()),n));
	while(static_cast<long long>((res).size())>1&&res.back()==0) res.pop_back();
	return res;
}

// first d terms of 1/p
poly invert(const poly &p, int d){
	assert(p[0]);
	poly res={inv(p[0])};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly pre(p.begin(), p.begin()+min(static_cast<long long>((p).size()),sz));
		poly cur=multiply(res,pre);
		for (int i=(0), nb_fin_17=(static_cast<long long>((cur).size())); i<nb_fin_17; ++i) cur[i]=submod(0,cur[i]);
		cur[0]=addmod(cur[0],2);
		cur=takemod(cur,sz);
		res=multiply(res,cur);
		res=takemod(res,sz);
	}
	res.resize(d);
	return res;
}

// first d terms of log(p)
poly log(const poly &p, int d){
	assert(p[0]==1);
	poly cur=takemod(p,d);
	poly a=invert(cur,d), b=derivative(cur);
	auto res=multiply(a,b);
	res=takemod(res,d-1);
	res=integrate(res);
	return res;
}

// first d terms of exp(p)
poly exp(const poly &p, int d){
	assert(!p[0]);
	poly res={1};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly lg=log(res, sz), cur(sz);
		for (int i=(0), nb_fin_19=(sz); i<nb_fin_19; ++i) cur[i]=submod(i<static_cast<long long>((p).size())?p[i]:0, i<static_cast<long long>((lg).size())?lg[i]:0);
		cur[0]=addmod(cur[0],1);
		res=multiply(res,cur);
		res=takemod(res, sz);
	}

	res.resize(d);
	return res;
}

pair<poly,poly> divslow(const poly &a, const poly &b){
	poly q,r=a;
	tf ib=inv(b.back());
	while(static_cast<long long>((r).size())>=static_cast<long long>((b).size())){
		q.pb(mulmod(r.back(),ib));
		if(q.back()) for (int i=(0), nb_fin_25=(static_cast<long long>((b).size())); i<nb_fin_25; ++i){
			r[static_cast<long long>((r).size())-i-1]=submod(r[static_cast<long long>((r).size())-i-1],mulmod(q.back(),b[static_cast<long long>((b).size())-i-1]));
		}
		r.pop_back();
	}
	reverse(all(q));
	return {q,r};
}

pair<poly,poly> divide(const poly &a, const poly &b){	//returns {quotient,remainder}
	int m=static_cast<long long>((a).size()),n=static_cast<long long>((b).size()),MAGIC=128;
	if(m<n) return {{0},a};
	if(min(m-n,n)<MAGIC)return divslow(a,b);
	poly ap=a; reverse(all(ap));
	poly bp=b; reverse(all(bp));
	bp=invert(bp,m-n+1);
	poly q=multiply(ap,bp);
	q.resize(m-n+1,0);
	reverse(all(q));
	poly bq=multiply(b,q);
	for (int i=(0), nb_fin_36=(static_cast<long long>((bq).size())); i<nb_fin_36; ++i) bq[i]=submod(0,bq[i]);
	poly r=add(a,bq);
	return {q,r};
}

struct EvalTree {
	int k;
	vector<poly> tree;
	EvalTree(const vector<tf> &x): k(static_cast<long long>((x).size())), tree(2*max(static_cast<long long>((x).size()),1)) {
		for (int i=(k), nb_fin_40=(2*k); i<nb_fin_40; ++i) tree[i]={submod(0,x[i-k]),1};
		for(int i=k-1;i;i--) tree[i]=multiply(tree[2*i],tree[2*i+1]);
	}
};

poly mulT(const poly &M, const poly &a, int n){
	poly c=multiply(M,a);
	int m=static_cast<long long>((M).size());
	poly res(n);
	for (int j=(0), nb_fin_43=(n); j<nb_fin_43; ++j) res[j]=(j+m-1<static_cast<long long>((c).size()))?c[j+m-1]:0;
	return res;
}

void downsweep(const EvalTree &et, int v, poly q, vector<tf> &out){
	if(v>=et.k){ out[v-et.k]=q[0]; return; }
	poly ql=mulT(et.tree[2*v+1],q,static_cast<long long>((et.tree[2*v]).size())-1);
	poly qr=mulT(et.tree[2*v],  q,static_cast<long long>((et.tree[2*v+1]).size())-1);
	poly().swap(q);
	downsweep(et,2*v,move(ql),out);
	downsweep(et,2*v+1,move(qr),out);
}

vector<tf> evaluate(const poly &a, const EvalTree &et){
	int k=et.k;
	if(!k) return {};
	poly f=static_cast<long long>((a).size())>=static_cast<long long>((et.tree[1]).size())?divide(a,et.tree[1]).second:a;
	poly rm=et.tree[1]; reverse(all(rm));
	poly h=invert(rm,static_cast<long long>((f).size()));
	poly().swap(rm);
	reverse(all(h));
	poly q1=mulT(h,f,static_cast<long long>((et.tree[1]).size())-1);
	poly().swap(h); poly().swap(f);
	vector<tf> out(k);
	downsweep(et,1,move(q1),out);
	return out;
}

// Multi-point polynomial evaluation for arbitrarily large points
vector<tf> evaluate(const poly &a, const vector<tf> &x){
	if(x.empty()) return {};
	EvalTree et(x);
	return evaluate(a,et);
}

poly upsweep(EvalTree &et, int v, const vector<tf> &c){
	if(v>=et.k) return {c[v-et.k]};
	poly L=upsweep(et,2*v,c), R=upsweep(et,2*v+1,c);
	poly p1=multiply(et.tree[2*v],R); poly().swap(R);
	poly p2=multiply(et.tree[2*v+1],L); poly().swap(L);
	poly().swap(et.tree[2*v]); poly().swap(et.tree[2*v+1]);
	poly res=add(p1,p2);
	return res;
}

poly interpolate(const vector<tf> &x, const vector<tf> &y){
	int k=static_cast<long long>((x).size());
	if(!k) return {0};
	EvalTree et(x);
	vector<tf> d=evaluate(derivative(et.tree[1]),et);
	vector<tf> pre(k+1); pre[0]=1;
	for (int i=(0), nb_fin_55=(k); i<nb_fin_55; ++i) pre[i+1]=mulmod(pre[i],d[i]);
	tf iv=inv(pre[k]);
	vector<tf> c(k);
	for(int i=k-1;i>=0;i--){
		c[i]=mulmod(y[i],mulmod(iv,pre[i]));
		iv=mulmod(iv,d[i]);
	}
	return upsweep(et,1,c);
}

// Given any number g, perform multi-point polynomial evaluation
// for all points of the form g^i, for each i in [0, k)
// in O((n+k) * log(n+k))
vector<int> chirpTransform(const poly &p, int g, int k){
	int inv_g=inv(g), n=static_cast<long long>((p).size())-1, sz=min(k,MOD-1);
	poly ap(n+1), bp(n+sz);

	for (int i=(0), nb_fin_58=(n+sz); i<nb_fin_58; ++i){
		int exp=1ll*i*(i-1)/2%(MOD-1);
		if(i<=n) ap[n-i]=mulmod(p[i],fpow(inv_g, exp));
		bp[i]=fpow(g, exp);
	}

	poly cp=multiply(ap, bp);
	vector<int> ans(k);

	for (int i=(0), nb_fin_60=(sz); i<nb_fin_60; ++i){
		int exp=1ll*i*(i-1)/2%(MOD-1), val=0;
		if(n+i<static_cast<long long>((cp).size())) val=cp[n+i];
		val=mulmod(val, fpow(inv_g,exp));
		ans[i]=val;
	}
	for (int i=(sz), nb_fin_63=(k); i<nb_fin_63; ++i) ans[i]=ans[i-MOD+1];
	return ans;
}

// Multi-point polynomial evaluation for all points in [0, MOD)
// MOD needs to be a prime number
vector<int> evaluate_all_points(const poly &p){
	int g=MOD_PRIMITIVE_ROOT, gk=1;
	assert(g!=-1);

	vector<int> ch=chirpTransform(p,g,MOD-1), ans(MOD, p[0]);

	for (int i=(0), nb_fin_65=(MOD-1); i<nb_fin_65; ++i){
		ans[gk]=ch[i];
		gk=mulmod(gk,g);
	}
	return ans;
}
#endif
