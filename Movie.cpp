#include"Movie.h"


Movie::Movie(int i,string t)
{
    id=i;
    title=t;
    ratings.push_back(0);
    profile;
}
Movie::Movie(int i,int h, string t)
{
    id=i;
    hId=h;
    title=t;
    ratings.push_back(0);
}
Movie::Movie(){}

Movie::~Movie(){
    profile.clear();
    vector<float>().swap(ratings);

}
void Movie::addRating(float r)
{
    ratings.push_back(r);
}
vector<float> Movie::getRatings()const
{
    return ratings;
}
string Movie::getTitle()const
{
    return title;
}
void Movie::getAvg(){
    int i=1;
    int j=0;
    float sum=0;
    while (i<ratings.size()){
        if (ratings.at(i)!=0){
            j++;
            sum+=ratings[i];
        }
        i++;
    }
    if (sum!=0)
        ratings[0]=sum/j;
    else
        ratings[0]=0;
}
int Movie::getId()const{
    return id;
}
int Movie::gethId()const{
    return hId;
}
void Movie::assignRatings(vector<float> r){
    ratings=r;
}
Movie& Movie::operator=(Movie& M){
    if(&M!=this){
        id=M.id;
        hId=M.hId;
        title=M.title;
        ratings=M.ratings;
    }
    return *this;
}

void Movie::setTag(int tagid, float tag_weight){
    profile.insert(pair<int,float>(tagid,tag_weight));
}

map<int,float> Movie::getProfile()const{
    return profile;
}
