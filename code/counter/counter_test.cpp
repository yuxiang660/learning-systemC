#include "counter_test.h"

void counter_test::stimulus()
{
    // clock cycle counter
    int i;

    // clear counter
    clr.write(1);

    for (i = 0; i <= 5; i++)
    {
        clk.write(1);
        wait(10, SC_NS);
        clk.write(0);
        wait(10, SC_NS);
    }

    // start counting
    clr.write(0);

    for (i = 0; i <= 18; i++)
    {
        clk.write(1);
        wait(10, SC_NS);
        clk.write(0);
        wait(10, SC_NS);
    }

    // clear counter
    clr.write(1);

    for (i = 0; i <= 3; i++)
    {
        clk.write(1);
        wait(10, SC_NS);
        clk.write(0);
        wait(10, SC_NS);
    }

    // start counting - 2nd time
    clr.write(0);

    for (i = 0; i <= 18; i++)
    {
        clk.write(1);
        wait(10, SC_NS);
        clk.write(0);
        wait(10, SC_NS);
    }

    sc_stop();
}
