#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 3e5;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}

  ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;

	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}

	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}

	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}

	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}

	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}

	m operator -(){ return m(-v); }

  m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e%(p-1));
		return *this;
	}

	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}

	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}

	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

typedef mod_int<(int)MOD> mint;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  mint ans = 1;
  for(int i = 1; i < s.size(); i++)     // É mais fácil pensar no processo ao contrário: se s[i] == '?',
    ans = (s[i] == '?' ? ans*i : ans);  // então temos temos a quantidade de elementos até i menos 2 (máximo
																				// e mínimo) que podemos tirar. Sacada bem esperta.

  auto query = [&]() { return (s[0] == '?' ? 0 : ans); };

  cout << query() << "\n";

  while(m--){
    int i; cin >> i; i--;
    char c; cin >> c;

    if(i == 0)
      s[i] = c;
    else {
      if(s[i] != c){
        if(s[i] == '?') ans = ans/i;
        else if(c == '?') ans = ans*i;

        s[i] = c;
      }
    }

    cout << query() << "\n";
  }

  return 0;
}

