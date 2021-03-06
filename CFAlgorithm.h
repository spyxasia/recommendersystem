#ifndef CFALGORITHM_H
#define CFALGORITHM_H
#include<iostream>
using namespace std;
#include<locale>
#include<string>
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include<string>
#include<map>
#include <math.h>
#include"User.h"
#include"Movie.h"
#include"Algorithm.h"
#include"Matrix.h"
#include"MatrixVector.h"
#include"MatrixMap.h"
#include"Matrix2D.h"

class CFAlgorithm: public Algorithm
{
public:
    CFAlgorithm(string, string, string);
    CFAlgorithm();
    float cos_similarity(vector<float>,vector<float>);
    float predictRate(map<int,User>, map<int,float>,int, int);
    float predictRate(map<int,Movie>, map<int,float>,int, int);
    void cfuser(map<int,User>,map<int,Movie>,int);
    void cfitem(map<int,User>,map<int,Movie>,int);
    void execute(int);
};
#endif
