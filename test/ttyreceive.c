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

#include "userlib/syscall.h"
#include "userlib/libnachos.h"



// Table to be sorted

#define NUM 30

void jobReceive() {
    char houdail[9];

    TtyReceive(houdail, 8);
    n_printf("Received string %s\n", houdail);
}


int

main()

{

    
    jobReceive();

    return 0;
}