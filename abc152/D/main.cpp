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


int num_keta(string s){
    return s.size();
}
int reverseDigits(int num) 
{ 
    int rev_num = 0; 
    while (num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
} 
void solve(long long N){
    string s;
    // int max_keta = 0;
    // s = to_string(N);
    // max_keta = s.size();
    // int ans=0;
    // for(int i=1; i<=N; i++){
    //     string s = to_string(i);
    //     if(s[0]==s[num_keta(s)-1]){
    //         for(int j = 0; j<=max_keta; j++){
    //             int factor = (pow(10,j)); if(factor==1)factor=0;
    //             if((int)(s[0]-48) * ((factor+1))>N)break;
    //             if(j==0)ans++;
    //             else if(j==1)ans++;
    //             else{
    //                 ans+=(j-2)*9;
    //             }
    //             // if(j+1 == num_keta(s))ans--;
    //         }
    //     }
    //     debug(i);
    //     debug(ans)
    // }
    int ans=0;
    int max_keta = to_string(N).size();
    for(int i=1; i <= N; i++){
        s = to_string(i);
        // int keta = s.length()-1;
        string core=to_string(reverseDigits(i));
        if(i%10==0)continue;
        if(stoi(core)<=N && core[0]==s[s.size()-1] && s[0] == core[core.size()-1])
        {
                ans++;
                cout<<s<<","<<core<<endl;
        
        }
        for(int j = 0; j <max_keta; j++){
            int factor = pow(10, j)-1;//99, 9999;
            for(int k = 0; k <= N; k++)
            {
                if(factor==0)break;
                string num = "0";
                string res = to_string(k);
                num.insert(1, res);
                // debug(res)
                if(stoi(num)<=N && num[0]==s[s.size()-1] && s[0] == num[num.size()-1]){
                    ans++;
                    // if(stoi(s)<stoi(num))ans++;
                    cout<<s<<","<<num<<endl;
                }
                if(stoi(num)>N)break;
            }
        }
    }

    cout<<ans<<endl;

}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
