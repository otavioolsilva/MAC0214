#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << ", ate aqui bao" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

vector<pair<int, int>> acc, queries;

void solve(){
  int n, m;
  cin >> n >> m;

  acc.assign(n+1, make_pair(0, 0)); // {qtd 0's, qtd 1's}

  for(int i = 1; i <= n; i++){
    acc[i] = acc[i-1];

    char c; cin >> c;
    if(c == '0') acc[i].first++;
    else acc[i].second++;
  }

  queries.resize(m);

  for(int i = 0; i < m; i++)
    cin >> queries[i].first >> queries[i].second;

  sort(queries.begin(), queries.end());

  int ans = 1;
  int bf_0 = acc[queries[0].second].first - acc[queries[0].first-1].first;
  int bf_1 = acc[queries[0].second].second - acc[queries[0].first-1].second;

  bool flag = (bf_0 == 0 || bf_1 == 0);

  for(int i = 1; i < m; i++){
    int now_0 = acc[queries[i].second].first - acc[queries[i].first-1].first;
    int now_1 = acc[queries[i].second].second - acc[queries[i].first-1].second;

    if(now_0 == 0 || now_1 == 0){ // ordenar não afeta a string original
      if(!flag) flag = true, ans++;
      
      bf_0 = now_0, bf_1 = now_1;

      continue;
    }

    if(queries[i].first > queries[i-1].second) ans++, continue;

    if(now_0 && acc[queries[i].second] - acc[queries[i-1].second-1].second) ans++;
    else if()
  }

  cout << ans << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--)
    solve();

  return 0;
}

