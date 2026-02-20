#include <stdint.h>

#define IN_H 64
#define IN_W 64
#define IN_C 3
#define OUT_C 16
#define K 3

#define OUT_H (IN_H - K + 1)
#define OUT_W (IN_W - K + 1)

void conv1_hls(
    int8_t input[IN_H][IN_W][IN_C],
    int8_t weights[K][K][IN_C][OUT_C],
    int8_t bias[OUT_C],
    int32_t output[OUT_H][OUT_W][OUT_C]
)
{
    for (int h = 0; h <= IN_H - K; h++)
    {
        for (int w = 0; w < OUT_W; w++)
        {
            for (int oc = 0; oc < OUT_C; oc++)
            {
                int32_t sum = 0;

                for (int kh = 0; kh < K; kh++)
                {
                    for (int kw = 0; kw < K; kw++)
                    {
                        for (int ic = 0; ic < IN_C; ic++)
                        {
                            sum +=
                            (int32_t)input[h+kh][w+kw][ic] *(int32_t)weights[kh][kw][ic][oc];
                        }
                    }
                }

                output[h][w][oc] = sum + bias[oc];
            }
        }
    }
}