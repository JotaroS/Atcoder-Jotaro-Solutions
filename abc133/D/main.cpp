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

void solve(long long N, std::vector<long long> A) {
  bool flag = true;
  bool right = true;
  vector <long long> Y;
  REP(i, N){
    Y.PB(0);
  }
  while(flag){
    flag = false;
    REP(i,N){
      if(A[i]>0)flag = true;
      if(right){//migi
        if(i==N-1){
          Y[0]+=ceil(A[i]/2.0f);
          A[i]-=ceil(A[i]/2.0f);
        }
        else{
        Y[i+1]+=ceil(A[i]/2.0f);
        A[i]-=ceil(A[i]/2.0f);
        }
      }
      else{ //hidari
        if(i==0){
          Y[0]+=ceil(A[N-1]/2.0f);
          A[N-1]-=ceil(A[N-1]/2.0f);
        }
        else{
        Y[i]+=ceil(A[i-1]/2.0f);;
        A[i-1]-=ceil(A[i-1]/2.0f);
        }
      }
      REP(i,N){
    // cout<<A[i]<<" ";
  }
    }
    right = !right;
  }
  REP(i,N){
    cout<<Y[i]<<" ";
  }
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}