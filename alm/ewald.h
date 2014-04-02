/*
 ewald.h

 Copyright (c) 2014 Terumasa Tadano

 This file is distributed under the terms of the MIT license.
 Please see the file 'LICENCE.txt' in the root directory 
 or http://opensource.org/licenses/mit-license.php for information.
*/

#pragma once

#include "pointers.h"
#include <string>
#include <vector>

namespace ALM_NS {

    class Gvecs {
    public:
        double vec[3];

        Gvecs();
        Gvecs(const double *arr)
        {
            for (unsigned int i = 0; i < 3; ++i){
                vec[i] = arr[i];
            }
        };
    };

    class Ewald: protected Pointers {
    public:
        Ewald(class ALM *);
        ~Ewald();

        bool is_longrange;
        std::string file_longrange;

        void init();
        double *Q;
        void ewald_force(const int, double **, double **);  


    private:
        double alpha;
        double Gmax, Lmax;
        int Nmax;
        void load_charge();
        void ewald_force_short(const int, double **, double **);
        void ewald_force_long(const int, double **, double **);
        double dij(double [3], double [3]);
        inline int nint(const double);
        std::vector<Gvecs> G_vector;
        void prepare_G(const double);
    };
}