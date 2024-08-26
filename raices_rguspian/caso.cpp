/**
 * @file
 * @brief Casos que evaluan diferentes metodos para encontrar una raiz
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#include <iostream>
#include <string>

#include "caso.h"
#include "encontrar.h"


using std::cout;
using std::endl;
using std::string;

/**
* @brief Caso 1° TVI e^(~x) - ln(x)
*/
void caso_1_tvi(){
    encontrar_tvi("e^(~x) -ln(x)", 0.5f, 2.0f , 0.001f);
}

/**
* @brief Caso 1° Bisección x^2 - cos(x)
*/
void caso_1_biseccion(){
    cout<<"Caso 1 Biseccion"<<endl;
    encontrar_biseccion("x^2 - cos(x)", -2.0f, 0.5f , 0.001f, 100);
}

/**
* @brief Caso 2° Bisección x^3 + 4*x^2 - 10
*/
void caso_2_biseccion(){
    cout<<"Caso 2 Biseccion"<<endl;
    encontrar_biseccion("x^3 + 4*x^2 - 10", 0.0f, 2.0f , 0.001f, 100);
}

/**
* @brief Caso 1° Regla Falsa x^2 - cos(x)
*/
void caso_1_regla_falsa(){
    cout<<"Caso 1 Regla Falsa"<<endl;
    encontrar_regla_falsa("x^2 - cos(x)",  -2.0f, 0.5f, 0.001f, 100);
    
}

/**
* @brief Caso 2° Regla Falsa x^3 + 4*x^2 - 10
*/
void caso_2_regla_falsa(){
    cout<<"Caso 2 Regla Falsa"<<endl;
    encontrar_regla_falsa("x^3 + 4*x^2 - 10",  0.0f, 2.0f, 0.001f, 100);
    
}

/**
* @brief Caso 1° Newton Rapsohon x^2 - cos(x)
*/
void caso_1_newton_rapshon(){
    cout<<"Caso 1 Newton Rapsohon"<<endl;
    encontrar_newton_rapshon("x^2 - cos(x)", "2*x + sin(x)", 0.5f, 0.001f, 100);
}

/**
* @brief Caso 2° Newton Rapsohon x^3 + 4*x^2 -10 
*/
void caso_2_newton_rapshon(){
    cout<<"Caso 2 Newton Rapsohon"<<endl;
    encontrar_newton_rapshon("x^3 + 4*x^2 - 10", "3*x^2 + 8*x", 1.0f, 0.001f, 100);
}

/**
* @brief Caso 1° Secante x^2 - cos(x)
*/
void caso_1_secante(){
    cout<<"Caso 1 Secante"<<endl;
    encontrar_secante("x^2 - cos(x)", -2.0f, 0.5f, 0.001f, 100);    
}

/**
* @brief Caso 2° Secante x^3 + 4*x^2 - 10
*/
void caso_2_secante(){
    cout<<"Caso 2 Secante"<<endl;
    encontrar_secante("x^3 + 4*x^2 - 10", 0.0f, 2.0f, 0.001f, 100);    
}