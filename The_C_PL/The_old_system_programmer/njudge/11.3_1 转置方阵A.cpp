#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	int i,j;
	scanf("%d",&n);
	int a[100][110],b[33][444];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		b[j][i]=a[i][j];
	}
		for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		printf("%d ",b[i][j]);
		printf("\n");
	}
	system("pause");
	
}
