// Copyright 2022 ETH Zurich and University of Bologna.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "host.c"

// Assumes bypass FLL mode and SIM_WITHOUT_HBM
// #define PERIPH_FREQ 1000000000
#define PERIPH_FREQ 100000000  // 100 MHz

int main() {
    // This configuration must set to be equal of the uartdpi simulation model
    init_uart(PERIPH_FREQ, 115200);
    asm volatile("fence" : : : "memory");
    print_uart("Hello world!\r\n");
    return 0;
}
