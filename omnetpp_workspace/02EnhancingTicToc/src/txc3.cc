#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Txc3 : public cSimpleModule{
    protected :
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Txc3);

void Txc3::initialize(){
    if(strcmp("tic",getName()) == 0){
        EV << "init ";
        cMessage *msg = new cMessage("tictocmsg");
        send(msg, "out");
    }

}

void Txc3::handleMessage(cMessage *msg){
    EV << "request";
    send(msg, "out");

}
