//Sequential search
#include<iostream>
using namespace std;

int main(){
    int n,key;
    cout<<"Enter number of elements:";
    cin>>n;

    int a[n];
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<"Enter elements to search:";
    cin>>key;

    for(int i=0;i<n;i++){
        if(a[i]==key){
            cout<<"Elements found at position "<<i+1;
            return 0;
        }
    }

    cout<<"Elements not found";
    return 0;
}
