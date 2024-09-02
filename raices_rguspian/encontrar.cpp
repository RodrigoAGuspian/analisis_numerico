
/**
 * @file
 * @brief Funciones que llaman a diferentes metodos para encontrar una raiz
 * @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/



#include <iostream>
#include <string>

#include "biseccion.h"
#include "encontrar.h"
#include "falsa.h"
#include "muller.h"
#include "newtonRaphson.h"
#include "newtonRaphsonG.h"
#include "secante.h"
#include "tvi.h"

using std::string;
using raices::biseccion;
using raices::falsa;
using raices::muller;
using raices::newton_raphson;
using raices::newton_raphson_g;
using raices::secante;
using raices::solucion;
using raices::tvi;



/**
 * @brief Encuentra la raíz de una función utilizando el método del Teorema del Valor Intermedio (TVI).
 * @param f_str La función en formato de cadena.
 * @param a El límite inferior del intervalo.
 * @param b El límite superior del intervalo.
 * @param h El tamaño del paso para la búsqueda.
 */

void encontrar_tvi(string f_str, double a, double b, double h){
    // Instanciar el tvi.
    tvi t(f_str);

    // Encontrar la solución.
    solucion sol = t.encontrar(a,b,h);

    sol.imprimir();
}


/**
 * @brief Encuentra la raíz de una función utilizando el método de bisección.
 * @param f_str La función en formato de cadena.
 * @param a Límite inferior de la función
 * @param b Límite superior de la función
 * @param tol Tolerancia - del Error Relativo Porcentual
 * @param n Número máximo de repeticiones   
 */
void encontrar_biseccion(string f_str, double a, double b, double tol, int n){
    // Instanciar biseccion.
    biseccion t(f_str);

    // Encontrar la solución.
    solucion sol = t.encontrar(a,b,tol,n);

    sol.imprimir();
}

/**
 * @brief Encuentra la raíz de una función utilizando el método de regla falsa.
 * @param f_str Función como texto
 * @param xi Límite inferior de la función
 * @param xs Límite superior de la función
 * @param tol Tolerancia - del Error Relativo Porcentual
 * @param n Número máximo de repeticiones
*/

void encontrar_regla_falsa(string f_str, double xi, double xs, double tol, int n){
    // Instanciar regla falsa.
    falsa regla_falsa(f_str);
    
    // Encontrar la solución.
    solucion sol = regla_falsa.encontrar(xi, xs, tol, n);

    sol.imprimir();
}

/**
 * @brief Encuentra la raíz de una función utilizando el método de Newton Rapshon.
 * @param f_str Función como texto
 * @param df_str Derivada como texto
 * @param p0 Valor Inicial (primera aproximación de x)
 * @param tol Tolerancia - del Error Relativo Porcentual
 * @param n Número máximo de repeticiones
*/

void encontrar_newton_raphson(string f_str, string df_str, double p0, double tol, int n){
    // Instanciar newton rapshon.
    newton_raphson nr(f_str, df_str);
    
    // Encontrar la solución.
    solucion sol = nr.encontrar(p0, tol, n);

    sol.imprimir();
}

/**
 * @brief Encuentra la raíz de una función utilizando el método de Secante.
 * @param f_str Función como texto
 * @param x0 Valor x0 de la funcion
 * @param x1 Valor x0 de la funcion
 * @param tol Tolerancia - del Error Relativo Porcentual
 * @param n Número máximo de repeticiones
*/

void encontrar_secante(string f_str, double x0, double x1, double tol, int n){
    // Instanciar secante.
    secante secan(f_str);
    
    // Encontrar la solución.
    solucion sol = secan.encontrar(x0, x1, tol, n);

    sol.imprimir();
}


/**
 * @brief Encuentra la raíz de una función utilizando el método de Newton Rapshon.
 * @param f_str Función como texto
 * @param df_str Derivada como texto
 * @param df2_str Segunda derivada como texto
 * @param p0 Valor Inicial (primera aproximación de x)
 * @param tol Tolerancia - del Error Relativo Porcentual
 * @param n Número máximo de repeticiones
*/

void encontrar_newton_raphson_g(string f_str, string df_str, string  df2_str,double p0, double tol, int n){
    // Instanciar newton rapshon generalizado.
    newton_raphson_g nr(f_str, df_str, df2_str);
    
    // Encontrar la solución.
    solucion sol = nr.encontrar(p0, tol, n);

    sol.imprimir();
}


/**
 * @brief Encuentra una raiz de la función usando el método de Müller
 * @param f_str Función como texto
 * @param x0 Punto inicial
 * @param x1 Punto intermedio
 * @param x2 Punto final
 * @param tol Tolerancia - del Error Relativo Porcentual
 * @param n Número máximo de repeticiones
 * 
*/
void encontrar_muller(string f_str, double x0, double x1, double x2, double tol, int n){
    // Instanciar Müller
    muller m(f_str);

    // Encontrar la solución
    solucion sol = m.encontrar(x0, x1, x2, tol, n);
    sol.imprimir();

    
}