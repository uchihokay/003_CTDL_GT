#include<iostream>
#include <iomanip>
using namespace std;

int main(){
	int n ,m;
	int arr1[100],arr2[100],arr3[100];
	
	cout<<"Day thu nhat "<<"\n";
	cout<<"Nhap n :"; cin>>n;
	for (int i = 0 ; i < n ; i ++){
		cout<<"So thu "<<i+1<<": ";
		cin>>arr1[i];
	}
	
	cout<<"\nDay thu 2  "<<"\n";
	cout<<"Nhap m :"; cin>>m;
	for (int i = 0 ; i < m ; i ++){
		cout<<"So thu "<<i+1<<": ";
		cin>>arr2[i];
	}
	
	int bien1 = m + n;
	int bien2 = 0 ;
	int bien3;
	
	for (int i = 0 ; i <n ; i ++){
		arr3[bien2]=arr1[i];
		bien2++;
	}
	for (int i = 0 ; i <m ; i ++){
		arr3[bien2]=arr2[i];
		bien2++;
	}
	for (int i = 0 ; i < bien1 ; i++){
		for (int j = i + 1; j <bien1; j ++){
			if (arr3[i]>arr3[j]){
				bien3 = arr3[i];
				arr3[i]=arr3[j];
				arr3[j]=bien3;
			}
		}
	}
	
	for (int i = 0 ; i < bien1 ; i ++){
		cout<<arr3[i]<<" ";
	}	
}





