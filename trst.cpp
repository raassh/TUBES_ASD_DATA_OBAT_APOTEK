#include <iostream>
using namespace std;

int main(){
    int j,i;
    int nilai[4];
    nilai[0]=9;
    nilai[1]=4;
    nilai[2]=5;
    nilai[3]=1;
    for(i=3;i>=1;i--){
        for(j=1;j<=i;j++){
            if(nilai[j-1]<nilai[j]){
                int tmp = nilai[j-1];
                nilai[j-1]=nilai[j];
                nilai[j]=tmp;
            }
        }
    }
    for(i=0;i<=3;i++){
        cout<<nilai[i]<<endl;
    }
    return (0);
}
