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
bool compare_by_b(pair<LL, LL> a, pair<LL, LL> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
void solve(long long N, long long L) {
  int m=10000000;
  int dec=0;
  bool flag=false;
  int sum=0;
  for(int i=1; i<N+1; i++){
    int cur = L+i-1;
    // cout<<cur<<endl;
    if(m>abs(cur)){
      dec=cur;
      m=abs(cur);
    }
    sum+=cur;
  }
  cout<<sum-dec<<endl;
}

int main() {
  int t;
  cin>>t;
  REP(_, t){
    int n;
    cin>>n;
    vector <vector <int> > coords(1002);
    int prev_y=0;
    int prev_x=0;
    REP(i, n){
      int x,y;
      cin>>x>>y;
      coords[x].PB(y);
    }
    string str="";
    int min_y = 0;
    bool err=false;
    REP(i, 1002){
      if(coords[i].size()==0)continue;
      int max_y=0;
      int m = 1000000;
      REP(j, coords[i].size()){
        if(max_y<coords[i][j])max_y=coords[i][j];
        if(m>coords[i][j])m=coords[i][j];
      }
      if(m<min_y){
        err = true;
        break;
      }
      else{
        REP(j, i-prev_x){
          str+="R";
        }
        REP(j, max_y-prev_y){
          str+="U";
        }
        prev_y=max_y;
        prev_x=i;
        min_y = max_y;
      }
    }
    if(err){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
      cout<<str<<endl;
    }
  }
  return 0;
}
