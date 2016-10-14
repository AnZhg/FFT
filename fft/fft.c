//
//  fft.c
//  fft
//
//  Created by 安志钢 on 16-10-13.
//  Copyright (c) 2016年 安志钢. All rights reserved.
//

#include "fft.h"
#include <math.h>
#include <string.h>

void fft(complex *io[8])
{
    complex tmp[8];
    
    // Two-point.
    tmp[0].re = io[0]->re + io[4]->re;
    tmp[0].im = io[0]->im + io[4]->im;
    tmp[1].re = io[0]->re - io[4]->re;
    tmp[1].im = io[0]->im - io[4]->im;
    tmp[2].re = io[2]->re + io[6]->re;
    tmp[2].im = io[2]->im + io[6]->im;
    tmp[3].re = io[2]->re - io[6]->re;
    tmp[3].im = io[2]->im - io[6]->im;
    tmp[4].re = io[1]->re + io[5]->re;
    tmp[4].im = io[1]->im + io[5]->im;
    tmp[5].re = io[1]->re - io[5]->re;
    tmp[5].im = io[1]->im - io[5]->im;
    tmp[6].re = io[3]->re + io[7]->re;
    tmp[6].im = io[3]->im + io[7]->im;
    tmp[7].re = io[3]->re - io[7]->re;
    tmp[7].im = io[3]->im - io[7]->im;
    
    // Four-point.
    io[0]->re = tmp[0].re + tmp[2].re;
    io[0]->im = tmp[0].im + tmp[2].im;
    io[1]->re = tmp[1].re - tmp[3].im;
    io[1]->im = tmp[1].im + tmp[3].re;
    io[2]->re = tmp[0].re - tmp[2].re;
    io[2]->im = tmp[0].im - tmp[2].im;
    io[3]->re = tmp[1].re + tmp[3].im;
    io[3]->im = tmp[1].im - tmp[3].re;
    io[4]->re = tmp[4].re + tmp[6].re;
    io[4]->im = tmp[4].im + tmp[6].im;
    io[5]->re = tmp[5].re - tmp[7].im;
    io[5]->im = tmp[5].im + tmp[7].re;
    io[6]->re = tmp[4].re - tmp[6].re;
    io[6]->im = tmp[4].im - tmp[6].im;
    io[7]->re = tmp[5].re + tmp[7].im;
    io[7]->im = tmp[5].im - tmp[7].re;
    
    // Eight-point.
    double p1, p2, sum1, sum2;
    tmp[0].re = io[0]->re + io[4]->re;
    tmp[0].im = io[0]->im + io[4]->im;
    tmp[4].re = io[0]->re - io[4]->re;
    tmp[4].im = io[0]->im - io[4]->im;
    
    p1 = M_SQRT1_2 * io[5]->re;
    p2 = M_SQRT1_2 * io[5]->im;
    sum1 = p1 + p2;
    sum2 = p1 - p2;
    tmp[1].re = io[1]->re + sum2;
    tmp[1].im = io[1]->im + sum1;
    tmp[5].re = io[1]->re - sum2;
    tmp[5].im = io[1]->im - sum1;
    
    tmp[2].re = io[2]->re - io[6]->im;
    tmp[2].im = io[2]->im + io[6]->re;
    tmp[6].re = io[2]->re + io[6]->im;
    tmp[6].im = io[2]->im - io[6]->re;
    
    p1 = M_SQRT1_2 * io[7]->re;
    p2 = M_SQRT1_2 * io[7]->im;
    sum1 = p1 + p2;
    sum2 = p1 - p2;
    tmp[3].re = io[3]->re - sum1;
    tmp[3].im = io[3]->im + sum2;
    tmp[7].re = io[3]->re + sum1;
    tmp[7].im = io[3]->im - sum2;
    
    *io[0] = tmp[0];
    *io[1] = tmp[1];
    *io[2] = tmp[2];
    *io[3] = tmp[3];
    *io[4] = tmp[4];
    *io[5] = tmp[5];
    *io[6] = tmp[6];
    *io[7] = tmp[7];
}

void ifft(complex *io[8])
{
    complex tmp[8];
    
    // Two-point.
    tmp[0].re = io[0]->re + io[4]->re;
    tmp[0].im = io[0]->im + io[4]->im;
    tmp[1].re = io[0]->re - io[4]->re;
    tmp[1].im = io[0]->im - io[4]->im;
    tmp[2].re = io[2]->re + io[6]->re;
    tmp[2].im = io[2]->im + io[6]->im;
    tmp[3].re = io[2]->re - io[6]->re;
    tmp[3].im = io[2]->im - io[6]->im;
    tmp[4].re = io[1]->re + io[5]->re;
    tmp[4].im = io[1]->im + io[5]->im;
    tmp[5].re = io[1]->re - io[5]->re;
    tmp[5].im = io[1]->im - io[5]->im;
    tmp[6].re = io[3]->re + io[7]->re;
    tmp[6].im = io[3]->im + io[7]->im;
    tmp[7].re = io[3]->re - io[7]->re;
    tmp[7].im = io[3]->im - io[7]->im;
    
    // Four-point.
    io[0]->re = tmp[0].re + tmp[2].re;
    io[0]->im = tmp[0].im + tmp[2].im;
    io[1]->re = tmp[1].re + tmp[3].im;
    io[1]->im = tmp[1].im - tmp[3].re;
    io[2]->re = tmp[0].re - tmp[2].re;
    io[2]->im = tmp[0].im - tmp[2].im;
    io[3]->re = tmp[1].re - tmp[3].im;
    io[3]->im = tmp[1].im + tmp[3].re;
    io[4]->re = tmp[4].re + tmp[6].re;
    io[4]->im = tmp[4].im + tmp[6].im;
    io[5]->re = tmp[5].re + tmp[7].im;
    io[5]->im = tmp[5].im - tmp[7].re;
    io[6]->re = tmp[4].re - tmp[6].re;
    io[6]->im = tmp[4].im - tmp[6].im;
    io[7]->re = tmp[5].re - tmp[7].im;
    io[7]->im = tmp[5].im + tmp[7].re;
    
    // Eight-point.
    double p1, p2, sum1, sum2;
    tmp[0].re = io[0]->re + io[4]->re;
    tmp[0].im = io[0]->im + io[4]->im;
    tmp[4].re = io[0]->re - io[4]->re;
    tmp[4].im = io[0]->im - io[4]->im;
    
    p1 = M_SQRT1_2 * io[5]->re;
    p2 = M_SQRT1_2 * io[5]->im;
    sum1 = p1 + p2;
    sum2 = p1 - p2;
    tmp[1].re = io[1]->re + sum1;
    tmp[1].im = io[1]->im - sum2;
    tmp[5].re = io[1]->re - sum1;
    tmp[5].im = io[1]->im + sum2;
    
    tmp[2].re = io[2]->re + io[6]->im;
    tmp[2].im = io[2]->im - io[6]->re;
    tmp[6].re = io[2]->re - io[6]->im;
    tmp[6].im = io[2]->im + io[6]->re;
    
    p1 = M_SQRT1_2 * io[7]->re;
    p2 = M_SQRT1_2 * io[7]->im;
    sum1 = p1 + p2;
    sum2 = p1 - p2;
    tmp[3].re = io[3]->re - sum2;
    tmp[3].im = io[3]->im - sum1;
    tmp[7].re = io[3]->re + sum2;
    tmp[7].im = io[3]->im + sum1;
    
    io[0]->re = tmp[0].re / 8.0;
    io[0]->im = tmp[0].im / 8.0;
    io[1]->re = tmp[1].re / 8.0;
    io[1]->im = tmp[1].im / 8.0;
    io[2]->re = tmp[2].re / 8.0;
    io[2]->im = tmp[2].im / 8.0;
    io[3]->re = tmp[3].re / 8.0;
    io[3]->im = tmp[3].im / 8.0;
    io[4]->re = tmp[4].re / 8.0;
    io[4]->im = tmp[4].im / 8.0;
    io[5]->re = tmp[5].re / 8.0;
    io[5]->im = tmp[5].im / 8.0;
    io[6]->re = tmp[6].re / 8.0;
    io[6]->im = tmp[6].im / 8.0;
    io[7]->re = tmp[7].re / 8.0;
    io[7]->im = tmp[7].im / 8.0;
}
