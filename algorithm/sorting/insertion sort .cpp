#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void instr(vector<int>& num){
	int j;
	for(int i=1;i<num.size();i++){
		int tmp=num[i];
		for(j=i-1;j>=0;j--){
			if(tmp<num[j]) num[j+1]=num[j];
			else{
				break;
			}
		}
		swap(num[j+1],tmp);
	}
	return;
}
int main(){
	int a;
	cin>>a;
	vector<int> arr(a);
	for(int i=0;i<a;i++){
		cin>>arr[i];
	}
	instr(arr);
	for(int i=0;i<a;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}