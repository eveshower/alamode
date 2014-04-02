/*
 system.h

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
    class System: protected Pointers {
    public:
        System(class ALM *);
        ~System();
        void init();
        void recips(double [3][3], double [3][3]);
        void frac2cart(double **);
        void load_reference_system();
        void load_reference_system_xml();

        int nat, nkd;
        int ndata, nstart, nend, nskip;
        int *kd;
        double lavec[3][3], rlavec[3][3];
        double **xcoord; // fractional coordinate
        double **x_cartesian;
        std::string *kdname;



        unsigned int nclassatom;
        std::vector<unsigned int> *atomlist_class;

        double cell_volume;

    private:
        unsigned int coordinate_index(const char);
        double volume(double [3], double [3], double[3]);
        void setup_atomic_class(int *);
    };
}