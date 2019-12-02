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

const long long MOD = 1000000007;

void solve(long long N, long long M, std::vector<long long> a) {
  vector<long long> dp(N+1);
  vector<int> broken(N+1);
  REP(i,N+1){
    dp[i]=0;
  }
  dp[0] = dp[1] = 1;
  for(int i=0; i<N+1; i++){
    broken[i]=0;
  }
  for(int i=0; i<M; i++){
    broken[a[i]]=1;
  }
  
  for(int i=2;i < N+1; i++){
    if(broken[i-1]==0)dp[i]=(dp[i]+dp[i-1])%1000000007;
    if(broken[i-2]==0)dp[i]=(dp[i]+dp[i-2])%1000000007;
  }
  // REP(i, N+1){
  //   cout<<dp[i]<<endl;
  // }
  cout<<dp[N]<<endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  std::vector<long long> a(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &a[i]);
  }
  solve(N, M, std::move(a));
  return 0;
}
