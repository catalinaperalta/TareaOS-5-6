//
//  RoundRobin.cpp
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/16/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//
//Catalina Peralta A01021472
//Krikor Bisdikian A01020645

#include <stdio.h>
#include "RoundRobin.h"

void RoundRobin::roundRobin(vector<Process*> list)
{
    //Variables para apoyar el proceso del Round Robin.
    ::deque<Process*> helper;
    ::deque<Process*> doneQueue;
    Process * running_process = NULL;
    float time = (float) 0.0;
    float timeQ = (float) 0.0;
    
    cout<<"Grafica de Gantt: "<<endl;
    
    //While para simular el funcionamiento de Round Robin. Con cada iteracion incrementa una variable que es
    //como una variable de tiempo. Es la variable "time".
    while (!queue.empty() || !helper.empty())
    {
        
        //Se revisa que el queue no este vacio. Mientras no esta vacio entonces revisa si hay un proceso que
        //va a empezar en el tiempo actual del reloj.
        if (!queue.empty())
        {
            if (compFloat(queue.front()->getEntryTime(),time))
            {
                Process * p = queue.front();
                helper.push_back(p);
                queue.pop_front();
            }
        }
        
        //Revisa si hay un proceso ejecutandose. Si no, busca en la fila de espera de procesos.
        if (!running_process)
        {
            if (!helper.empty())
            {
                running_process = helper.front();
                helper.pop_front();
                cout<<" || "<<time<<" "<<running_process->getName()<<" ";
            }
        }
        //Revisa si se ha acabado de ejecutar el proceso actual.
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
        //Revisa si ya se acabo el tiempo designado de procesamiento del proceso actual.
        else if (compFloat((8.0-fmod(timeQ, quantum)), 0.0))
        {
            cout<<time<<" ";
            helper.push_back(running_process);
            running_process = helper.front();
            helper.pop_front();
            cout<<" || "<<time<<" "<<running_process->getName()<<" ";
            timeQ = 0.0;
        }
        
        //Incrementa el tiempo general del sistema.
        time += 0.1;
        //Incrementa el tiempo del quantum actual.
        timeQ += 0.1;
        
        //Incrementa el tiempo de espera de los procesos en la fila.
        for (auto i : helper)
        {
            i->setWaitTime((float)(i->getWaitTime()+0.1));
            
        }
        
        //Decrementa el tiempo que le queda de ejecución del proceso actual.
        running_process->setRemainingTime((float)running_process->getRemainingTime()-(float)0.1);
        
    }
    
    //Agrega la ultima iteracion del ultimo proceso de la fila.
    running_process->setWaitTime(running_process->getWaitTime()+running_process->getRemainingTime());
    doneQueue.push_back(running_process);
    cout<<running_process->getRemainingTime()+time<<" ||"<<endl;
    
    //Imprime el queue de los procesos terminados.
    float totWait = 0.0;
    for (auto i : doneQueue)
    {
        cout<<i->getName()<<" espero "<<i->getWaitTime()<<endl;
        totWait += i->getWaitTime();
    }
    
    //Calculo del tiempo promedio de espera.
    totWait = (float)(totWait/(float)doneQueue.size());
    
    cout<<"Tiempo promedio de espera: "<<totWait<<endl;
}

//Llena el queue con los procesos que se leyeron del .txt
void RoundRobin::fillQueue(vector<Process*> list)
{
    quantum = list[0]->getQuantum();
    
    for (int i = 1; i<list.size(); i++)
    {
        Process * p = list[i];
        queue.push_back(p);
    }
}

//Función de comparación de floats para poder comparar los tiempos de tipo float que se utilizan en el programa.
bool RoundRobin::compFloat(float a, float b)
{
    if (fabs(a-b) < 1e-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}