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

//pair sort
bool compare_by_b(pair<LL, LL> a, pair<LL, LL> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}


void solve(long long N, std::vector<long long> a){
    if(N==1)cout<<1<<endl;
    else{
        REP(i, N){
            if(a[i]>=1&&a[i]<=399)a[i]=1;
            else if(a[i]>=400&&a[i]<=799)a[i]=2;
            else if(a[i]>=800&&a[i]<=1199)a[i]=3;
            else if(a[i]>=1200&&a[i]<=1599)a[i]=4;
            else if(a[i]>=1600&&a[i]<=1999)a[i]=5;
            else if(a[i]>=2000&&a[i]<=2399)a[i]=6;
            else if(a[i]>=2400&&a[i]<=2799)a[i]=7;
            else if(a[i]>=1800&&a[i]<=3199)a[i]=8;
            else if(a[i]>=3200)a[i]=9;
        }
        // REP(i, N)debug(a[i]);
        map<int, int> m;
        int ans=0;
        REP(i,10)m[i]=0;
        REP(i, N){
            m[a[i]]++;
        }

        wefoij
        // for(int i=1; i <10; i++)debug(m[i]);
        for(int i=1; i <=8; i++)if(m[i]>0)ans++;
        else cout<<ans<<" "<<ans+m[9]<<endl;
    }
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
