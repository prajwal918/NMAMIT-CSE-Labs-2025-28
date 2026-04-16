# i n c l u d e < s t d i o . h >
# i n c l u d e < s t d l i b . h >

# d e f i n e M A X 1 0 0

i n t g r a p h [ M A X ] [ M A X ] ;
i n t i n d e g r e e [ M A X ] , n ;

v o i d t o p o l o g i c a l _ s o r t ( )
{
i n t v i s i t e d [ M A X ] = { 0 } ;
i n t c o u n t = 0 ;

w h i l e ( c o u n t < n )
{
i n t f o u n d = 0 ;
f o r ( i n t i = 0 ; i < n ; i + + )
{
i f ( i n d e g r e e [ i ] = = 0 & & ! v i s i t e d [ i ] )
{
p r i n t f ( " % d \ t " , i ) ;
v i s i t e d [ i ] = 1 ;
f o u n d = 1 ;
c o u n t + + ;

f o r ( i n t j = 0 ; j < n ; j + + )
{
i f ( g r a p h [ i ] [ j ] = = 1 )
i n d e g r e e [ j ] - - ;
}
}
}

i f ( ! f o u n d )
{
p r i n t f ( " C y c l e  d e t e c t e d !  T o p o l o g i c a l  S o r t  n o t  p o s s i b l e "
) ;
r e t u r n ;
}
}
}

i n t m a i n ( )
{
p r i n t f ( " E n t e r  n u m b e r  o f  v e r t i c e s :  " ) ;
s c a n f ( " % d " , & n ) ;

p r i n t f ( " E n t e r  a d j a c e n c y  m a t r i x : \ n " ) ;
f o r ( i n t i = 0 ; i < n ; i + + )
{
f o r ( i n t j = 0 ; j < n ; j + + )
{
s c a n f ( " % d " , & g r a p h [ i ] [ j ] ) ;
i f ( g r a p h [ i ] [ j ] = = 1 )
i n d e g r e e [ j ] + + ;
}
}

p r i n t f ( " T o p o l o g i c a l  O r d e r : \ n " ) ;
t o p o l o g i c a l _ s o r t ( ) ;

r e t u r n 0 ;
}
