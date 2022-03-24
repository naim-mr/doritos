/* sort.c

 *    Test program to sort a large number of integers.

 *

 *    Intention is to stress virtual memory system.

 *

 *    Ideally, we could read the unsorted array off of the file system,

 *	and store the result back to the file system!

//

//  Copyright (c) 1999-2000 INSA de Rennes.

//  All rights reserved.

//  See copyright_insa.h for copyright notice and limitation

//  of liability and disclaimer of warranty provisions.

*/

// Nachos system calls

#include "userlib/libnachos.h"
#include "userlib/syscall.h"

// Table to be sorted

#define NUM 30

void jobSend() {
    char phil[9] = "philemon\0";
    n_printf("sending %s ...\n", phil);
    TtySend(phil);
}

void jobReceive() {
    char houdail[9];

    TtyReceive(houdail, 9);
    n_printf("receive %s OMG\n", houdail);
}
int

main()

{
    jobSend();
    // jobReceive();
    return 0;
}
