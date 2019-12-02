
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

void solve(std::string S) {
  int N = S.length();
  int ans[N];
  int distR[N];
  int distL[N];
  REP(i, N){
    ans[i]=0;
    distR[i]=distL[i]=0;
  }
  int cnt=0;
  int cnt_=0;
  REP(i, N){
    if(S[i]=='R')cnt=0;
    distR[i]=cnt;
    cnt++;

    if(S[N-i-1]=='L')cnt_=0;
    distL[N-i-1]=cnt_;
    cnt_++;
  }

  REP(i, N){
    if(S[i]=='R'){ 
      int x = distL[i];//idx - i - 1;
      int idx = i + x;
      if(x%2 == 1){ans[idx-1]++;}
      else{ans[idx]++;}
    }
    else{
      int x = distR[i];//idx - i + 1;
      int idx = i - x;
      if(x%2 == 1){ans[idx+1]++;}
      else{ans[idx]++;}
    }
  }
  REP(i, N){
    if(i!=N-1)cout<<ans[i]<<" ";
    else cout<<ans[i];
  }cout<<endl;
}

int main() {
  std::string S;
  std::cin >> S;
  solve(S);
  return 0;
}
