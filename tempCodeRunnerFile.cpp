#include <iostream>

using namespace std;

int main(){
  int n;
  int sum=0;
  int i=1;
  cout<<"Enter a number"<<endl;
  cin>>n;
  while(i>=n){
    if(i%2==0){
      sum=sum+i;
    }
    else{
      continue;
    }
    i+=1;
  }
  cout<<"Sum of even number are"<<sum<<endl;
}

 