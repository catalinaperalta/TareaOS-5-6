//
//  main.cpp
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/13/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//

#include <iostream>
#include "RoundRobin.h"
#include "SJF.h"

int main(int argc, const char * argv[])
{
    Process * p = new Process();
    p->getProcess();
    p->orderProcess();
//    p->printProcessList();
    
    RoundRobin * r = new RoundRobin();
    
    r->fillQueue(p->getList());
    r->roundRobin(p->getList());
    
    SJF sjf;
    sjf.excecute();
    
    return 0;
}
