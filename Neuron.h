//
// Created by tarak on 12/28/2019.
//

#ifndef NEURALNETWORK_NEURON_H
#define NEURALNETWORK_NEURON_H


#include <cmath>
#include <regex>
#include "Matrix.h"

class Neuron {
    static double sigmoidFunction(double);
    static Matrix sigmoidFunction(const Matrix&);

    static double tanhFunction(double x);
    static Matrix tanhFunction(const Matrix&);
};


#endif //NEURALNETWORK_NEURON_H
