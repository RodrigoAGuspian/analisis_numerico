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
using std::cerr;
using std::vector;

using regresion::lineal_simple;
using regresion::modelo_lineal;
using regresion::log;
using regresion::ln;

void caso_1_regresion(){
    cout<<"Caso 1 regersión."<<endl;
    vector<double> x {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f};
    vector<double> y {0.5f, 2.5f, 2.0f, 4.0f, 3.5f, 6.0f, 5.5f};

    lineal_simple l(x, y);

    double x_est = 3.5f;
    double y_est= l.estimar(x_est);

    cout<< "El valor de y para x = "<< x_est<< " es: "<<y_est<<endl;



    modelo_lineal m = l.obtener_modelo();

    cout<<m;


    
}

void caso_1_funcion_potencia(){
    cout<<" Caso 1 linealización de función potencia"<<endl;

    vector<double> x {10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f, 70.0f, 80.0f};
    vector<double> xlog = log(x);

    for (auto x1: xlog){
        cout<<x1<<endl;
    }
}