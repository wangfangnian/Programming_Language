#include<stdio.h>
int main(){
		int i,a[8]={1,2,3,4,5,6,7,8};
		int *pa;
		pa=a;
		for(i=0;i<8;i++)
		printf("%d ",*(pa+i));
}
