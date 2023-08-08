#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << ", ate aqui bao" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 2e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int arr[MAXN];

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = 0;
  bool block = false, used = false;

  for(int i = 0; i < n; i++){
    if(!block){
      ans++;
      block = true;

      if(arr[i] == 0) used = true;
      else used = false;
    } else {
      if(arr[i] == 0) {
        if(!used) used = true;
        else i--;

        block = false;
      } else if(arr[i] == 2)
        used = false;
    }
  }

  cout << ans << "\n";

  return 0;
}

