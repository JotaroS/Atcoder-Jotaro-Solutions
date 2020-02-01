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
typedef int LL;
 
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


void solve(long long N, long long M, std::vector<long long> p, std::vector<std::string> S){
    long long watable[N+10];
    bool actable[N+10];
    // vector <LL> acs;
    REP(i, N+10){
        watable[i]=0;
        actable[i]=false;
    }
    REP(i, M){ 
        if(actable[p[i]]==false&&S[i]=="WA"){
            watable[p[i]]++;
        }
        else if(actable[p[i]]==true&&S[i]=="WA"){
        }
        else if(S[i]=="AC"){
            actable[p[i]]=true;
        }
    }
    long long acs = 0;
    long long was = 0;
    REP(i, N+10){
        if(actable[i]==true)was += watable[i];
        if(actable[i]==true)acs++;
    }
    cout<<acs<<" "<<was<<endl;

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> p(M);
    std::vector<std::string> S(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&p[i]);
        std::cin >> S[i];
    }
    solve(N, M, std::move(p), std::move(S));
    return 0;
}
