/*
 * Create project on base OS Protothreads using a functions 
 * PT_WAIT_UNTIL,
 * PT_SCHEDULE
 */

#include "pt.h"
#include <stdio.h>

/* Three flags that the two protothread functions use. */
static int protothread1_flag, protothread2_flag;

/*
 * The first protothread function.
 */
static int
protothread1(struct pt *pt)
{
	     
  PT_BEGIN(pt);

  while(1) {
    /* Wait until the other protothread has set its flag. */
    PT_WAIT_UNTIL(pt, protothread2_flag != 0);
    printf("Protothread 1\n");

    protothread2_flag = 0; 
    protothread1_flag = 1; 
  }
  PT_END(pt);
}

/*
 * The second protothread function.
 */
static int
protothread2(struct pt *pt)
{
  PT_BEGIN(pt);

  while(1) {
    /* Let the other protothread run. */
    protothread2_flag = 1;

    /* Wait until the other protothread has set its flag. */
    PT_WAIT_UNTIL(pt, protothread1_flag != 0);
    
    printf("Protothread 2\n");

    protothread1_flag = 0; // reset flag protothread1
  }
  PT_END(pt);
}

static struct pt pt1, pt2;
int
main(void)
{
  PT_INIT(&pt1);
  PT_INIT(&pt2);
  

  while(1) {
    PT_SCHEDULE (protothread1(&pt1));
    PT_SCHEDULE (protothread2(&pt2));
  }
}