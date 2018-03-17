#ifndef PROCESS_H
#define PROCESS_H


class Process
{
    int pid;
    int burstTime;
    int priority;
    int arrvTime;
    int startTime;
    int finishTime;
    int remainingTime;

public:
    Process();
    int retPid();
    int retBurstTime();
    int retPriority();
    int retArrvTime();
    int retStartTime();
    int retFinishTime();
    int retWaitingTime();
    int retRemainingTime();
    void setStartTime(int time);
    void setFinishTime(int time);
    void setRemainingTime(int time);
    void setWaitingTime(int time);
    void enter();
    void display();
};

#endif // PROCESS_H
