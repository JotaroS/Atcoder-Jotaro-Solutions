#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// conversion
//------------------------------------------
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

// math
//-------------------------------------------
template <class T> inline T sqr(T x) { return x * x; }

// typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

// container util
//------------------------------------------
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i, c)                                                             \
  for (typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())

// repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

// constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI = acos(-1.0);

// clear memory
#define CLR(a) memset((a), 0, sizeof(a))

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                                               \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")"                       \
       << " " << __FILE__ << endl;

const long long MOD = 2;
/*

3
1 0 0 ...

1 1 1, 1;
0 1 0  0
0 0 1  0

0 0 0 0 0 
0

1 1 0


*/

int table[501010];

void make_table(int N){
  REP(i, N+10)table[i]=0;
  table[1]=1;
  for(int i=2; i <= N; i++){
    for(int j=1; j<=sqrt(i); j++){
      if(i % j ==0) table[i]++;
    }
    table[i]++;
  }
  return;
}

void solve(long long N, std::vector<long long> a) {
}

int a [202020];
int b [202020];
int main() {
  int N;
  cin>>N;
  REP(i, N)cin>>a[i+1];
  for(int i=N;i >=1; i--){
    int cnt=0;
    for(int j=2; i*j<=N; j++){
      cnt += b[i*j];
    }
    if(cnt%2!=a[i])b[i]=1;
  }
  VI ans;
  for(int i=1; i <=N; i++){
    if(b[i]==1)ans.PB(i);
  }
  cout<<ans.size()<<endl;
  for (auto i : ans)cout<<i<<" ";
  cout<<endl;
  return 0;
}
