#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e5+1;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int n;
vector<int> divisors[MAXN];
vector<int> arr;
vector<bool> valid;

void unmark(int x, int base = 0){
  for(int d : divisors[x]){
    if(d <= n){
      if(d >= base) valid[d] = false;
    } else return;
  }
}

bool dfa(int k){
  int d; // índice do último cara diferente de -1 visto
  int s; // estado:
         //   0 = antes de processar algum número
         //   1 = subindo
         //   2 = subindo ou descendo
         //   3 = descendo
         //   4 = deu ruim

  for(int j = 1; j <= n/k; j++){
    s = 0; d = -1;

    for(int i = (j-1)*k + 1; i <= min(n, j*k) && s != 4; i++){
      if(arr[i] == -1 || (arr[i] != -1 && d == -1) || (d != -1 && arr[d] == arr[i])){ // mesmo nível ou no começo
        if(s == 0) s = 1;
        else if(s == 1) s = 2;
        //else if(s == 2) s = 2;
        //else if(s == 3) s = 3;
        //else if(s == 4) s = 4;
      } else if(arr[d] < arr[i]){ // subindo
        if(s == 0) s = 1;
        //else if(s == 1) s = 1;
        else if(s == 2) s = 1;
        else if(s == 3) s = 4;
        //else if(s == 4) s = 4;
      } else if(arr[d] > arr[i]){ // descendo
        if(s == 0) s = 4;
        else if(s == 1) s = 3;
        else if(s == 2) s = 3;
        //else if(s == 3) s = 3;
        //else if(s == 4) s = 4;
      }

      if(arr[i] != -1) d = i;
    }

    if(s == 2 || s == 3) return true;
  }

  return false;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // crivo pra determinar divisores de cada número de 1 à MAXN
  for(int i = 1; i < MAXN; i++)
    for(int j = 0; j < MAXN; j += i)
      divisors[j].push_back(i);

  cin >> n;

  arr.resize(n+1); valid.assign(n+1, true);
  for(int i = 1; i <= n; i++) cin >> arr[i];

  // primeiro caso pra eliminar divisores (arr[i] < arr[i+1])
  for(int i = 1; i < n; i++)
    if(arr[i] != -1 && arr[i+1] != -1 && arr[i] < arr[i+1])
      unmark(i+1);

  // segundo caso pra eliminar divisores (arr[i] > arr[i+1])
  for(int i = 1; i < n; i++)
    if(arr[i] != -1 && arr[i+1] != -1 && arr[i] > arr[i+1])
      unmark(i-1);

  // terceiro caso
  for(int i = 1, d = -1, p = -1, aux = -1; i < n; i++){
    if(arr[i] != -1){
      if(d != -1 && arr[d] > arr[i]) p = d;
      else if(d != -1 && p != -1 && arr[i] > arr[d]) aux = p;

      d = i;
    }

    if(aux != -1)
      unmark(i, i - aux + 1);
  }

  // iterar pelos caras válidos e ver se alguém satisfaz
  for(int i = 3; i <= n; i++){
    if(valid[i] && dfa(i)){
      cout << "Y\n";
      return 0;
    }
  }

  cout << "N\n";

  return 0;
}

