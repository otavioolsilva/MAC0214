#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 2e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int n, q;
vector<int> a(MAXN), st(4*MAXN);

void build(int pos, int l, int r){
  if(l == r){
    st[pos] = a[l];
    return;
  }

  int m = (l + r)/2;
  build(pos*2, l, m);
  build(pos*2+1, m+1, r);
  st[pos] = st[pos*2] & st[pos*2+1];
}

int query(int pos, int l, int r, int a, int b){
  if(a <= l && r <= b) return st[pos];
  if(b < l || r < a) return 1073741823;

  int m = (l+r)/2;
  return query(pos*2, l, m, a, b) & query(pos*2+1, m+1, r, a, b);
}

void solve(){
  cin >> n;

  for(int i = 1; i <= n; i++) cin >> a[i];

  build(1, 1, n);

  cin >> q;
  while(q--){
    int l, k; cin >> l >> k;

    int a = l, b = n, m, best = -1;
    while(a <= b){
      m = (a+b)/2;

      if(query(1, 1, n, l, m) >= k){
        best = m;
        a = m+1;
      } else
        b = m-1;
    }

    cout << best << " ";
  }
  cout << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

