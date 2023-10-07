#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 3e5, MAX_CRIVO = 1e4;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

vector<int> prim;
int mark[MAX_CRIVO];	
void crivo(){
	for(int i = 2; i < MAX_CRIVO; i++){
		if(!mark[i]) prim.push_back(i);
		for(int p: prim){
			if(i*p >= MAX_CRIVO) break;
			mark[i*p] = 1;
			if(i%p == 0) break;
		}
	}
}

vector<int> fatoracao(int n) {
    vector<int> f;
    for (int p : prim) {
        if (p * p > n)
            break;
        while (n % p == 0) {
            f.push_back(p);
            n /= p;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

void solve(){
  int p; cin >> p;

  vector<int> f = fatoracao(p);

  int sum = 0;
  for(int i : f) sum += i;

  if(sum > 41) cout << "-1\n";
  else {
    cout << f.size() + (41-sum) << " ";
    for(int i : f) cout << i << " ";
    while(41-sum > 0){ cout << "1 "; sum++; }
    cout << "\n";
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  crivo();

  int t; cin >> t;
  for(int i = 1; i <= t; i++){
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}

