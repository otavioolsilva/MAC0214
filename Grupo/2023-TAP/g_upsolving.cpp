#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl

typedef long long ll;
const int INF = 0x3f3f3f3f, MAXN = 1e5+10;
const ll MOD = 998244353, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

int n;
vector<array<ll, 3>> sca; // {h, l, r}
vector<array<ll, 3>> edges; // {custo, a, b}, 0 é o chão

void add_edge(int a, int b, ll c){
  edges.push_back({c, a, b});
}

vector<int> parent;
vector<int> sz;

void init(){
  parent.resize(n+1);
  for(int i = 0; i <= n; i++)
    parent[i] = i;

  sz.assign(n+1, 1);
}

int find(int x){
  if(x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);

  if(a == b) return;

  if(sz[a] < sz[b]) swap(a, b);

  parent[b] = a;
  sz[a] += sz[b];
}

ll kruskal(){
  init();

  ll ans = 0;

  sort(edges.begin(), edges.end());

  for(auto [c, a, b] : edges) if(find(a) != find(b)){
    ans += c;
    merge(a, b);
  }

  return ans;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  sca.resize(n+1);
  for(int i = 1; i <= n; i++)
    cin >> sca[i][0] >> sca[i][1] >> sca[i][2]; 

  set<array<ll, 3>> borders; // {x, começando (0) ou acabando (1), índice}
  set<array<ll, 2>> in; // {altura, índice}

  // escadas sentido direita ---->
  for(int i = 1; i <= n; i++){
    borders.insert({sca[i][1] - sca[i][0], 0, i});
    borders.insert({sca[i][2] - sca[i][0], 1, i});
  }

  for(auto [x, flag, i] : borders){
    if(!flag){
      if(!in.empty()){
        auto up = in.lower_bound({sca[i][0], 0});
        
        if(up != in.end())
          add_edge(i, up->at(1), abs(sca[i][0] - up->at(0)));

        if(up != in.begin()){
          up--; // pega o cara abaixo
          add_edge(i, up->at(1), abs(sca[i][0] - up->at(0)));
        }
      }

      add_edge(i, 0, sca[i][0]);

      in.insert({sca[i][0], i});
    } else
      in.erase({sca[i][0], i});
  }

  borders.clear();
  in.clear();

  // escadas sentido esquerda <----
  for(int i = 1; i <= n; i++){
    borders.insert({sca[i][1] + sca[i][0], 0, i});
    borders.insert({sca[i][2] + sca[i][0], 1, i});
  }

  for(auto [x, flag, i] : borders){
    if(!flag){
      if(!in.empty()){
        auto up = in.lower_bound({sca[i][0], 0});
        
        if(up != in.end())
          add_edge(i, up->at(1), abs(sca[i][0] - up->at(0)));

        if(up != in.begin()){
          up--; // pega o cara abaixo
          add_edge(i, up->at(1), abs(sca[i][0] - up->at(0)));
        }
      } 

      in.insert({sca[i][0], i});
    } else
      in.erase({sca[i][0], i});
  }

  cout << kruskal() << "\n";

  return 0;
}

