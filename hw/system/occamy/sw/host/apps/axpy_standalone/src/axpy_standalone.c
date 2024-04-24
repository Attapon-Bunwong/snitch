#include "host.c"
#include "data.h"

// Define your kernel
void axpy(uint32_t l, double a, double *x, double *y, double *z) {
    for (uint32_t i = 0; i < l ; i++) {
        z[i] = a * x[i] + y[i];
    }
}

int main() {
    // Wake up the Snitch cores even if we don't use them
    reset_and_ungate_quad(0);
    deisolate_quad(0, ISO_MASK_ALL);

    // Read the mcycle CSR (this is our way to mark/delimit a specific code region for benchmarking)
    uint64_t start_cycle = mcycle();

    // Call your kernel
    axpy(L, a, x, y, z);

    // Read the mcycle CSR
    uint64_t end_cycle = mcycle();
}
