#include <stdio.h>
#include <stdint.h>

#define IN_H 64
#define IN_W 64
#define IN_C 3

#define OUT_C 16
#define K 3

#define OUT_H (IN_H-K+1)
#define OUT_W (IN_W-K+1)

void conv1_hls(
    int8_t *input,
    int8_t *weights,
    int8_t *bias,
    int32_t *output
);

int main()
{

    static int8_t input[64*64*3];
    static int8_t weights[3*3*3*16];
    static int8_t bias[16];
    static int32_t output[62*62*16];

    for(int i=0;i<64*64*3;i++)
        input[i]=1;

    for(int i=0;i<3*3*3*16;i++)
        weights[i]=1;

    for(int i=0;i<16;i++)
        bias[i]=0;

    conv1_hls(input,weights,bias,output);

    printf("Output[0] = %d\n",output[0]);

    return 0;
}
