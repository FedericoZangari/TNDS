#include "RandomGen.h"
#include <math.h>

RandomGen::RandomGen(){
    m_a = 1664525;
    m_c = 1013904223;
    m_m = pow(2,31);
    m_seed = 1;
}

RandomGen::RandomGen(unsigned int i){
    m_a = 1664525;
    m_c = 1013904223;
    m_m = pow(2,31);
    m_seed = i;
}

double RandomGen::Rand(){
    m_seed = (m_a*m_seed +m_c)%m_m;
    return m_seed;
}

double RandomGen::Unif(double xmin, double xmax){
    return xmin + (xmax - xmin) * Rand()/ m_m;
}

double RandomGen::Exp(double mean){
    return -1./mean * log(1 - Rand()/m_m);
}

double RandomGen::Gauss(double mean, double sigma){
    return mean + sigma * sqrt(-2* log( Rand()/m_m ) ) * cos(2* M_PI* Rand()/m_m);
}

double RandomGen::GaussAR(double mean, double sigma){
    double a = mean - 5* sigma;
    double b = mean + 5* sigma;
    double max = 1. / (sigma * sqrt(2. * M_PI));
    double x;
    double y;

    do{
        x = Unif(a,b);
        y = max * Rand()/m_m;
    }while(y > max * exp(- pow(x - mean, 2)/(2*sigma*sigma) ) );

    return x;
}