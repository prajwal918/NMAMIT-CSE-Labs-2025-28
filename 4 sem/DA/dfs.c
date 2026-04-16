# i n c l u d e < s t d i o . h >

v o i d r e a d _ m a t ( i n t a [ 1 0 ] [ 1 0 ] , i n t n )
{
f o r ( i n t i = 0 ; i < n ; i + + )
{
f o r ( i n t j = 0 ; j < n ; j + + )
{
s c a n f ( " % d " , & a [ i ] [ j ] ) ;
}
}
}

v o i d d i s p l a y _ m a t ( i n t a [ 1 0 ] [ 1 0 ] , i n t n )
{
f o r ( i n t i = 0 ; i < n ; i + + )
{
f o r ( i n t j = 0 ; j < n ; j + + )
{
p r i n t f ( " % d \ t " , a [ i ] [ j ] ) ;
}
p r i n t f ( " \ n " ) ;
}
}

v o i d d f s ( i n t a d j _ m a t [ 1 0 ] [ 1 0 ] , i n t v i s i t e d [ ] , i n t v i s i t i n g , i n t n )
{
p r i n t f ( " V i s i t i n g  % d  V e r t e x \ n " , v i s i t i n g ) ;
v i s i t e d [ v i s i t i n g ] = 1 ;

f o r ( i n t i = 0 ; i < n ; i + + )
{
i f ( a d j _ m a t [ v i s i t i n g ] [ i ] = = 1 & & v i s i t e d [ i ] = = 0 )
{
d f s ( a d j _ m a t , v i s i t e d , i , n ) ;
}
}
}

i n t m a i n ( )
{
i n t n , s ;
p r i n t f ( " E n t e r  t h e  n u m b e r  o f  v e r t i c e s : \ n " ) ;
s c a n f ( " % d " , & n ) ;

i n t a d j _ m a t [ 1 0 ] [ 1 0 ] , v i s i t e d [ n ] ;

f o r ( i n t i = 0 ; i < n ; i + + )
v i s i t e d [ i ] = 0 ;

p r i n t f ( " E n t e r  t h e  a d j a c e n c y  m a t r i x : \ n " ) ;
r e a d _ m a t ( a d j _ m a t , n ) ;

p r i n t f ( " T h e  a d j a c e n c y  m a t r i x  i s : \ n " ) ;
d i s p l a y _ m a t ( a d j _ m a t , n ) ;

p r i n t f ( " E n t e r  t h e  s t a r t i n g  v e r t e x : \ n " ) ;
s c a n f ( " % d " , & s ) ;

d f s ( a d j _ m a t , v i s i t e d , s , n ) ;

r e t u r n 0 ;
}
