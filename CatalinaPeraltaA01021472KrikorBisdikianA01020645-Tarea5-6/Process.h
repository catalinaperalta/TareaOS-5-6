//
//  Process.h
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/13/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//

#ifndef Process_h
#define Process_h

#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Process
{
    vector<Process*> procesos;
    string process;
    float quantum;
    float entryTime;
    float waitTime;
    float remainingTime;
    float nextEntryTime;
    float duration;
    
public:
    Process() {waitTime = 0; remainingTime = 0; nextEntryTime = 0;}
    void getProcess();
    Process * setValues(string line);
    void orderProcess();
    void printProcessList();
    
    float getQuantum();
    float getEntryTime();
    void setNextEntryTime(float nextTime);
    float getNextEntryTime();
    void setWaitTime(float wait);
    float getWaitTime();
    void setRemainingTime(float remain);
    float getRemainingTime();
    string getName() { return process;}
    void setWaitTime(int time) { waitTime = time;}
    vector<Process*> getList() {return procesos;}
    bool operator() (Process * i,Process * j) { return (i->entryTime<j->entryTime);}
    static bool wayToSort(Process * i,Process * j) { return (i->entryTime < j->entryTime);}
};

#endif /* Process_h */
