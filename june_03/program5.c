#include<stdio.h>
void main()
{
int a,b,gcd=0,i;
printf("enter two numbers:\n");
scanf("%d%d",&a,&b);
for(i=1;i<=a && i<=b;i++)
{
if(a%i==0 && b%i==0)
gcd=i;
}
printf("GCD of %d and %d is %d\n",a,b,gcd);
}

