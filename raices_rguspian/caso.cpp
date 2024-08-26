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

using std::string;


/**
* @brief Caso 1° TVI e^(~x) - ln(x)
*/
void caso_1_tvi(){
    encontrar_tvi("e^(~x) -ln(x)", 0.5f, 2.0f , 0.001f);
}

/**
* @brief Caso 1° Bisección e^(~x) - ln(x)
*/
void caso_1_biseccion(){
    encontrar_biseccion("e^(~x) -ln(x)", 1.0f, 1.5f , 0.1f, 100);
}

/**
* @brief Caso 1° Regla Falsa e^(~x) -ln(x)
*/
void caso_1_regla_falsa(){
    encontrar_regla_falsa("e^(~x) -ln(x)",  1.0f, 1.5f, 0.1f, 100);
    
}

/**
* @brief Caso 1° Newton Rapsohon e^(~x) -ln(x)
*/
void caso_1_newton_rapshon(){
    encontrar_newton_rapshon("e^(~x) -ln(x)", "~e^(~x) -(1/x)", 1.0f, 0.1f, 100);
}


/**
* @brief Caso 2° Newton Rapsohon x³ + 4*x² -10
*/
void caso_2_newton_rapshon(){
    encontrar_newton_rapshon("x^3 + 4*x^2 - 10", "3*x^2 + 8*x", -2.3f, 0.1f, 100);
}

/**
* @brief Caso 3° Secante e^(-x^2) -x;
*/
void caso_3_secante(){
    encontrar_secante("e^(~x^2) -x", -0.5f, 0.5f, 1.0f, 100);
    
}
