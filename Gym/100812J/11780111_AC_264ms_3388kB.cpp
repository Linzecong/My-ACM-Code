#include   <stdio.h> 
 #include   <tchar.h> 
 #include   <iostream> 
 #include   <vector> 

 using namespace std ; 

  int main () 
  { 
  vector <int> bandits ;
    vector <int> flag ; 
      int n ; 
      int maxban = 0 ; 
	   cin >> n ; 
     for( int it = 0 ;  it < n ;  it ++) 
     { 
          int tmp ;
		    cin >> tmp ;
			  bandits.push_back (tmp); 
         if ( tmp > maxban ) 
		 maxban = tmp ;
		 
		   flag.push_back ( 0 ); 
     } 

     if  ( maxban < n ) 
     cout << n << endl ; 
      else { 
          maxban = min ( maxban , n ); 

         while ( maxban >  0 ) 
         { 
              int count =    0 ; 
             for    ( int it =   0 ;  it < n ;  it ++) 
             { 
                 if  ( flag [ it ]  ==   0  && bandits [ it ]    >= maxban ) 
                  { 
                      flag [ it ]   =    1 ;
                        count ++; 
                 } 
             } 
             if  ( count == 0 ) 
                  break;  
			maxban = maxban - count ; 
          }
          
        cout << maxban << endl ; 
     } 

     return    0 ; 
 } 