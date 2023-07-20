#include <iostream>

using namespace std;

int main(){
  int n;
  cout<<" Enter the value of n"<<endl;
  cin>>n;

  int a=0;
  int b=1;
  cout<<a<<" "<<endl;
  cout<<b<<" "<<endl;
  for(int i=1; i<=n;i++){
    int nxt=a+b;
    cout<<nxt<<endl;
    a=b;
    b=nxt;

  }
}
