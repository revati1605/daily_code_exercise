#include<stdio.h>
void main()
	{
		int a[5],i,j,n,temp;
		n=sizeof(a)/sizeof(a[0]);
		printf("enter 5 numbers:\n");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
			{
				for(j=0;j<n-1-i;j++)
					{
						if(a[j]>a[j+1])
							{
								temp=a[j];
								a[j]=a[j+1];
								a[j+1]=temp;
							}
					}
			}
		printf("after sorting array is:\n");
		for(i=0;i<n;i++)
			printf("%d\n",a[i]);
	}
