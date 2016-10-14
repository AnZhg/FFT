//
//  fft.h
//  fft
//
//  Created by 安志钢 on 16-10-13.
//  Copyright (c) 2016年 安志钢. All rights reserved.
//

#ifndef fft_fft_h
#define fft_fft_h

typedef struct complex {
    double re;
    double im;
} complex;

void fft(complex *io[8]);
void ifft(complex *io[8]);

#endif
