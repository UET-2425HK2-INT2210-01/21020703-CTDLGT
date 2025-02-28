#include <iostream>
 using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	int count[n]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0; i<n;i++){
		for(int j=i+1;j<n;++j){
			if(a[i]==a[j]){
				count[i]++;
			}
		}
	}
	int sum = 0;
	for(int i=0;i<n;i++){
		sum+=count[i];
	}
	cout << sum << endl;
}
