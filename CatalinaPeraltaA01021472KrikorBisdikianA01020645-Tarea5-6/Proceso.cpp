//
//  Proceso.cpp
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/22/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//
//
//  Proceso.cpp
//  Procesos
//
//  Created by Krikor Bisdikian on 10/15/15.
//  Copyright © 2015 Krikor Bisdikian. All rights reserved.
//
//Catalina Peralta A01021472
//Krikor Bisdikian A01020645

#include "Proceso.h"

#include <iostream>

Proceso::Proceso(std::string _id, double _arrival, double _duration){
    id = _id;
    arrival= _arrival;
    duration = _duration;
}

bool Proceso::operator<(const Proceso & p)const { return this->duration< p.duration;}
bool Proceso::operator>(const Proceso & p)const{ return this->duration>p.duration;}
bool Proceso::operator==(const Proceso & p)const{ return this->duration==p.duration;}
bool Proceso::operator>=(const Proceso & p)const{ return this->duration>=p.duration;}
bool Proceso::operator<=(const Proceso & p)const{ return this->duration<=p.duration;}

double Proceso::print() const{
    std::cout<<this->id<<": "<<this->wait<<std::endl;
    
    return this->wait;
    
}