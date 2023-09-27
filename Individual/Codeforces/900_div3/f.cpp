#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e5+10, MAX_CRIVO = 1e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

vector<ll> prim;
ll mark[MAX_CRIVO];	

void crivo(){
	for(ll i = 2; i < MAX_CRIVO; i++){
		if(!mark[i]) prim.push_back(i);
		for(ll p: prim){
			if(i*p >= MAX_CRIVO) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

vector<int> cont, cont_orig;
ll divii, divii_orig;
vector<int> divi, divi_orig;

void fatorizacao(ll n, vector<int>& c, bool set_divii){
  for (ll d : prim) {
    if (d * d > n)
      break;
    while (n % d == 0) {
      if(set_divii){
        divii /= c[d] + 1;
        divii *= c[d] + 2;
      }

      c[d]++;
      
      n /= d;
    }
  }

  if (n > 1){
    if(set_divii){
      divii /= c[n] + 1;
      divii *= c[n] + 2;
    }

    c[n]++;
  }
}

void solve(){
  cont.assign(1e6+10, 0);
  divi.assign(1e6+10, 0);
  divii = 1; // que gambiarra

  ll n, q; cin >> n >> q;

  fatorizacao(n, cont, true);
  cont_orig = cont;
  divi_orig = divi;
  divii_orig = divii;

  while(q--){
    int op; cin >> op;

    if(op == 2){
      cont = cont_orig; // TLE?
      divii = divii_orig;
      divi = divi_orig;
      continue;
    }

    ll x; cin >> x;
    fatorizacao(x, cont, true);

    divi.assign(1e6+10, 0); // nuss, mas vai dar tle fácil
    fatorizacao(divii, divi, false);

    bool flag = true;

    for(int i = 1; i < 1e6+10 && flag; i++)
      if(cont[i] < divi[i]) flag = false;

    if(flag) cout << "YES\n";
    else cout << "NO\n";
  }

  cout << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  crivo();

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

