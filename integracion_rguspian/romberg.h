/**
 * @file 
 * @brief Método de Romberg
 * @author rguspian@unicauca.edu.co
 * @copyright MIT License
 */

#ifndef ROMBERG_H
#define ROMBERG_H
#include <cmath>
#include <string>
#include <vector>


#include "expression.h"
#include "trapecio.h"

using integracion::trapecio;
using std::string;
using std::vector;

namespace integracion{

    /**
     * @brief Resultado de integracion por Romberg
     */
    struct resultado_romberg{
        double valor; /*!< Valor de la integral*/
        int k; /*!< Cantidad de aproximaciones utilizadas*/
        double error; /*!< Error de integración*/
    };
    /**
     * @brief Método de Romberg
     */
    class romberg{
        
        public:
            /**
             * @brief Construye una nueva instacia del metodo
             * @param f_str Función a inegrar
             * @param a Limite inferior
             * @param b Limite superior
             */
            romberg(string f_str, double a, double b): f_str(f_str), a(a), b(b){

            }

            /**
             * @brief Calcula la integral con la k aproximaciones
             * @param k N´umero de aproximaciones
             * @return Resultado de la integración
             */
            resultado_romberg calcular(int k){
                size_t i;
                size_t j;

                // Crear la matriz de k filas
                vector<vector<double>> m(k);

                // Redimensionar las filas
                for (size_t i=0; i< (size_t) k; i++){
                    m[i].resize(k-1);
                }
                
                //Llenar la primera columna de la matrz

                for (i = 0; i< (size_t) k;i++){
                    int n = pow(2,i);
                    trapecio t(f_str, a,b, n);
                    m[i][0] = t.calcular();
                }

                for (j = 1; j< (size_t) k; j++){
                    int potencia = pow(4, j);
                    for (i= 0; i<k -j; i++){
                        m[i][j] = (double) ((double) potencia/ (double) (potencia-1)) * m[i+1][j-1]-
                                     (double) (1.0f/ (double) (potencia-1)) * m[i][j-1];
                    }
                }


                for (i = 0; i<k; i++){
                    for (j=0; j<k; j++){

                    }
                }

                // Calcular el error de la integral
                double v_real = m[0][k-1];
                double v_estimado = m[0][k-2];
                double error = (v_real - v_estimado)/ v_real;

                return resultado_romberg {v_real, k, error};

            }
        private:
            string f_str; /*!< Función a integrar*/
            double a; /*!< Valor de a*/
            double b;/*!< Valor de b*/
    };
}

#endif