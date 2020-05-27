#include "counter.h"

SC_MODULE(counter_test)
{
    sc_signal<bool> clr;
    sc_signal<bool> clk;
    sc_signal<sc_uint<4> > count;

    // pointing to tracefile in constructor
    sc_trace_file* pTraceFile;

    counter uut;

    // calling stimulus
    void stimulus();

    SC_CTOR(counter_test) :
        clr("clr"),
        clk("clk"),
        count("count"),
        uut("uut")
    {
        // defining and identifying signals
        uut.clr(clr);
        uut.clk(clk);
        uut.count(count);

        // trace file
        pTraceFile = sc_create_vcd_trace_file("counter_sim");
        pTraceFile->set_time_unit(1, SC_NS);		// set tracing resolution to ns

        // tracing signals to waveforms
        sc_trace(pTraceFile, clr, "clr");
        sc_trace(pTraceFile, clk, "clk");
        sc_trace(pTraceFile, count, "count");

        SC_THREAD(stimulus);
    }

    // ending simulation, closing trace file
    ~counter_test()
    {
        sc_close_vcd_trace_file(pTraceFile);
    }
};
