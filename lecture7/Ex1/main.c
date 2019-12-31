/**
 * The program consists of three protothreads that wait
 * for each other to toggle a variable.
 */
#include "pt.h"
#include <stdio.h>

/* Three flags that the three protothread functions use. */
static int protothread1_flag, protothread2_flag, protothread3_flag;


static int protothread1(struct pt *pt)
{
    PT_BEGIN(pt);

    while(1) {
        /* Wait until the other protothread has set its flag. */
        PT_WAIT_UNTIL(pt, protothread2_flag != 0 && protothread3_flag != 0);
        printf("Protothread 1 running\n");

        protothread2_flag = 1;
        protothread3_flag = 0;
        protothread1_flag = 1;
    }

    PT_END(pt);
}

/**
 * The second protothread function.
 */
static int protothread2(struct pt *pt)
{
    PT_BEGIN(pt);

    while(1) {
        /* Let the other protothread run. */
        protothread2_flag = 1;

        /* Wait until the other protothread has set its flag. */
        PT_WAIT_UNTIL(pt, protothread1_flag != 0 && protothread3_flag != 0);
        printf("Protothread 2 running\n");
        
        /* We then reset the other protothread's flag. */
        protothread1_flag = 0;
        protothread3_flag = 1;
    }
    PT_END(pt);
}

/**
 * The third protothread function.
 */
static int protothread3(struct pt *pt)
{
    PT_BEGIN(pt);

    while(1) {
        protothread3_flag = 1;

        /* Wait until the other protothread has set its flag. */
        PT_WAIT_UNTIL(pt, protothread1_flag != 0 && protothread2_flag != 0);
        printf("Protothread 3 running\n");
        
        /* We then reset the other protothread's flag. */
        protothread1_flag = 1;
        protothread2_flag = 0;
        protothread3_flag = 1;
    }
    PT_END(pt);
}

static struct pt pt1, pt2, pt3;

int main(void)
{
    /* Initialize the protothread state variables with PT_INIT(). */
    PT_INIT(&pt1);
    PT_INIT(&pt2);
    PT_INIT(&pt3);

    while(1) {
        protothread1(&pt1);
        protothread2(&pt2);
        protothread3(&pt3);
    }
}
