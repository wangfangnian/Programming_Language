#include<stdio.h>
int main(){
	int a[36],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int max=a[0];
	for(i=0;i<n;i++){
		if(a[i]<max){
			max=a[i];
		}
	}
	for(i=0;i<n;i++){
		a[i]=a[i]-max;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
} 
