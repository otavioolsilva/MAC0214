#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 5e5+10;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

const int LOG = 20;

vector<array<int, 2>> trie;

void trie_add(int x){
  int u = 0;

  for(int i = LOG-1; i >= 0; i--){
    int j = (x >> i) & 1;
    
    if(trie[u][j] == -1){
      trie[u][j] = trie.size();
      trie.push_back(array<int, 2>({-1, -1}));
    }

    u = trie[u][j];
  }
}

int trie_query(int x){
  int u = 0;

  for(int i = LOG-1; i >= 0; i--){
    int j = (x >> i) & 1;

    if(trie[u][j ^ 1] != -1) j ^= 1; // pra maximizar o xor
    
    x ^= (j << i);
    u = trie[u][j];
  }

  return x;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  trie = {array<int, 2>({-1, -1})};

  int n; cin >> n;
  
  vector<int> arr(n, 0); trie_add(0); // c0
  for(int i = 1; i < n; i++){
    cin >> arr[i];
    arr[i] ^= arr[i-1];
    trie_add(arr[i]);
  }

  int ans;

  for(ans = 0; ans < n; ans++)
    if(trie_query(ans) == n-1) break;

  assert(ans < n);

  cout << ans << " ";
  for(int i = 1; i < n; i++)
    cout << (ans ^ arr[i]) << " ";
  cout << "\n";

  return 0;
}
 
