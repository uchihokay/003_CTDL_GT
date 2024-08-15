#include<iostream>            
#include<vector>
using namespace std;

void Quick_Sort(vector<int> &list , int l , int r ){
	int p = list[(l + r) / 2];
	int i = l ;
	int j = r ;
    int temp;
	while (i <= j){
		while (list[i] < p){
			i++;
		}
		while (list[j] > p){
			j--;
		}

		if (i <= j){
			int temp = list[i];
			list[i] = list[j];
			list[j] = temp;
            i++;
            j--;
		}		
	}
    if (i < r){
        Quick_Sort(list,i,r);
    }
    if (l < j){
        Quick_Sort(list,l,j);
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


	Quick_Sort(list,0,n-1);


	for (int i = 0 ; i < list.size() ; i++){
		cout<<list[i]<<" ";
	}
}
