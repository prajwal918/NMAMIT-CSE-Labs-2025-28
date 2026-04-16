# i n c l u d e < s t d i o . h >
# i n c l u d e < s t d l i b . h >

i n t a [ 1 0 0 ] ;

v o i d r e a d ( i n t n )
{
f o r ( i n t i = 0 ; i < n ; i + + )
s c a n f ( " % d " , & a [ i ] ) ;
}

v o i d d i s p l a y ( i n t n )
{
f o r ( i n t i = 0 ; i < n ; i + + )
p r i n t f ( " % d \ t " , a [ i ] ) ;
}

v o i d i n s e r t i o n _ s o r t ( i n t n )
{
i n t k e y , j ;
f o r ( i n t i = 1 ; i < n ; i + + )
{
k e y = a [ i ] ;
j = i - 1 ;
w h i l e ( j > = 0 & & a [ j ] > k e y )
{
a [ j + 1 ] = a [ j ] ;
j - - ;
}
a [ j + 1 ] = k e y ;
}
}

i n t m a i n ( )
{
i n t n ;
p r i n t f ( " E n t e r  t h e  n u m b e r  o f  e l e m e n t s :  " ) ;
s c a n f ( " % d " , & n ) ;

p r i n t f ( " E n t e r  t h e  e l e m e n t s :  " ) ;
r e a d ( n ) ;

p r i n t f ( " \ n E l e m e n t s  a r e :  " ) ;
d i s p l a y ( n ) ;

i n s e r t i o n _ s o r t ( n ) ;

p r i n t f ( " \ n S o r t e d  a r r a y :  " ) ;
d i s p l a y ( n ) ;

r e t u r n 0 ;
}
