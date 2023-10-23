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

vector<vector<ll>> partitions;
vector<array<ll, 3>> partitions_info; // {tamanho, produto da partição, índice}

void gen_partitions(int n){
  vector<ll> p(n, 0);
  int k = 0;
  p[0] = n;

  while(true){
    partitions.emplace_back(p.begin(), p.begin()+k+1);
    partitions_info.push_back({k+1, 1, (ll)partitions.size()-1});
    for(int i = 0; i <= k; i++) partitions_info.back()[1] *= p[i];

    ll rem = 0;
    while(k >= 0 && p[k] == 1){
      rem += p[k];
      k--;
    }

    if(k < 0) return;

    p[k]--;
    rem++;

    while(rem > p[k]){
      p[k+1] = p[k];
      rem = rem - p[k];
      k++;
    }

    p[k+1] = rem;
    k++;
  }
}

void solve(){
  ll p; cin >> p;

  for(int i = 0; i < partitions_info.size(); i++){
    if(partitions_info[i][1] == p){
      cout << partitions_info[i][0] << " ";
      
      for(int j : partitions[partitions_info[i][2]])
        cout << j << " ";
      cout << "\n";

      return;
    }
  }

  cout << "-1\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  gen_partitions(41);

  sort(partitions_info.begin(), partitions_info.end());

  int t; cin >> t;
  for(int j = 1; j <= t; j++){
    cout << "Case #" << j << ": ";
    solve();
  }

  return 0;
}

