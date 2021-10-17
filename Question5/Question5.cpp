using namespace std;
#include <string>
#include <iostream>

string solution(string s){

    int n=s.size();
    if(n==0) return "B";
    if(n==1){
        if(s[0]=='0')
            return "A";
        else
            return "B";
    }
    
    int nz=0;
    int ncz=0;
    int cur=0;
    int pre=0;
    bool r=false;
    
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            nz++;
            if(!r)
                cur=1;
            else
                cur++;
            r=true;
        }
        else
            r=false;
        ncz=max(ncz,cur);
    }
    if(nz==0 || nz==2)
        return "B";
    if(nz==1)
        return "A";
    if(ncz%2==0)
        return "B";
    else
         return "A";
}

int main(){
    string  n;
	  cin >> n;	
    string answer=solution(n);
	  cout << answer << endl;	
}
