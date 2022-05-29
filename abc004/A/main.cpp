#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

struct Edge{
  int from;
  int to;
  int cost;
};

int main(int argc, char *argv[]) {
  string s; cin>>s;
  int a=0, b=0, c=0;
  for(int i=0;i < s.size(); i++){
    if(s[i]=='a')a++;
    if(s[i]=='b')b++;
    if(s[i]=='c')c++;
  }
  if(abs(a-b)<=1 && abs(b-c)<=1 && abs(c-a)<=1){
    cout<<"YES"<<endl;
  }
  else cout<<"NO"<<endl;
  return 0;
}
