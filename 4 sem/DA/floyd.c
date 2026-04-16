# i n c l u d e < s t d i o . h >

# d e f i n e M A X 1 0
# d e f i n e I N F 9 9 9 9 9

i n t n ;

v o i d f l o y d ( i n t d i s t [ M A X ] [ M A X ] )
{
i n t i , j , k ;

f o r ( k = 0 ; k < n ; k + + )
{
f o r ( i = 0 ; i < n ; i + + )
{
f o r ( j = 0 ; j < n ; j + + )
{
/ / I f p a t h t h r o u g h k i s s h o r t e r , u p d a t e d i s t [ i ] [ j ]
i f ( d i s t [ i ] [ k ] + d i s t [ k ] [ j ] < d i s t [ i ] [ j ] )
d i s t [ i ] [ j ] = d i s t [ i ] [ k ] + d i s t [ k ] [ j ] ;
}
}
}
}

v o i d p r i n t M a t r i x ( i n t d i s t [ M A X ] [ M A X ] )
{
f o r ( i n t i = 0 ; i < n ; i + + )
{
f o r ( i n t j = 0 ; j < n ; j + + )
{
i f ( d i s t [ i ] [ j ] = = I N F )
p r i n t f ( " I N F  " ) ;
e l s e
p r i n t f ( " % d    " , d i s t [ i ] [ j ] ) ;
}
p r i n t f ( " \ n " ) ;
}
}

i n t m a i n ( )
{
i n t d i s t [ M A X ] [ M A X ] ;

p r i n t f ( " E n t e r  t h e  n u m b e r  o f  v e r t i c e s :  " ) ;
s c a n f ( " % d " , & n ) ;

p r i n t f ( " E n t e r  t h e  d i s t a n c e  m a t r i x  ( u s e  9 9 9 9 9  f o r  I N F ) : \ n " ) ;
f o r ( i n t i = 0 ; i < n ; i + + )
{
f o r ( i n t j = 0 ; j < n ; j + + )
{
s c a n f ( " % d " , & d i s t [ i ] [ j ] ) ;
}
}

p r i n t f ( " O r i g i n a l  D i s t a n c e  M a t r i x : \ n " ) ;
p r i n t M a t r i x ( d i s t ) ;

f l o y d ( d i s t ) ;

p r i n t f ( " \ n S h o r t e s t  P a t h  M a t r i x : \ n " ) ;
p r i n t M a t r i x ( d i s t ) ;

r e t u r n 0 ;
}
