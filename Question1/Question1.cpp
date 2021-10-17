
#include <iostream>
using namespace std;

int solution(int n){
    int res = 0;
    res += (n/3)*2;
    int div = n%3;
    if(div!=0)
            res++;
    return res;
}

/*  Do not edit below code */
int main() {
	long long n;
	cin >> n;	
    long long answer=solution(n);
	cout << answer << endl;	
}
