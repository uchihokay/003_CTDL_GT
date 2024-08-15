#include<iostream>              
#include<vector>
using namespace std;

void Selection_Sort(vector<int> &list){
	int IndexMin , temp;
	for (int i = 0 ; i < list.size() - 1 ; i++){
		IndexMin = i;
		for (int j = i ; j < list.size() ; j++){
				if (list[IndexMin] > list[j]){
					IndexMin = j;
				}
		}

		if (i != IndexMin){
			temp = list[i];
			list[i] = list[IndexMin];
			list[IndexMin] = temp;
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
	
	Selection_Sort(list);

	for (int i = 0 ; i < list.size() ; i++){
		cout<<list[i]<<" ";
	}
}
