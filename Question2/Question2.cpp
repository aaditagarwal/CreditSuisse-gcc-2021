#include <bits/stdc++.h>
using namespace std;
 
int securitiesBuying(int z, int arr[], int n)
{
    if(z==0)
        return 0;

    int no_of_stocks = 0;
    int ele = -1;
    while(z>0) {
        int minm = 51;
        int idx = -1;
        for(int i=0; i<n; i++){
            if( (arr[i]<minm) && (i!=(ele-1)) && (arr[i]!=-1) ) {
                minm = arr[i];
                idx = i;
            }
        }
        if(z<minm)
            break;
        ele = idx+1;
        arr[idx] = -1;
        int temp = (z/minm);
        if(temp >= ele){
            no_of_stocks += ele;
            z -= minm*ele;
        }
        else{
            no_of_stocks += temp;
            z -= minm*temp;
        }
    }
    return no_of_stocks;
}
 
int main(){
    int z;
    cin>>z;
    vector<int> input_data;
    string buffer;
    int data;
    getline(cin, buffer);
    getline(cin, buffer);
    istringstream iss(buffer);
 
    while (iss >> data)
        input_data.push_back(data);
 
    int n= input_data.size();
 
    int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
    int no_of_stocks_purchased = securitiesBuying(z,security_value,n);
    cout << no_of_stocks_purchased;
}