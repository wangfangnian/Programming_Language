#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int*maxv(int t[],int n){
	int *p=t;
	int i;
	for(i=0;i<n;i++){
		if(*p<t[i])
		p=&t[i];
	}
	return p;
}
int main(){
	int x[5][5],j,k,*pl=x[0];
	int (*px)[5]=x;
	srand(time(0));
	for(j=0;j<25;j++)
		*pl++=rand();
	for(j=0;j<5;j++,px++){
		pl=maxv(*px,5);
		printf("%d\t",*pl);
	}
}
