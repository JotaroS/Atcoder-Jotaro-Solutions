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

const long long MOD = 1000000007;


void solve(int N, std::vector<int> A){
    map<int,int> list;
    
    bool error = false;
    REP(i, N){
            list[A[i]]++;
    }
    if(N%2==0){ //even
        for(int i=1; i<N; i+=2) if(list[i]!=2){error=true;break;}
    }
    else{ //odd
        for(int i=2; i<N; i+=2)if(list[i]!=2){error=true;break;}
        if(list[0]!=1)error=true;
        
    }    
    if(error){
        cout<<0<<endl;
        return;
    }
    LL ans=1;
    REP(i,N/2){
      ans*=2;
      ans%=MOD;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    int N;
    cin>>N;
    std::vector<int> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
