#include "fir.h"

const sc_uint<8> coef[5] = {18, 77, 107, 77, 18};

// FIR Main thread
void fir::fir_main(void)
{
    sc_int<16> taps[5];
    // Reset code
    // Reset internal variables
    // Reset outputs
    // Initialize handshake
    inp_rdy.write(0);
    outp_vld.write(0);
    outp.write(0);
    wait();

    while(true)
    {
        // Read inputs
        sc_int<16> in_val;
        inp_rdy.write(1);
        do {
            wait();
        } while(!inp_vld.read());
        in_val = inp.read();
        inp_rdy.write(0);

        // Algorithm code
        for (int i = 4; i > 0; i--)
        {
            taps[i] = taps[i - 1];
        }
        taps[0] = inp.read();

        sc_int<16> out_val;
        for (int i = 0; i < 5; i++)
        {
            out_val += coef[i] * taps[i];
        }

        // Write outputs
        outp_vld.write(1);
        outp.write(out_val);
        do {
            wait();
        } while(!outp_rdy.read());
        outp_vld.write(0);
    }
}
