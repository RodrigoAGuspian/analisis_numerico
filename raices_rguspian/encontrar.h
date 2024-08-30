/**
 * @file
 * @brief Archivo de cabecera de encontrar.cpp
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef ENCONTRAR_H
#define ENCONTRAR_H

#include <string>

using std::string;

void encontrar_tvi(string f_str, double a, double b, double h);
void encontrar_biseccion(string f_str, double a, double b, double tol, int n);
void encontrar_regla_falsa(string f_str, double xi, double xs, double tol, int n);
void encontrar_newton_raphson(string f_str, string df_str, double p0, double tol, int n);
void encontrar_secante(string f_str, double x0, double x1, double tol, int n);
void encontrar_newton_raphson_g(string f_str, string df_str, string df2_str,double p0, double tol, int n);

#endif