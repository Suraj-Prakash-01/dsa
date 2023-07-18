#include <iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int row=1;

  while(row<=n){
    // Printing spaces
    int space=n-row;
    while(space){
      cout<<" ";
      space=space-1;
    }

    // Printing 1st pattern

    int j=1;
    while(j<=row){
      cout<<j;
      j=j+1;
    }

    // Printing 2nd pattern

    int start=row-1;
    while(start){
      cout<<start;
      start=start-1;
    }
    cout<<endl;
    row=row+1;
  }
}

 