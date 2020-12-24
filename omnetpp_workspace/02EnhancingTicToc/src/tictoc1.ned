package _02enhancingtictoc;

@license(LGPL);
simple Txc1
{
    gates:
        input in;
        output out;
}

network Tictoc1
{
    @display("bgb=335,202");
    submodules:
        tic: Txc1;
        toc: Txc1 {
            @display("is=vl;p=265,150");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
