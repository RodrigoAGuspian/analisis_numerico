
/**
 * @file
 * @brief Implementación de casos de prueba
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
 */

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

#include "caso.h"
#include "simpson.h"
#include "simpson13.h"
#include "simpson38.h"
#include "trapecio.h"
#include "romberg.h"

using integracion::simpson;
using integracion::simpson13;
using integracion::simpson38;
using integracion::trapecio;

using std::cout;
using std::endl;

/**
 * @brief Método para el uso de caso 1° e^(x^2) 
 */

void caso_1_trapecio(){

    // Declaración de variables para el caso 1
    string f_str = "e^(x^2)";
    double a = 0.0f;
    double b = 1.0f;
    int n = 100;

    // Crea la instancia del trapecio
    trapecio i(f_str,a,b,n);

    // Imprimir tabla de datos
    double valor = i.calcular();

    // Calcula el valor de la integral
    i.imprimir_tabla(cout);

    // Imprimir el resltado por pantalla
    cout << "El valor de la integral de " << f_str<< " en el intervalo []"<<
    a << ", "<< b<< "] es: "<<valor<< endl;   
}


void caso_1_simpson13(){
// Declaración de variables para el caso 1
    string f_str = "e^(x^2)";
    double a = 0.0f;
    double b = 1.0f;
    int n = 10;

    // Crea la instancia del simpson
    simpson13 i(f_str,a,b,n);

    // Imprimir tabla de datos
    double valor = i.calcular();

    // Calcula el valor de la integral
    i.imprimir_tabla(cout);

    // Imprimir el resltado por pantalla
    cout << "El valor de la integral de " << f_str<< " en el intervalo ["<<
    a << ", "<< b<< "] es: "<<valor<< endl;   
}


void caso_1_simpson38(){
// Declaración de variables para el caso 1
    string f_str = "e^(x^2)";
    double a = 0.0f;
    double b = 1.0f;
    int n = 9;

    // Crea la instancia del simpson
    simpson38 i(f_str,a,b,n);

    // Imprimir tabla de datos
    double valor = i.calcular();

    // Calcula el valor de la integral
    i.imprimir_tabla(cout);

    // Imprimir el resltado por pantalla
    cout << "El valor de la integral de " << f_str<< " en el intervalo ["<<
    a << ", "<< b<< "] es: "<<valor<< endl;   
}


void caso_1_simpson(){
// Declaración de variables para el caso 1
    string f_str = "e^(x^2)";
    double a = 0.0f;
    double b = 1.0f;
    int n = 11;

    // Crea la instancia del simpson
    simpson i(f_str,a,b,n);

    // Imprimir tabla de datos
    double valor = i.calcular();

    // Calcula el valor de la integral
    i.imprimir_tabla(cout);

    // Imprimir el resltado por pantalla
    cout << "El valor de la integral de " << f_str<< " en el intervalo ["<<
    a << ", "<< b<< "] es: "<<valor<< endl;   
}

void caso_1_error_np(){
    string f_str= "(sin(x))^2";
    string d2f_str= "2*cos(2*x)";
    double a = 0;
    double b = M_PI/ 3.0f;

    int n_trapecio = 1;
    int n_simpson13 = 2;
    int n_simpson38 = 3;

    trapecio t(f_str, a, b, n_trapecio);
    simpson13 s13(f_str, a, b, n_simpson13);
    simpson38 s38(f_str, a, b, n_simpson38);
    
    double i_trapecio = t.calcular();
    cout << "La integral de "<< f_str<<
    " en el intervalo [" << a <<" , "<<b<<
    "] usando trapecio es: "<< i_trapecio << endl;

    cout<<"El error del metodo del trapecio es: "<< fabs(t.error(d2f_str)) << endl;

    double i_simpson13= s13.calcular();
    cout << "La integral de "<< f_str<<
    " en el intervalo [" << a <<" , "<<b<<
    "] usando simpson  con "<<n_simpson13<<" segmentos 1/3 es: "<< i_simpson13 << endl;

    
    double i_simpson38 = s38.calcular();
    cout << "La integral de "<< f_str<<
    " en el intervalo [" << a <<" , "<<b<<
    "] usando simpson  con "<<n_simpson38<<" segmentos 3/8 es: "<< i_simpson38 << endl;


    cout<< "Extensión del caso.... "<<endl;
    n_simpson13 = 8;
    simpson13 s13_2(f_str, a, b, n_simpson13);

    
    i_simpson13= s13_2.calcular();
    cout << "La integral de "<< f_str<<
    " en el intervalo [" << a <<" , "<<b<<
    "] usando simpson  con "<<n_simpson13<<" segmentos 1/3 es: "<< i_simpson13 << endl;
 
}

void caso_1_romberg(){
    using integracion::romberg;
    using integracion::resultado_romberg;
    string f_str = "" ;
    double a = 0.0f;
    double b = M_PI/3.0F;
    int k = 5;

    romberg r(f_str, a, b);

}