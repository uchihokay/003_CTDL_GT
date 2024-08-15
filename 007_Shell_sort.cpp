#include<iostream>            
#include<vector>
using namespace std;

void Shell_Sort(vector<int> &list){
    int index , value ;
    int i , j;
    for (int interval = list.size() / 2 ; interval > 0 ; interval /= 2){
        for ( i = interval ; i < list.size() ; i++){
            value = list[i];
            for ( j = i ; j >= interval && list[j - interval] > value ; j -= interval ){
                list[j] = list[j - interval];
            }
            list[j] = value;
        }
    }
}

int main(){
	int n ; 
	cout<<"n = ";cin>>n;
	vector<int> list ;

	int a;
	for (int i = 0 ; i < n ; i ++){
		cin>>a;
		list.push_back(a);
	}
	Shell_Sort(list);

	for (int i = 0 ; i < list.size() ; i++){
		cout<<list[i]<<" ";
	}
}
