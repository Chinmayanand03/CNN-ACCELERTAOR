#include <stdio.h>
#include <stdint.h>

#define IN_H 64
#define IN_W 64
#define IN_C 3
#define OUT_C 16
#define K 3

void conv1_hls(
    int8_t input[IN_H][IN_W][IN_C],
    int8_t weights[K][K][IN_C][OUT_C],
    int8_t bias[OUT_C],
    int32_t output[IN_H-K+1][IN_W-K+1][OUT_C]
);

int main()
{
    static int8_t input[IN_H][IN_W][IN_C];
    static int8_t weights[K][K][IN_C][OUT_C];
    static int8_t bias[OUT_C];
    static int32_t output[IN_H-K+1][IN_W-K+1][OUT_C];

    for (int h=0; h<IN_H; h++)
        for (int w=0; w<IN_W; w++)
            for (int c=0; c<IN_C; c++)
                input[h][w][c] = 1;

    for (int kh=0; kh<K; kh++)
        for (int kw=0; kw<K; kw++)
            for (int ic=0; ic<IN_C; ic++)
                for (int oc=0; oc<OUT_C; oc++)
                    weights[kh][kw][ic][oc] = 1;

    for (int oc=0; oc<OUT_C; oc++)
        bias[oc] = 0;

    conv1_hls(input, weights, bias, output);

    printf("Output = %d\n", output[0][0][0]);

    return 0;
}