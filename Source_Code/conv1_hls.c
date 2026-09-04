#include <stdint.h>

#define IN_H 64
#define IN_W 64
#define IN_C 3

#define K 3
#define OUT_C 16

#define OUT_H (IN_H - K + 1)
#define OUT_W (IN_W - K + 1)

/*
Input size  = 64*64*3  = 12288
Weight size = 3*3*3*16 = 432
Bias size   = 16
Output size = 62*62*16 = 61504
*/

void conv1_hls(
    int8_t *input,
    int8_t *weights,
    int8_t *bias,
    int32_t *output
)
{

#pragma HLS INTERFACE m_axi port=input   offset=slave bundle=gmem0 depth=12288
#pragma HLS INTERFACE m_axi port=weights offset=slave bundle=gmem1 depth=432
#pragma HLS INTERFACE m_axi port=bias    offset=slave bundle=gmem1 depth=16
#pragma HLS INTERFACE m_axi port=output  offset=slave bundle=gmem2 depth=61504

#pragma HLS INTERFACE s_axilite port=input   bundle=control
#pragma HLS INTERFACE s_axilite port=weights bundle=control
#pragma HLS INTERFACE s_axilite port=bias    bundle=control
#pragma HLS INTERFACE s_axilite port=output  bundle=control
#pragma HLS INTERFACE s_axilite port=return  bundle=control


    for(int h = 0; h < OUT_H; h++)
    {
        for(int w = 0; w < OUT_W; w++)
        {

#pragma HLS PIPELINE II=1

            for(int oc = 0; oc < OUT_C; oc++)
            {

                int32_t sum = bias[oc];

                for(int kh = 0; kh < K; kh++)
                {
                    for(int kw = 0; kw < K; kw++)
                    {

#pragma HLS UNROLL

                        for(int ic = 0; ic < IN_C; ic++)
                        {

                            int in_index =
                            ((h + kh) * IN_W + (w + kw)) * IN_C + ic;

                            int wt_index =
                            ((kh * K + kw) * IN_C + ic) * OUT_C + oc;

                            sum +=
                            (int32_t)input[in_index] *
                            (int32_t)weights[wt_index];
                        }
                    }
                }

                int out_index =
                (h * OUT_W + w) * OUT_C + oc;

                output[out_index] = sum;
            }
        }
    }
}
