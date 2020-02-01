#include<stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
 
 
using namespace std;
 
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
 
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const string YES = "POSSIBLE";
const string NO = "IMPOSSIBLE";

vector <vector <LL> > adj;
vector <bool> visited;
LL N_;
bool dfs(LL p, LL d){
    visited[p]=true;
    if(p==N_ && d==2)return true;
    else if(d<2){
        for(LL i=0; i < adj[p].size(); i++){
            if(!visited[adj[p][i]] && dfs(adj[p][i], d+1)){
                return true;
            }
        }
    }
    return false;
}

void solve(long long N, long long M, std::vector<long long> a, std::vector<long long> b){
    N_=N;
    REP(i,N+1){
        vector<LL> l;
        visited.PB(false);
        adj.PB(l);
    }
    REP(i, M){
        adj[a[i]].PB(b[i]);
        adj[b[i]].PB(a[i]);
    }
    if(dfs(1, 0))cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> a(M);
    std::vector<long long> b(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&a[i]);
        scanf("%lld",&b[i]);
    }
    solve(N, M, std::move(a), std::move(b));
    return 0;
}
