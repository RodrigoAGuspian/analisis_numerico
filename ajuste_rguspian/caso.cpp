/**
* @file 
* @brief Declaración de los casos
* @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
* @copyright MIT License
 */

#include <iostream>

#include "caso.h"
#include "regresion.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

using regresion::lineal_simple;

void caso_1_regresion(){
    cout<<"Caso 1 regersión."<<endl;
    vector<double> x {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f};
    vector<double> y {0.5f, 2.5f, 2.0f, 4.0f, 3.5f, 6.0f, 5.5f};

    lineal_simple l(x, y);

    double x_est = 3.5f;
    double y_est= l.estimar(x_est);

    cout<< "El valor de y para x = "<< x_est<< " es: "<<y_est<<endl;

}