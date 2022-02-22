#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//二分搜
bool binary_search1(vector<int> &arr,int key){
    int left=0;
    int right=arr.size()-1;
    int mid;
    while(right>left){
        mid=(right+left)/2; /*因為資料已經經過排序
                                所以如果key比中間的數值小
                                代表他在陣列的左半邊
                                */
        if(key>arr[mid]){
            left=mid+1; //+1是因為已知mid不是解
        }
        else if(key<arr[mid]){
            right=mid-1;//-1是因為已知mid不是解
        }
        else{ //等於的情況，find
            return true;
        }
    }
    return false;
}
int main()
{
    int a,key;
    while(cin>>a){
        vector<int> arr(a);
        for(int i=0;i<a;i++){
            cin>>arr[i];
        }
        cin>>key;
        sort(arr.begin(),arr.end());
        if(binary_search1(arr,key)){
            cout<<"find"<<endl;
        }
        else{
            cout<<"not find"<<endl;
        }
    }
}
