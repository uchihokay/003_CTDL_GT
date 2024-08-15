#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> &list , int l , int m , int r){
	int n1 = m - l + 1;
	int n2 = r - m ;
	vector<int> L(n1);
	vector<int> R(n2);

	for (int i = 0 ; i < n1 ; i++){
		L[i] = list[l + i];
	}
	for (int i = 0 ; i < n2 ; i++){
		R[i] = list[m + i + 1];
	}

	int i = 0 ;
	int j = 0 ;
	int k = l ;
	while(i < n1 && j < n2){
		if (L[i] <= R[j]){
			list[k] = L[i];
			i++;
		}
		else{
			list[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		list[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		list[k] = R[j];
		j++;
		k++;
	}
}

void Merge_Sort(vector<int> &list , int l , int r){
	if (l < r){
		int m = (l + r) / 2;
		Merge_Sort(list,l,m);
		Merge_Sort(list,m+1,r);
		Merge(list,l,m,r);
	}
}

int main(){
	int n ; cout<<"n = ";cin>>n;
	vector<int> list;

	int x;
	for (int i = 0 ; i < n ; i++){
		cin>>x;
		list.push_back(x);
	}

	Merge_Sort(list,0,n - 1);

	for (int i = 0 ; i < n ; i++){
		cout<<list[i]<<" ";
	}
	return 0;
}
