#include <iostream>

using namespace std;

int main(){
  int p=1;
  int sum=0;

  while(n!=0){
    int rem=n%10;
    p*=rem;
    sum=sum+rem;
    n=n/10;
  }
  int answer=p-sum;
  return answer;
}

