# i n c l u d e < s t d i o . h >

# d e f i n e M A X 1 0

i n t n ;

v o i d w a r s h a l l ( i n t g r a p h [ M A X ] [ M A X ] )
{
i n t i , j , k ;

f o r ( k = 0 ; k < n ; k + + )
{
f o r ( i = 0 ; i < n ; i + + )
{
f o r ( j = 0 ; j < n ; j + + )
{
/ / I f v e r t e x k i s o n a p a t h f r o m i t o j ,
/ / u p d a t e g r a p h [ i ] [ j ] u s i n g l o g i c a l O R
g r a p h [ i ] [ j ] = g r a p h [ i ] [ j ] | | ( g r a p h [ i ] [ k ] & & g r a p h
[ k ] [ j ] ) ;
}
}
}
}

v o i d p r i n t M a t r i x ( i n t g r a p h [ M A X ] [ M A X ] )
{
f o r ( i n t i = 0 ; i < n ; i + + )
{
f o r ( i n t j = 0 ; j < n ; j + + )
{
p r i n t f ( " % d  " , g r a p h [ i ] [ j ] ) ;
}
p r i n t f ( " \ n " ) ;
}
}

i n t m a i n ( )
{
i n t g r a p h [ M A X ] [ M A X ] ;

p r i n t f ( " E n t e r  t h e  n u m b e r  o f  v e r t i c e s :  " ) ;
s c a n f ( " % d " , & n ) ;

p r i n t f ( " E n t e r  t h e  a d j a c e n c y  m a t r i x : \ n " ) ;
f o r ( i n t i = 0 ; i < n ; i + + )
{
f o r ( i n t j = 0 ; j < n ; j + + )
{
s c a n f ( " % d " , & g r a p h [ i ] [ j ] ) ;
}
}

p r i n t f ( " O r i g i n a l  A d j a c e n c y  M a t r i x : \ n " ) ;
p r i n t M a t r i x ( g r a p h ) ;

w a r s h a l l ( g r a p h ) ;

p r i n t f ( " \ n T r a n s i t i v e  C l o s u r e : \ n " ) ;
p r i n t M a t r i x ( g r a p h ) ;

r e t u r n 0 ;
}
