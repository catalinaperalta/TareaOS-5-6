//
//  Process.cpp
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/13/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//
//Catalina Peralta A01021472
//Krikor Bisdikian A01020645

#include <stdio.h>

#include "Process.h"

//Función para leer el archivo .txt, crear los procesos que lee del archivo y agregar dichos procesos a una lista.
void Process::getProcess()
{
    string line;
    fstream file;
    file.open("/Users/iCaty/Documents/TEC/QuintoSemestre/SistemasOperativos/procesos.txt");
    getline(file, line);
    
    Process * temp = new Process();
    temp->process = "Quantum";
    temp->quantum = stof(line, 0);
    temp->entryTime = -1;
    procesos.push_back(temp);
    
    while (!file.eof())
    {
        getline(file, line);
        this->setValues(line);
    }
    file.close();
    
}

Process * Process::setValues(string line)
{
    if (line.length() > 0)
    {
        vector<string> list;
        int begin = 0;
        for (int i = 0; i<line.length(); i++)
        {
            if (line[i] == ' ' || i == line.length()-1)
            {
                if (i == line.length()-1)
                {
                    list.push_back(line.substr(begin, i-begin+1));
                    break;
                }
               list.push_back(line.substr(begin, i-begin));
                begin = i+1;
            }
        }
        Process * p = new Process();
        
        p->process = list[0];
        p->entryTime = stof(list[1], 0);
        p->duration = p->remainingTime = stof(list[2], 0);
        
        procesos.push_back(p);
    }
    return this;
}

void Process::orderProcess()
{
    sort(procesos.begin(), procesos.end(), wayToSort);
}

void Process::printProcessList()
{
    for (auto i : procesos)
    {
        cout<<i->process<<" "<<i->entryTime<<" "<<i->duration;
        cout<<endl;
    }
}

float Process::getQuantum()
{
    return quantum;
}

float Process::getEntryTime()
{
    return entryTime;
}

void Process::setWaitTime(float wait)
{
    waitTime = wait;
}

float Process::getWaitTime()
{
    return waitTime;
}

void Process::setRemainingTime(float remain)
{
    remainingTime = remain;
}

float Process::getRemainingTime()
{
    return remainingTime;
}

string Process::getName()
{
    return process;
}

void Process::setWaitTime(int time)
{
    waitTime = time;
}

vector<Process*> Process::getList()
{
    return procesos;
}
