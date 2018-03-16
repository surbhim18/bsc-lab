#ifndef FRAME_H
#define FRAME_H
#include "Packet.h"

typedef int seq_no;
enum frame_kind {data, ack, nak};

class Frame
{
    public:
        Packet info;
        seq_no seqNo;
        seq_no ackNo;
        frame_kind kind;
};

#endif // FRAME_H
