#include <iostream>
#include<string>
#include<algorithm>

using namespace std;
int main() {
	long long int num;
	cin >> num;    
	long long int k;
	cin>>k;
   
	for(long long int j = 0; j < k; j++)
    {
         long long int ans = 0;
        long long int i = 1;
        long long int temp;
        
        while(num/i>0)
        {
            
            temp = (num/(i*10))*i+(num%i);
            i *= 10;
            ans = max(ans,temp);
        }
       num = ans;
       cout<<num<<endl;
    }
    cout<<num;
    return 0;
}