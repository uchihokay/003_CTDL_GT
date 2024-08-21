#include<iostream>
#include<stack>
using namespace std;

int main(){
	string s ;
	getline(cin,s);
	stack<char> st ;                     
	for (int i = 0 ; i < s.length() ; i++){
		st.push(s[i]);                     
	}
	for (int i = 0 ; i < s.length() ; i++){
		cout <<st.top();                  // lay gtri dau tien
		st.pop();						  // xoa cai dau
	}
	
}
