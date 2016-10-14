//
//  main.c
//  fft
//
//  Created by 安志钢 on 16-10-13.
//  Copyright (c) 2016年 安志钢. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "fft.h"

int main(int argc, const char * argv[])
{
    // insert code here...
    
    complex *io[8];
    int i;
    
    for (i = 0; i < 8; ++i) {
        io[i] = malloc(sizeof(complex));
    }
    
    io[0]->re = 1.0;
    io[0]->im = 9.0;
    io[1]->re = 2.0;
    io[1]->im = 0.0;
    io[2]->re = 3.0;
    io[2]->im = 1.0;
    io[3]->re = 4.0;
    io[3]->im = 2.0;
    io[4]->re = 5.0;
    io[4]->im = 3.0;
    io[5]->re = 6.0;
    io[5]->im = 4.0;
    io[6]->re = 7.0;
    io[6]->im = 5.0;
    io[7]->re = 8.0;
    io[7]->im = 6.0;
    
    printf("Original:\n");
    for (i = 0; i < 8; ++i) {
        printf("#%i: %f", i + 1, io[i]->re);
        if (io[i]->im != 0) {
            printf("%+f", io[i]->im);
        }
        printf("\n");
    }
    printf("\n");
    
    fft(io);
    
    printf("FFT:\n");
    for (i = 0; i < 8; ++i) {
        printf("#%i: %f", i + 1, io[i]->re);
        if (io[i]->im != 0) {
            printf("%+f", io[i]->im);
        }
        printf("\n");
    }
    printf("\n");
    
    ifft(io);
    
    printf("IFFT:\n");
    for (i = 0; i < 8; ++i) {
        printf("#%i: %f", i + 1, io[i]->re);
        if (io[i]->im != 0) {
            printf("%+f", io[i]->im);
        }
        printf("\n");
    }
    printf("\n");
    
    for (i = 0; i < 8; ++i) {
        free(io[i]);
    }
    
    return 0;
}

