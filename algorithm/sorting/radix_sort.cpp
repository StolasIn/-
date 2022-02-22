#include <iostream>
#include <vector>
using namespace std;
struct node{
    int real,div;
};
int con=256;
int max1=-INT_MAX;
void count_sort(vector<node>& arr){
    int n=arr.size();
    vector<node> ans;
    vector<vector<node>> d(con);
    for(int i=0;i<n;i++){
        d[arr[i].div%con].emplace_back(node{arr[i].real,arr[i].div/con});
    }
    for(int i=0;i<con;i++){
        ans.insert(ans.end(),d[i].begin(),d[i].end());
    }
    arr.clear();
    arr.assign(ans.begin(),ans.end());
}
void radix_sort(vector<node>& arr){
    int j;
    for(j=0;max1!=0;j++) max1/=con;
    for(int i=0;i<j;i++){
        count_sort(arr);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<node> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].real;
        arr[i].div=arr[i].real;
    }
    radix_sort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i].real<<" ";
    }
    cout<<endl;
}
