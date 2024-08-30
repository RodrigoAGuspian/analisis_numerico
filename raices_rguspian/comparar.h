/**
 * @file
 * @brief Archivo de cabecera de comparar.cpp
 * @author  Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
 * @copyright MIT License
*/

#ifndef COMPARAR_H
#define COMPARAR_H

#include <string>
#include <vector>

using std::string;
using std::vector;

void comparar_newton_raphson(string f_str, string df_str, string  df2_str,vector<double> valores_iniciales, double tol, int n);
 


 #endif