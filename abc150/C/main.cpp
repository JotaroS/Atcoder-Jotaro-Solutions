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
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}
std::uint32_t euclidean_gcd(std::uint32_t a, std::uint32_t b){return b != 0 ? euclidean_gcd(b, a % b) : a;}


void solve(int N, std::vector<int> P, std::vector<int> Q){
    vector <int> arr;
    string p;
    string q;
    REP(i, N){
        arr.PB(i+1);
        p+=to_string(P[i]);
        q+=to_string(Q[i]);
    }
    SORT(arr);
    string s;
    REP(i, N){
        s += to_string(arr[i]);
    }
    // cout<<s<<endl;
    vector <string > lists;
    do{
        lists.PB(s);
    }while(next_permutation(ALL(s)));
    SORT(lists);
    int idx1=0;
    int idx2=0;
    REP(i, lists.size()){
        if(lists[i]==p)idx1=i;
        if(lists[i]==q)idx2=i;
    }
    cout<<abs(idx1-idx2)<<endl;
}

int main(){
    int N;
    scanf("%d",&N);
    std::vector<int> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&P[i]);
    }
    std::vector<int> Q(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&Q[i]);
    }
    solve(N, std::move(P), std::move(Q));
    return 0;
}
