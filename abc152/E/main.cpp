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

void solve(long long N, std::vector<long long> A){

}

int main(){
    LL t;
    vector<LL> ans;
    cin>>t;
    REP(i, t){
        LL n,s,k;
        cin>>n>>s>>k;
        // vector<bool>closed(n+1);
        // REP(j, n+1){
        //     closed[j]=false;
        // }
        // closed[0]=true;
        LL closest = 100000000;
        bool flag = false;
        vector<LL> closed;
        REP(j, k){
            LL v; cin>>v;
            // closed[v]=true ;
            closed.PB(v);
            if(v==s)flag=true; //if closed == start then closest stays
            // LL dist = v-s;
            // closest = min((LL)closest, abs(v-s));
            // debug(closest);
        }
        if(!flag){
            cout<<0<<endl;
            continue;
        }
        // closed.PB(s);
        LL left=-10000000, right=10000000;
        SORT(closed);
        REP(j, closed.size()){
            int c = closed[j];
            if(c<s){
                if(j>=1){
                    if(closed[j-1]!=closed[j]-1){
                        left=max(left, closed[j]-1);
                    }
                }
                else{ //j==0
                    if(closed[0]>1){
                        left = max(left,closed[0]-1);
                    }
                }
            }
            else if(s<c){
                if(j<n-1){
                    if(closed[j+1]!=closed[j]+1){
                        right=min(right,closed[j]+1);
                    }
                }
                else{ //j==n-1
                    if(closed[n-1]<n){
                        right=min(right,closed[n-1]+1);
                    }
                }
                
            }
        }
        cout<<min(right-s,s-left)<<endl;

    }
    return 0;
}
