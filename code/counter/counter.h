#include "systemc.h"

SC_MODULE(counter)
{
    sc_in<bool> clk;
    sc_in<bool> clr;
    sc_out<sc_uint<4> > count;

    int internal_count;

    void up_count();
    void data();

    SC_CTOR(counter)
    {
        internal_count = 0;

        SC_METHOD(up_count);
            sensitive << clk.pos();
            sensitive << clr.pos();

        SC_METHOD(data);
            sensitive << clk.pos();
            sensitive << clr;
    }
};