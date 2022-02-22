#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void merge(vector<int>& num,int left,int mid,int right){
	vector<int> LeftArray(num.begin() + left, num.begin() + mid + 1);
    vector<int> RightArray(num.begin() + mid + 1, num.begin() + right + 1);
    int idxLeft = 0, idxRight = 0;

    LeftArray.insert(LeftArray.end(), INT_MAX);
    RightArray.insert(RightArray.end(), INT_MAX);
    for (int i = left; i <= right; i++) {
        if (LeftArray[idxLeft] < RightArray[idxRight]) {
            num[i] = LeftArray[idxLeft];
            idxLeft++;
        } 
        else {
            num[i] = RightArray[idxRight];
            idxRight++;
        }
    }
}
void merge_sort(vector<int>& num,int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		merge_sort(num,left,mid);
		merge_sort(num,mid+1,right);
		merge(num,left,mid,right);
	}
}
int main(){
	int a;
	cin>>a;
	vector<int> arr(a);
	for(int i=0;i<a;i++){
		cin>>arr[i];
	}
	merge_sort(arr,0,arr.size());
	for(int i=0;i<a;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}