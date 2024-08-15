#include<iostream>              
#include<vector>
using namespace std;

int Bubble_Sort(vector<int> &list){
	for (int i = list.size() - 1 ; i > 0 ; i--){
		for (int j = 0 ; j < i ; j++){
			if (list[j] > list[j+1]){
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}

	for (int i = 0 ; i < list.size() ; i++){
		cout<<list[i]<<" ";
	}
}

int main(){
    int n ; cout<<"n = ";cin>>n;
    vector<int> list;
    for (int i = 0 ; i < n ; i++){
        int value;
        cin>>value;
        list.push_back(value);
    }

	Bubble_Sort(list);
	
}
