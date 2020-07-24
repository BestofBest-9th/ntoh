#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "file.h"

int main(int argc, char *argv[])        // ./byte_ping <file1> <file2>
{
    FILE *f1, *f2;
    uint32_t buffer1, buffer2;
    if (argc != 3)
        return 1;
    else
    {
       buffer1 = file_make(argv[1], buffer1);
       buffer2 = file_make(argv[2], buffer2);
       
       
        //buffer1 = reinterpret_cast<uint32_t*>(&buffer1);
        //uint32_t *buf2 = reinterpret_cast<uint32_t*>(buffer2);
       
        uint32_t host1 = ntohl(buffer1);		//net -> host
	    uint32_t host2 = ntohl(buffer2);
        
        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", host1, host1, host2, host2, host1+host2, host1+host2);
    }
    return 0;

}









