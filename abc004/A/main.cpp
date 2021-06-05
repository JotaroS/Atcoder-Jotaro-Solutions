#include <iostream>
#include <string>
using namespace std;


int main(int argc, char *argv[]) {
    int cnt=0;
  for(int i=1; i<1000; i++){ 
     if(1000%i==0)cnt++;
  }
  cout<<cnt;
  return 0;
}
