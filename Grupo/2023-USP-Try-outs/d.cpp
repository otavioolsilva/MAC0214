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

queue<int> filas[MAXN];
int entrou[MAXN];
set<pair<int, int>> ainda;
set<int> res;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for(int i = 1; i <= 2*n; i++){
    int op; cin >> op;

    if(op == 1){
      int p, f; cin >> p >> f;

      entrou[p] = i;
      filas[f].push(p);
      ainda.insert({i, p});
    } else {
      int f; cin >> f;

      int p = filas[f].front(); filas[f].pop();
      int t = entrou[p];

      set<pair<int, int>> novos;

      for(pair<int, int> x : ainda){
        if(x.first < t){
          novos.insert(x);
        } else break;
      }

      for(pair<int, int> x : novos){
        res.insert(x.second);
        ainda.erase(x);
      }

      ainda.erase({t, p});
    }
  }

  cout << res.size() << "\n";
  for(int i : res)
    cout << i << " ";
  cout << "\n";

  return 0;
}

