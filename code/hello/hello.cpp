#include <systemc.h>

// SC_MODULE(module name): build module
SC_MODULE(top){
    void helloworld();
    // SC_CTOR(module name): SystemC constructor that creates internal data structures
    SC_CTOR(top)
    {
        // SC_THREAD likes "initial" block in verilog, run once, not synthesiazble
        // SC_METHOD likes "always" block in verilog, run continuously, synthesiazble
        // SC_cTHREAD means clocked thread, run continuously, synthesiazble
        // SC_THREAD(function name): SystemC thread that can be used to automate simulation functions and suspend simulation.
        SC_THREAD(helloworld);
    };
};

void top::helloworld()
{
    cout << "Hello World" << endl;
};

int sc_main(int argc, char *argv[])
{
    top mod("HELLO");
    mod.helloworld();
    return (0);
}