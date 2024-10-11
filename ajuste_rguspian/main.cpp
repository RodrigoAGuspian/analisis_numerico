/**
* @file 
* @brief Regresión e Interpolación
* @author Rodrigo Alejandro Guspian Perez <rguspian@unicauca.edu.co>
* @copyright MIT License
 */

#include <iostream>
#include <vector>
#include "caso.h"
#include "gauss.h"

using std::vector;
using std::cout;
using std::endl;
void prueba_gauss();

int main(int argc, char * argv[]){
    /*{
        caso_1_regresion();
    }*/

   {
    // Caso 1 Función potencia    
    //caso_1_funcion_potencia();
   }

   {
    //prueba_gauss();
   }

   {

    //Caso 1 Función cuadratica
    caso_1_regresion_cuadratica();
   }
    return 0;
}

void prueba_gauss(){
    vector<vector<double>> m_gauss = {
        {6.0f, 15.0f, 55.0f, 152.6f},
        {15.0f, 55.0f, 225.0f, 585.6f},
        {55.0f, 225.0f, 979.0f, 2488.8f}
    };

    vector<double> a = gauss(m_gauss);
    
    for (size_t i = 0; i<a.size(); i++){
        cout<<"a["<<i<<"] = " << a[i] <<endl;
    }
}

