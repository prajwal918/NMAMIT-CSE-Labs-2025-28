# i n c l u d e < s t d i o . h >
# i n c l u d e < s t d l i b . h >

v o i d p r i n t a r r a y ( i n t a r r [ ] , i n t n )
{
f o r ( i n t i = 0 ; i < n ; i + + )
p r i n t f ( " % d \ t " , a r r [ i ] ) ;
}

v o i d s w a p ( i n t * a , i n t * b )
{
i n t t e m p = * a ;
* a = * b ;
* b = t e m p ;
}

v o i d h e a p i f y ( i n t a r r [ ] , i n t n , i n t i )
{
i n t l a r g e s t = i ;
i n t l e f t = 2 * i + 1 ;
i n t r i g h t = 2 * i + 2 ;

i f ( l e f t < n & & a r r [ l e f t ] > a r r [ l a r g e s t ] )
l a r g e s t = l e f t ;

i f ( r i g h t < n & & a r r [ r i g h t ] > a r r [ l a r g e s t ] )
l a r g e s t = r i g h t ;

i f ( l a r g e s t ! = i )
{
s w a p ( & a r r [ i ] , & a r r [ l a r g e s t ] ) ;
h e a p i f y ( a r r , n , l a r g e s t ) ;
}
}

v o i d h e a p s o r t ( i n t a r r [ ] , i n t n )
{
f o r ( i n t i = n / 2 - 1 ; i > = 0 ; i - - )
h e a p i f y ( a r r , n , i ) ;

f o r ( i n t i = n - 1 ; i > = 0 ; i - - )
{
s w a p ( & a r r [ 0 ] , & a r r [ i ] ) ;
h e a p i f y ( a r r , i , 0 ) ;
}
}

i n t m a i n ( )
{
i n t a r r [ 2 0 ] , n ;

p r i n t f ( " E n t e r  t h e  n u m b e r  o f  e l e m e n t s : \ n " ) ;
s c a n f ( " % d " , & n ) ;

p r i n t f ( " E n t e r  % d  e l e m e n t s :  " , n ) ;
f o r ( i n t i = 0 ; i < n ; i + + )
s c a n f ( " % d " , & a r r [ i ] ) ;

h e a p s o r t ( a r r , n ) ;

p r i n t f ( " S o r t e d  a r r a y : \ n " ) ;
p r i n t a r r a y ( a r r , n ) ;

r e t u r n 0 ;
}
