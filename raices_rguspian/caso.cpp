/**
 * @file
 * @brief Funciones que llaman a diferentes metodos para encontrar una raiz
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@gmail.com>.
*/


#include <iostream>
#include <string>

#include "biseccion.h"
#include "caso.h"
#include "falsa.h"
#include "tvi.h"

using raices::biseccion;
using raices::falsa;
using raices::solucion;
using raices::tvi;




/*
* @brief Caso 1° TVI -7e^(-0.04t) +1.8 
*/
void caso_1_tvi(){
    string f_str ="x^3 - 2*x^2 + 1";
    double a = 0.5f;
    double b = 1.1f; 
    double h = 0.0001f; 

    // Instanciar el tvi.
    tvi t(f_str);

    // Encontrar la solución.
    solucion sol = t.encontrar(a,b,h);

    sol.imprimir();
    
}


/*
* @brief Caso 2° TVI e^(~x) - ln(x)
*/
void caso_2_tvi(){
    string f_str ="e^(~x) -ln(x)";
    double a = 0.5f;
    double b = 2.0f; 
    double h = 0.001f; 

    // Instanciar el tvi.
    tvi t(f_str);

    // Encontrar la solución.
    solucion sol = t.encontrar(a,b,h);

    sol.imprimir();
    
}

/*
* @brief Caso 1° Bisección -7e^(-0.04t) +1.8 
*/
void caso_1_biseccion(){
    string f_str ="x^3 - 2*x^2 + 1";
    double a = 0.5f;
    double b = 1.0f; 
    double tol = 1.0f; 
    int n = 100;

    // Instanciar biseccion.
    biseccion bis(f_str);

    // Encontrar la solución.
    solucion sol = bis.encontrar(a, b, tol, n);

    sol.imprimir();
    
}

/*
* @brief Caso 2° Bisección e^(~x) - ln(x)
*/
void caso_2_biseccion(){
    string f_str ="e^(~x) -ln(x)";
    double a = 1.0f;
    double b = 1.5f; 
    double tol = 1.0f; 
    int n = 100;
    
    // Instanciar biseccion.
    biseccion bis(f_str);
    
    // Encontrar la solución.
    solucion sol = bis.encontrar(a, b, tol, n);

    sol.imprimir();
    
}


/*
* @brief Caso 1° Regla Falsa -7e^(-0.04t) +1.8 
*/
void caso_1_regla_falsa(){
    string f_str ="x^3 - 2*x^2 + 1";
    double a = 0.5f;
    double b = 1.0f; 
    double tol = 1.0f; 
    int n = 100;

    // Instanciar biseccion.
    falsa regla_falsa(f_str);

    // Encontrar la solución.
    solucion sol = regla_falsa.encontrar(a, b, tol, n);

    sol.imprimir();
    
}

/*
* @brief Caso 2° Regla Falsa e^(~x) -ln(x)
*/
void caso_2_regla_falsa(){
    string f_str ="e^(~x) -ln(x)";
    double a = 0.5f;
    double b = 2.0f; 
    double tol = 1.0f; 
    int n = 100;
    
    // Instanciar biseccion.
    falsa regla_falsa(f_str);
    
    // Encontrar la solución.
    solucion sol = regla_falsa.encontrar(a, b, tol, n);

    sol.imprimir();
    
}