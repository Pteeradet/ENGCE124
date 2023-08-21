/* 
Program Recursion can..
1. Calculate Factorial Function
2. Show each step of recursive result
3. Show final result
=======================================================================
=========
*/
#include <stdio.h> //use printf()
#include <conio.h> //use getch()
int Number , ans ;
int Factorial( int N ) { //Factorial Function
 int x , y ;
 if( N == 0 ) {
 printf( "...............Roll Back Point\n" ) ;
 return( 1 ) ;
 } else { 
 x = N - 1 ; 
 printf( "%2d! = %2d * %2d!\n" , N , N , x ) ; //Displaybefore Recursive
 y = Factorial( x ) ;
 printf( "%2d! = %2d * %3d = %5d\n" , N , N , y , y * N ) 
; //Display After Recursive
 return( N * y ) ;
 } 
} //End Fn
int main() {
 printf( "RECRSIVE(FACTORIAL) PROGRAM\n" ) ;
 printf( "===========================\n" ) ;
 //N=0;
 while( Number != -999 ) {
 printf( "Enter Number (-999 is END) : " ) ;
 scanf( "%d" , &Number ) ;
 if( Number >= 0 ) {
 printf( "N! = N(N-1)!\n" ) ;
 printf( "------------\n" ) ;
 ans = Factorial( Number ) ; //Recursive it self
 printf( "\nAnswer N! = %d\n" , ans ) ;
 printf( "----------------Finished\n" ) ;
 getch() ;
 }
 } //ENd while
 return(0); 
} //End Main
