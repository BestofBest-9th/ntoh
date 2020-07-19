#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
uint32_t my_ntohs(uint32_t p);
int main(int argc, char *argv[])        // ./byte_ping <file1> <file2>
{
    FILE *f1, *f2;
       
    if (argc > 3)
        return 0;
    else
    {
        f1 = fopen(argv[1], "r");		//file open error
        if(f1 == NULL)
            printf("file1 is null \n");
        f2 = fopen(argv[2], "r");		//file open error
        if(f2 == NULL)
            printf("file2 is null \n");
      
	uint8_t buffer1[4];			//for file1 fread
	uint8_t buffer2[4];			//for file2 fread
	int re1,re2;				//fread size(buffer length)
        
        re1 = fread(buffer1, sizeof(uint8_t), 4, f1);
        re2 = fread(buffer2, sizeof(uint8_t), 4, f2);
        //printf("read1 is %d\n",re1);
        //printf("read2 is %d\n",re2);
       
        uint32_t *buf1 = reinterpret_cast<uint32_t*>(buffer1);
        uint32_t *buf2 = reinterpret_cast<uint32_t*>(buffer2);
       
        uint32_t host1 = my_ntohs(*buf1);		//net -> host
	uint32_t host2 = my_ntohs(*buf2);
        
        printf("%d(%x) + %d(%x) = %d(%x)\n", host1, host1, host2, host2, host1+host2, host1+host2);

    }


}

uint32_t my_ntohs(uint32_t p)
{
	//printf("\nmy_ntohs\n");
	//uint32_t n1 = (p & 0xFF000000) >> 24;
	//printf(" n1 = %x\n", n1);
	//uint32_t n2 = (p & 0x00FF0000) >> 8;
	//printf(" n2 = %x\n", n2);
	//uint32_t n3 = (p & 0x0000FF00) << 8;
	//printf(" n3 = %x\n", n3);
	//uint32_t n4 = (p & 0x000000FF) << 24;
	//printf(" n4 = %x\n", n4);
	
	return ((p & 0xFF000000) >> 24|(p & 0x00FF0000) >> 8|(p & 0x0000FF00) << 8|(p & 0x000000FF) << 24);
}







