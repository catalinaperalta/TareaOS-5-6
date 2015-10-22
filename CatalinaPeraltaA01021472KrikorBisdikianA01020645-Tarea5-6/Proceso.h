//
//  Proceso.h
//  CatalinaPeraltaA01021472KrikorBisdikianA01020645-Tarea5-6
//
//  Created by iCaty on 10/22/15.
//  Copyright © 2015 Catalina Peralta. All rights reserved.
//
//
//  Proceso.h
//  Procesos
//
//  Created by Krikor Bisdikian on 10/15/15.
//  Copyright © 2015 Krikor Bisdikian. All rights reserved.
//

#ifndef Proceso_h
#define Proceso_h
#include <string>


//Clase proceso con su constructor y overload de los operadores logicos
class Proceso {
public:
    std::string id;
    double arrival;
    double duration;
    double wait=0;
    
    Proceso(){};
    Proceso(std::string _id, double _arrival, double _duration);
    
    
    bool operator<(const Proceso & p) const;
    bool operator>(const Proceso & p) const;
    bool operator==(const Proceso & p)const;
    bool operator>=(const Proceso & p)const;
    bool operator<=(const Proceso & p)const;
    
    //Función que imprime el nombre y le tiempo de espera y regresa este ultimo
    double print() const;
    
};

#endif /* Process_h */