//
//  SJF.h
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/22/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//
//
//  SJF.h
//  Procesos
//
//  Created by Krikor Bisdikian on 10/19/15.
//  Copyright © 2015 Krikor Bisdikian. All rights reserved.
//
//Catalina Peralta A01021472
//Krikor Bisdikian A01020645

#ifndef SJF_h
#define SJF_h

#include <queue>
#include "Proceso.h"
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

class SJF {
    
    std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
    
    std::vector<std::string> split(const std::string &s, char delim);
    
    void getProcess(std::queue<Proceso> & process_start,double & quantum);
    void nextArrives(std::list<Proceso> & process_queue, Proceso & next);
    void incrementWait(std::list<Proceso> & process_queue);
    bool compDouble(double a, double b);
    
    //Estructura de lista para la cola ordenada (para poder iterar sobre ella)
    std::list<Proceso> process_queue;
    //Estructura de cola para los procesos iniciales
    std::queue<Proceso> process_start;
    //Guardamos los procesos terminados ya que el tiempo de espera se almacena en ellos
    std::vector<Proceso> terminados;
    double quantum;
    double time=0;
    Proceso excecuting;
public:
    
    void excecute();
    
    
};


#endif /* SJF_h */