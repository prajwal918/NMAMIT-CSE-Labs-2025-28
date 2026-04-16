#include <stdio.h>
#define MAX 105
int max( int a, int b) {
return (a > b) ? a : b;
}
int main () {
int n, m, i, j;
int w[MAX], p[MAX], v[MAX ][ MAX ];
printf ("Enter number of items:");
scanf ("%d", &n);
printf ("Enter knapsack capacity:");
scanf ("%d", &m);
printf ("Enter %d weights:\n", n);
for (i = 1; i <= n; i++) {
scanf ("%d", &w[i]);
}
printf ("Enter %d profits:\n", n);
for (i = 1; i <= n; i++) {
scanf ("%d", &p[i]);
}
for (i = 0; i <= n; i++) {
for (j = 0; j <= m; j++) {
if (i == 0 || j == 0) {
v[i][j] = 0;
} else if (w[i] > j) {
v[i][j] = v[i - 1][j];
} else {
v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
}
}
}
printf ("\nOptimal Solution (Maximum profit)=%d\n", v[n][m]);
printf ("Items added are:\n");
i = n;
j = m;
while (i >= 1) {
if (v[i][j] != v[i - 1][j]) {
printf ("Item %d\n", i);
j = j - w[i];
}
i --;
}
return 0;
}
