#include <stdio.h>

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#define         BYTE_VEC32(c)   ((c)*0x01010101UL)

static inline uint32_t rnd_avg32(uint32_t a, uint32_t b)
{
	
    return (a | b) - (((a ^ b) & ~BYTE_VEC32(0x01)) >> 1);
}

static inline uint32_t no_rnd_avg32(uint32_t a, uint32_t b)
{

    return (a & b) + (((a ^ b) & ~BYTE_VEC32(0x01)) >> 1);
}

int main(){
	uint8_t source0[32];
	uint8_t source1[32];
	uint8_t dst[32];
	
	int i;
	for(i=0;i<32;i++){
		source0[i]=i;
		source1[i]=33-i;
	}
	for(i=0;i<4;i++){
		*((uint32_t*)&dst[i*4]) = rnd_avg32(*((uint32_t*)&source0[i*4]),*((uint32_t*)&source1[i*4]));
	}

   for(i=0;i<16;i++){
/*		dst[i] = ( (source[i]<<1) | (source[i]>>4)) &0x1F;*/
/* int OffsThrRowPermuted = ((OffsThreadInRow << 1) | (OffsThreadInRow >> 4) & 0x1)&0x1F;*/
		printf("%d\t",dst[i]);
	}
	printf("\n");
}
