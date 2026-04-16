# i n c l u d e < s t d i o . h >
# i n c l u d e < s t d l i b . h >
# i n c l u d e < s t r i n g . h >

# d e f i n e M A X 2 5 6

i n t t a b l e [ M A X ] ;

v o i d s h i f t T a b l e ( c h a r p a t t e r n [ ] , i n t m )
{
i n t i ;
f o r ( i = 0 ; i < M A X ; i + + )
t a b l e [ i ] = m ;
f o r ( i = 0 ; i < m - 1 ; i + + )
t a b l e [ ( i n t ) p a t t e r n [ i ] ] = m - 1 - i ;
}

i n t h o r s p o o l ( c h a r t e x t [ ] , c h a r p a t t e r n [ ] )
{
i n t i , j , k ;
i n t n = s t r l e n ( t e x t ) ;
i n t m = s t r l e n ( p a t t e r n ) ;

s h i f t T a b l e ( p a t t e r n , m ) ;

i = m - 1 ;
w h i l e ( i < n )
{
k = 0 ;
w h i l e ( k < m & & p a t t e r n [ m - 1 - k ] = = t e x t [ i - k ] )
k + + ;

i f ( k = = m )
r e t u r n i - m + 1 ;
e l s e
i + = t a b l e [ ( i n t ) t e x t [ i ] ] ;
}
r e t u r n - 1 ;
}

i n t m a i n ( )
{
c h a r t e x t [ 1 0 0 ] , p a t t e r n [ 5 0 ] ;
i n t p o s ;

p r i n t f ( " E n t e r  t e x t :  " ) ;
s c a n f ( " % s " , t e x t ) ;
p r i n t f ( " E n t e r  p a t t e r n :  " ) ;
s c a n f ( " % s " , p a t t e r n ) ;

p o s = h o r s p o o l ( t e x t , p a t t e r n ) ;

i f ( p o s = = - 1 )
p r i n t f ( " P a t t e r n  n o t  f o u n d \ n " ) ;
e l s e
p r i n t f ( " P a t t e r n  f o u n d  a t  p o s i t i o n  % d \ n " , p o s ) ;

r e t u r n 0 ;
}
