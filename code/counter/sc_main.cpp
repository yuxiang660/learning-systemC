#include <systemc.h>

#include "counter_test.h"

int sc_main(int argc, char *argv[])
{
    counter_test test("counter_test");
    sc_start(1000, SC_NS);
    return (0);
}
