#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 2010, MAXN2 = 1e6 + 10;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int n, k;
int memo[43046721]; // 8 * (\sum_{i=0}^{7} 9^i) + 1
int pot[9];
vector<vector<int>> machines;

int pos(vector<int>& arr){
  int ret = 0;
  for(int i = 0; i < 8; i++)
    ret += arr[i] * pot[i];
  return ret;
}

void upd(vector<int>& arr, int v){
  vector<int> it(9, 0);

  while(it[8] == 0){
    memo[pos(it)] += v;

    it[0]++;

    int j = 0;
    while(j < 8 && it[j] > arr[j]){
      it[j] = 0;
      it[j+1]++;
      j++;
    }
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  pot[0] = 1;
  for(int i = 1; i <= 8; i++)
    pot[i] = pot[i-1]*9;

  cin >> n >> k;

  while(n--){
    char op; cin >> op;

    if(op == 'C'){ // add machine
      int r; cin >> r;

      machines.push_back(vector<int>(8, 0));

      while(r--){
        int t; cin >> t; t--;
        machines.back()[t]++;
      }

      upd(machines.back(), 1);
    } else if(op == 'D'){ // remove machine
      int r; cin >> r; r--;

      upd(machines[r], -1);
    } else { // job query
      int r; cin >> r;
      vector<int> req(8, 0);

      while(r--){
        int t; cin >> t; t--;
        req[t]++;
      }

      cout << memo[pos(req)] << "\n";
    }
  }

  return 0;
}

