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


void solve(long long N, long long Q, std::vector<long long> a, std::vector<long long> b, std::vector<long long> p, std::vector<long long> x){
    
}
vector< vector<int> > tree;
vector<int>node;
vector<bool>visited;
void dfs(int p, int x){
    // debug(p);debug(x);
    visited[p]=true;
    REP(i, tree[p].size()){
        if(!visited[tree[p][i]]){
            dfs(tree[p][i], x+node[tree[p][i]]);
            node[tree[p][i]]+=x;
        }
    }
    return;
}

int main(){
    int N,Q;
    cin>>N>>Q;
    REP(_, N+1){
        vector<int> t;
        tree.PB(t);
        node.PB(0);
        visited.PB(false);
    }
    REP(_, N-1){
        int a, b;
        cin>>a>>b;
        tree[a].PB(b);
        tree[b].PB(a);
    }
    REP(_, Q){
        int p,x;
        cin>>p>>x;
        node[p]+=x;
    }
    dfs(1, node[1]);
    for(int i=1; i<=N; i++){
        cout<<node[i];
        if(i<N)cout<<" ";
    }cout<<endl;
    return 0;
}
