#include <stdio.h>
#include <stdlib.h>
int a [100] , c [100];
void read ( int n )
{
int i ;
printf ("Entertheelements:" ) ;
for ( i =0; i < n ; i ++)
scanf ("%d" , & a [ i ]) ;
}

void display ( int n )
{
int i ;
for ( i =0; i < n ; i ++)
printf ("%d\t" , a [ i ]) ;
}

void merge ( int low , int mid , int high )
{
int i , j , k ;
i = low ;
j = mid + 1;
k = low ;

while ( i <= mid && j <= high )
{
if ( a [ i ] <= a [ j ])
c [ k ] = a [ i ++];
else
c [ k ] = a [ j ++];
k ++;
}

while ( i <= mid )
{
c [ k ] = a [ i ];
i ++;
k ++;
}

while ( j <= high )
{
c [ k ] = a [ j ];
j ++;
k ++;
}

for ( i = low ; i <= high ; i ++)
a [ i ] = c [ i ];
}

void mergesort ( int low , int high )
{
if ( low < high )
{
int mid = ( low + high ) / 2;
mergesort ( low , mid ) ;
mergesort ( mid + 1 , high ) ;
merge ( low , mid , high ) ;
}
}

int main ()
{
int n ;
printf ("Enterthenumberofelements:" ) ;
scanf ("%d" , & n ) ;
read ( n ) ;
printf ("Elementsare:" ) ;
display ( n ) ;
mergesort (0 , n -1) ;
printf ("\nSortedarray:" ) ;
display ( n ) ;
return 0;
}
