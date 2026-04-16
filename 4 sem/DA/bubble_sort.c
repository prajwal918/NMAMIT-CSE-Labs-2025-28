#include <stdio.h>
#include <stdlib.h>
void read ( int b [100], int n )
{
    int i ;
    for ( i = 0; i < n ; i ++)
        scanf ("%d", & b [ i ]) ;
}
void display ( int b [100], int n )
{
    int i ;
    for ( i = 0; i < n ; i ++)
        printf ("%d\t", b [ i ]) ;
}

void sort ( int b [100], int n )
{
    int i, j, t, swap = 0, comp = 0, flag = 0;
    for ( i = 0; i < n - 1; i ++)
    {
        for ( j = 0; j < n - i - 1; j ++)
        {
            if ( b [ j ] > b [ j + 1])
            {
                t = b [ j ];
                b [ j ] = b [ j + 1];
                b [ j + 1] = t ;
                swap ++;
                flag = 1;
            }
            comp ++;
        }
        if ( flag == 0)
        {
            printf ("\nNoofswaps:%d\nNoofcomparisons:%d",
                    swap, comp ) ;
            return ;
        }
    }
    printf ("\nNoofswaps:%d\nNoofcomparisons:%d", swap, comp
           ) ;
}

int main ()
{
    int b [100], n ;
    printf ("Enternumberofelements:" ) ;
    scanf ("%d", & n ) ;
    printf ("Entertheelements:" ) ;
    read (b, n ) ;
    printf ("Elementsare:" ) ;
    display (b, n ) ;
    sort (b, n ) ;
    printf ("\nSortedarray:" ) ;
    display (b, n ) ;
    return 0;
}
