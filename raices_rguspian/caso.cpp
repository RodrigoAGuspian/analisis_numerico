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
#include "comparar.h"

#include <string>
#include <vector>


using std::cout;
using std::endl;
using std::string;
using std::vector;
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
    encontrar_newton_raphson("x^2 - cos(x)", "2*x + sin(x)", 0.5f, 0.001f, 100);
}

/**
* @brief Caso 2° Newton Rapsohon x^3 + 4*x^2 -10 
*/
void caso_2_newton_rapshon(){
    cout<<"Caso 2 Newton Rapsohon"<<endl;
    encontrar_newton_raphson("x^3 + 4*x^2 - 10", "3*x^2 + 8*x", 1.0f, 0.001f, 100);
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


/**
* @brief Caso especial newton raphson x^3 + 4*x^2 - 10
*/

void caso_especial_newton_rapshon(){
    cout<<"Caso especial Newton Rapsohon"<<endl;
    encontrar_newton_raphson("x^3 + 4*x^2 - 10", "3*x^2 + 8*x", 1.5f, 0.001f, 100);
}

/**
* @brief Caso especial 2 newton raphson x^4 -4x^2 +4
*/

void caso_especial_2_newton_rapshon(){
    cout<<"Caso especial Newton Rapsohon"<<endl;
    encontrar_newton_raphson("x^4 -4*x^2 +4", "3*x^3 -8*x^", 1.5f, 0.001f, 100);
}


/**
* @brief Caso especial newton raphson x^3 + 4*x^2 - 10
*/
void caso_especial_newton_rapshon_g(){
    cout<<"Caso especial Newton Rapsohon Generalizada"<<endl;
    encontrar_newton_raphson_g("x^3 + 4*x^2 - 10", "3*x^2 + 8*x", "6*x + 8",1.5f, 0.001f, 100);
}


/**
* @brief Caso especial 2 newton raphson x^4 -4x^2 +4
*/
void caso_especial_2_newton_rapshon_g(){
    cout<<"Caso especial Newton Rapsohon Generalizada"<<endl;
    encontrar_newton_raphson_g("x^4 -4x^2 +4", "4*x^3 -8*x ", "12*x^2- 8",1.5f, 0.001f, 100);
}

/** 
 * @brief Comparacion del caso especial con varios puntos iniciales
 * 
*/
void caso_especial_comparacion(){
    vector<double> valores_iniciales = {-1.4f, -1.0f, 1.0f, 1.5f};
    comparar_newton_raphson("x^4 -4x^2 +4", "4*x^3 -8*x ", "12*x^2- 8", valores_iniciales, 0.001f, 100);

}