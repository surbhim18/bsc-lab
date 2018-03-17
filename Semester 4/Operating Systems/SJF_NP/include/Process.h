#ifndef PROCESS_H
#define PROCESS_H


class Process
{
    int pid;
    int burstTime;
    int arrvTime;
    int startTime;
    int finishTime;

    public:
    Process();
    int retPid();
    int retBurstTime();
    int retArrvTime();
    int retStartTime();
    int retFinishTime();
    void setStartTime(int time);
    void setFinishTime(int time);
    void enter();
    void display();
};

#endif // PROCESS_H
