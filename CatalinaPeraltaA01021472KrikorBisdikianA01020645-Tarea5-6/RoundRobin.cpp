//
//  RoundRobin.cpp
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/16/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//

#include <stdio.h>
#include "RoundRobin.h"

void RoundRobin::roundRobin(vector<Process*> list)
{
    ::deque<Process*> helper;
    ::deque<Process*> doneQueue;
    Process * running_process = NULL;
    
    bool running = false;
    bool done = false;
    float time = (float) 0.0;
    float timeQ = (float) 0.0;
    float timeRunning = (float) 0.0;
    int i = 1;
    
    while (!queue.empty() || !helper.empty())
    {
        
        if (!queue.empty())
        {
            if (compFloat(queue.front()->getEntryTime(),time))
            {
                Process * p = queue.front();
                helper.push_back(p);
                queue.pop_front();
            }
        }
        
        if (!running_process)
        {
            if (!helper.empty())
            {
                running_process = helper.front();
                helper.pop_front();
                cout<<" || "<<time<<" "<<running_process->getName()<<" ";
            }
        }
        else if (compFloat(running_process->getRemainingTime(), 0.0))
        {
            if (!helper.empty())
            {
                cout<<time<<" ";
                doneQueue.push_back(running_process);
                running_process = helper.front();
                helper.pop_front();
                cout<<" || "<<time<<" "<<running_process->getName()<<" ";
                timeQ = 0.0;
            }
            else
            {
                cout<<time<<" ";
                doneQueue.push_back(running_process);
                timeQ = 0.0;
            }
        }
        else if (compFloat((8.0-fmod(timeQ, quantum)), 0.0))
        {
            cout<<time<<" ";
            helper.push_back(running_process);
            running_process = helper.front();
            helper.pop_front();
            cout<<" || "<<time<<" "<<running_process->getName()<<" ";
            timeQ = 0.0;
        }
        
        time += 0.1;
        timeQ += 0.1;
        for (auto i : helper)
        {
            i->setWaitTime((float)(i->getWaitTime()+0.1));
            
        }
        
        running_process->setRemainingTime((float)running_process->getRemainingTime()-(float)0.1);
        
    }
    running_process->setWaitTime(running_process->getWaitTime()+running_process->getRemainingTime());
    doneQueue.push_back(running_process);
    cout<<running_process->getRemainingTime()+time<<" ||"<<endl;
    
    float totWait = 0.0;
    for (auto i : doneQueue)
    {
        cout<<i->getName()<<" wait "<<i->getWaitTime()<<endl;
        totWait += i->getWaitTime();
    }
    
    totWait = (float)(totWait/(float)doneQueue.size());
    
    cout<<"Tiempo promedio de espera: "<<totWait<<endl;
}

void RoundRobin::fillQueue(vector<Process*> list)
{
    quantum = list[0]->getQuantum();
    
    for (int i = 1; i<list.size(); i++)
    {
        Process * p = list[i];
        queue.push_back(p);
    }
}