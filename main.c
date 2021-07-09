
#include <stdio.h>
// para printf


#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include "CDLL.h"


void Print( int item )
{
	printf( "%d\n", item );
}

bool less_than( int list_val, int user_val ){ return list_val < user_val; }




//----------------------------------------------------------------------
//  Driver program
//----------------------------------------------------------------------
int main(void)
{
	CDLL* list = CDLL_New();
	
	


	CDLL_Delete( &list );
	return 0;
}
