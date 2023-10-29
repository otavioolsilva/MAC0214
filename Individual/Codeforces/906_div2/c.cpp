#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 8010;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

void solve(){
  int n; cin >> n;
  
  deque<int> dq;
  int cont[2] = {0, 0};
  for(int i = 0; i < n; i++){
    char c; cin >> c;
    dq.push_back(c-'0');

    cont[c-'0']++;
  }

  if(cont[0] != cont[1]){ // se a string tem qtd de 0's != da qtd de 1's, já rodou
    cout << "-1\n";
    return;
  }

  // c.c., dá pra fazer
  vector<int> ans; int i = 0, j = n;
  while(!dq.empty()){
    if(dq.front() != dq.back()){
      dq.pop_front(); i++;
      dq.pop_back(); j--;
    } else {
      if(dq.front() == 0){
        ans.push_back(j);
        dq.pop_front(); i++;
        dq.push_back(0); j++;
      } else {
        ans.push_back(i);
        dq.push_front(1); i++;
        dq.pop_back(); j++;
      }
    }
  }

  cout << ans.size() << "\n";
  for(int a : ans) cout << a << " ";
  cout << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  for(int i = 1; i <= t; i++)
    solve();

  return 0;
}

