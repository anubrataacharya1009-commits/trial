#include<stdio.h>

int gcd( int x, int y)
{
int rem;
rem=x%y;

if( x==0 || y==0 )
{
printf("GCD is not possible");
}

else if( rem==0 )
{
return y;
}

else
{
return(gcd( y, rem));
}

}

int fibonacci(int n)
{

if(n<=1)
{
return n;
}

else
{
return(fibonacci(n-1)+fibonacci(n-2));
}}

 int main()
 {
 int x;
 printf("Enter your case number :");
 scanf("%d",&x);
 
 switch(x){
 
 case 1:
 {
 int a,b,hcf;
 printf("Enter your first number :");
 scanf("%d",&a);
 printf("Enter your second number :");
 scanf("%d",&b);
 hcf=gcd(a,b);
 printf("%d",hcf);
 }
 break;
 
 case 2:
 {
 int r;
 printf("Enter your range : ");
 scanf("%d",&r);
 for( int i=0;i<r;i++)
 {
 printf("%d\n",fibonacci(i));
 }}
 break;
 }
 return 0;
 }
