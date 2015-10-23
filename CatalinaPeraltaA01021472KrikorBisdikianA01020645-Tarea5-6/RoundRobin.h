//
//  RoundRobin.h
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/13/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//
//Catalina Peralta A01021472
//Krikor Bisdikian A01020645

#ifndef RoundRobin_h
#define RoundRobin_h

#include <queue>
#include <math.h>
#include "Process.h"

using namespace std;

class RoundRobin
{
    float quantum;
    deque<Process*> queue;
public:
    void roundRobin(vector<Process*> list);
    void fillQueue(vector<Process*> list);
    bool compFloat(float a, float b);
};

#endif /* RoundRobin_h */
