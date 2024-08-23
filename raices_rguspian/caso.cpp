/**
 * @file
 * @brief Funciones que llaman a diferentes metodos para encontrar una raiz
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/


#include <iostream>
#include <string>

#include "biseccion.h"
#include "caso.h"
#include "falsa.h"
#include "newtonRapshon.h"
#include "secante.h"
#include "tvi.h"

using raices::biseccion;
using raices::falsa;
using raices::newton_rapshon;
using raices::secante;
using raices::solucion;
using raices::tvi;


/*
* @brief Caso 1° TVI e^(~x) - ln(x)
*/
void caso_1_tvi(){
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
* @brief Caso 1° Bisección e^(~x) - ln(x)
*/
void caso_1_biseccion(){
    string f_str ="e^(~x) -ln(x)";
    double a = 1.0f;
    double b = 1.5f; 
    double tol = 0.1f; 
    int n = 100;
    
    // Instanciar biseccion.
    biseccion bis(f_str);
    
    // Encontrar la solución.
    solucion sol = bis.encontrar(a, b, tol, n);

    sol.imprimir();
    
}

/*
* @brief Caso 1° Regla Falsa e^(~x) -ln(x)
*/
void caso_1_regla_falsa(){
    string f_str ="e^(~x) -ln(x)";
    double a = 1.0f;
    double b = 1.5f; 
    double tol = 0.1f; 
    int n = 100;
    
    // Instanciar regla falsa.
    falsa regla_falsa(f_str);
    
    // Encontrar la solución.
    solucion sol = regla_falsa.encontrar(a, b, tol, n);

    sol.imprimir();
    
}

/*
* @brief Caso 1° Newton Rapsohon e^(~x) -ln(x)
*/
void caso_1_newton_rapshon(){
    string f_str ="e^(~x) -ln(x)";
    string df_str ="~e^(~x) -(1/x)";
    double p0 = 1.0f;
    double tol = 0.1f; 
    int n = 100;
    
    // Instanciar newton rapshon.
    newton_rapshon nr(f_str, df_str);
    
    // Encontrar la solución.
    solucion sol = nr.encontrar(p0, tol, n);

    sol.imprimir();
    
}


/*
* @brief Caso 2° Newton Rapsohon x³ + 4*x² -10
*/
void caso_2_newton_rapshon(){
    string f_str ="x^3 + 4*x^2  -10";
    string df_str ="3*x^2 + 8*x";
    double p0 = -2.3f;
    double tol = 0.1f; 
    int n = 100;
    
    // Instanciar newton rapshon.
    newton_rapshon nr(f_str, df_str);
    
    // Encontrar la solución.
    solucion sol = nr.encontrar(p0, tol, n);

    sol.imprimir();
    
}


/*
* @brief Caso 3° Secante e^(-x^2) -x;
*/
void caso_3_secante(){
    string f_str ="e^-(x^2) -x";
    double x0 = -0.5f;
    double x1 = 0.5f;
    double tol = 0.1f; 
    int n = 100;
    
    // Instanciar newton rapshon.
    secante secan(f_str);
    
    // Encontrar la solución.
    solucion sol = secan.encontrar(x0, x1, tol, n);

    sol.imprimir();
    
}
