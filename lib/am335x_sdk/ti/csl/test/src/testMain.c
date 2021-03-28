/*
 * main.c
 *
 *  Created on: May 12, 2014
 *      Author: a0756924
 */


#include <stdio.h>
#include <stdlib.h>
#include "ti/csl/cslver.h"

/* Has all the tests that needs to be done */
#include "tests.h"

void main(void)
{
	/* Get CSL version for the test*/
	printf ("%s \n", CSL_VERSION_STR);
	/* Cache Write Through test */
	csl_CacheWriteThroughTest();
}
