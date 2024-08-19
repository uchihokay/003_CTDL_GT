#include<iostream>              //list phai tang dan hoac k giam
#include<vector>                // m = (l + r)/2;
using namespace std;

int BinarySearch(vector<int> list , int x ){
    int l , r ;
    l = 0;
    r = list.size() - 1;

    while(l < r){
        int m = (l + r)/2;
        
        if (list[m] < x){
            l = m + 1;
        }
        else {
            r = m ;
        }
    }
    if (list[l] == x){
        return l;
    }
    return -1;
    
}

int main(){
    int n ; cout<<"n = ";cin>>n;
    vector<int> list;
    for (int i = 0 ; i < n ; i++){
        int value;
        cin>>value;
        list.push_back(value);
    }

    int x;
    cout<<"x = ";cin>>x;

    cout<<BinarySearch(list,x);

}
