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


void solve(std::vector<long long> E, long long B, std::vector<long long> L){
    vector<LL> map(10);
    bool bonus= false;
    REP(i, 10){
        map[i]=0;
    }
    REP(i, 6){
        map[E[i]]=1;
    }
    int cnt =0;
    REP(i, 6){
        if(map[L[i]]==1)cnt++;
    }
    if(cnt==5){
        REP(i, 6){
            if(L[i]==B)bonus=true;
        }
    }
    // debug(cnt)
    int grade=0;
    if(cnt==6)grade=1;
    else if(cnt==5&&bonus==true)grade=2;
    else if(cnt==5&&bonus==false)grade=3;
    else if(cnt==4)grade=4;
    else if(cnt==3)grade=5;
    else grade=0;
    cout<<grade<<endl;
    return;
    
}

int main(){
    int t;
    cin>>t;
    REP(_, t){
        LL n,s,k;
        cin>>n>>s>>k;
        vector<LL>cls(k);
        REP(__,k){
            cin>>cls[__];
        }
        SORT(cls);
    
        if(find(cls.begin(), cls.end(),s)==cls.end()){//starting point is opened
            cout<<0<<endl;
            continue;
        }
        else{
            REP(i, 10000){
                LL upfloor=min(n,s+i);
                LL downfloor=max((LL)1,s-i);
                // debug(upfloor);
                // debug(downfloor);
                if(find(cls.begin(),cls.end(), upfloor)==cls.end()){cout<<i<<endl;break;}
                if(find(cls.begin(),cls.end(), downfloor)==cls.end()){cout<<i<<endl;break;}
            }
        }
    }
    return 0;
}
