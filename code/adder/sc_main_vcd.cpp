//------------------------------------------------------------------
// Simple Testbench for 4-bits adder file
//
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------
#include <systemc.h>

#include "adder.h"
#include "stim.h"
#include "check.h"

int sc_main(int argc, char* argv[])
{
    
	sc_signal<sc_uint<4> > ain, bin, sum;
    sc_signal<bool> ci,co;

    sc_clock clk("clk",10,SC_NS,0.5);	// Create a clock signal

    sc_trace_file *fp;					// Create VCD file
    fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
    fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns

    adder DUT("adder");					// Instantiate Device Under Test
    DUT.ain(ain);						// Connect ports
    DUT.bin(bin);
    DUT.ci(ci);
    DUT.sum(sum);
    DUT.co(co);

    stim STIM("stimulus");				// Instantiate stimulus generator
    STIM.clk(clk);
    STIM.ain(ain);
    STIM.bin(bin);
    STIM.ci(ci);

    check CHECK("checker");				// Instantiate checker
    CHECK.clk(clk);
    CHECK.ain(ain);
    CHECK.bin(bin);
    CHECK.ci(ci);
    CHECK.sum(sum);
    CHECK.co(co);

    sc_trace(fp,clk,"clk");				// Add signals to trace file

    sc_trace(fp,ain,"ain");
    sc_trace(fp,bin,"bin");
    sc_trace(fp,ci,"ci");
    sc_trace(fp,sum,"sum");
    sc_trace(fp,co,"co");

    sc_trace(fp,DUT.co0,"DUT.co0");	// Add signals to trace file
    sc_trace(fp,DUT.co1,"DUT.co1");	// Add signals to trace file
    sc_trace(fp,DUT.co2,"DUT.co2");	// Add signals to trace file
    sc_trace(fp,DUT.sum_s,"DUT.sum_s");	// Add signals to trace file

    sc_trace(fp,DUT.ain,"DUT.ain");	// Add signals to trace file
    sc_trace(fp,DUT.bin,"DUT.bin");	// Add signals to trace file

    sc_start(100, SC_NS);			   	// Run simulation

    sc_close_vcd_trace_file(fp);		// close(fp)

    return 0;							// Return OK, no errors.
}