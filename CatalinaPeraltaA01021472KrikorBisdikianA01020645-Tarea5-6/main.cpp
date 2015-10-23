//
//  main.cpp
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/13/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//
//Catalina Peralta A01021472
//Krikor Bisdikian A01020645

#include <iostream>
#include "RoundRobin.h"
#include "SJF.h"

int main(int argc, const char * argv[])
{
    string op = "";
    
    while (op!="0")
    {
        cout<<"Bienvendo! Eliga una opcion: 1. Round Robin 2. SJF 0.Salir"<<endl;
        cin>>op;
        
        if (op == "1")
        {
            Process * p = new Process();
            RoundRobin * r = new RoundRobin();
            
            p->getProcess();
            p->orderProcess();
            
            
            r->fillQueue(p->getList());
            r->roundRobin(p->getList());
        }
        else if (op == "2")
        {
            SJF sjf;
            sjf.excecute();
        }
        else if (op == "0")
        {
            cout<<"Adios!"<<endl;
            return 0;
        }
        else
        {
            cout<<"Esa no es una opcion valida! Intente de nuevo."<<endl;
        }
    }
    
    return 0;
}
