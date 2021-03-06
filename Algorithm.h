#ifndef ALGORITHM_H
#define ALGORITHM_H

using namespace std;

#include<iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include<string>
#include<map>
#include <math.h>
#include "Movie.h"
#include "Rating.h"
#include "User.h"
#include "MatrixVector.h"
#include "Matrix2D.h"
#include "MatrixMap.h"

class Algorithm
{
protected:
    map<int,User> allUsers;
    map<int,Movie> allMovies;
    vector<Rating> allRatings;
    string userFileAddress;
    string movieFileAddress;
    string ratingFileAddress;
    MatrixVector M_vector;
    Matrix2D M_2D;
    MatrixMap M_map;
    Algorithm(string,string,string);
    Algorithm();
    ~Algorithm();
public:
    void loadRatings();
    void loadMovies();
    void loadUsers();
    map<int, float> getNeighbors(map<int, float>, int);
    void learning_vector(map<int,Movie>, map<int,User>);
    void learning_2D(map<int,Movie>, map<int,User>);
    void learning_map(map<int,Movie>, map<int,User>);
    virtual void execute(int);
};
#endif
