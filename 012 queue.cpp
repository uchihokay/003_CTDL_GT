#include<iostream>				//tim cac snt <= n
#include<queue>
using namespace std;

bool songuyento(int n ){                          //kiem tra so ngto
	int a = 0 ;
	for(int i = 1 ;i <= n ;i++){
		if (n%i==0){
			a++;
		}
	}
	if (a==2){
		a=0;
		return true;
	}
	else {
		a=0;
		return false;
	}
}

int main(){
	int n ; 
	cout<<"n = ";
	cin>>n;
	queue<int> st;
	for (int i = 1;i<n;i++){                         //dung queue de them so nguyen to tim duoc
		if (songuyento(i)==true){
			st.push(i);
		}
	}
	while (st.empty() == 0){
		cout<<st.front()<<" ";
		st.pop();
	}
}

