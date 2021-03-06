#include "CBAlgorithm.h"

CBAlgorithm::CBAlgorithm(){}
CBAlgorithm::CBAlgorithm(string a,string b,string c):Algorithm(a,b,c){
}


float CBAlgorithm::cos_similarity(map <int,float> U1, map <int,float>U2){
    /*

    */
    float a,b,c;
    for (std::map<int,float>::iterator it = U1.begin(); it != U1.end(); ++it){
        a=a+((U1[it->first]!=0)*U1[it->first]*U2[it->first]*(U2[it->first]!=0));
        b=b+((U1[it->first]!=0)*U1[it->first]*U1[it->first]);
        c=c+(U2[it->first]*(U2[it->first]!=0)*U2[it->first]);
    }
        b=sqrt(b);
        c=sqrt(c);
        if(b*c!=0)
        {
            return a/(b*c);
        }
        else {
            return 0;
        }

}

map <int,float> CBAlgorithm::getTop(map <int,float> sim,int top){
    map<int,float> res;
    int maximum;
    for (int i=0;i<top;i++){
        maximum=0;
        sim[maximum]=-2;
        for (std::map<int,float>::iterator it=sim.begin(); it!=sim.end(); ++it){
            if (it->second > sim[maximum]){
                maximum=it->first;
            }
        }
        cout<<maximum<<endl;
        res.insert(std::pair<int,float>(maximum,sim[maximum]));
        sim.erase(maximum);
    }
    return res;
}
void CBAlgorithm::execute(int methode){
    /*
    */
    int choice;
    int user=0; // user to predict
    map <int, float> similarity; //map of similarities of user with all movies
    map <int, float> top_sim;
    int top=10;
    int index;

    cout << "--------------------------------LOADING CONTENT BASED ALGORITHM--------------------------------\n\n";
    loadMovies();
    loadUsers();
    cout << allMovies.size() << " Movies and " << allUsers.size() <<" Users loaded !\n";


    if (methode==1){
        learning_2D(allMovies,allUsers);
    }
    else if (methode==2){
        learning_vector(allMovies,allUsers);
    }
    else{
        learning_map(allMovies,allUsers);
    }
    reuse:
    index=0;
    while ((index > 2113) or (index < 1)){
        cout << "Enter the id of the user you want to recommend to : ";
        cin >> user;
        index=allUsers[user].gethId(); // return what when not found ?
    }
    if (methode==1){
            allUsers[user].assignRatings(M_2D.getColumn(index));
            allUsers[user].setProfile(allMovies);
            cout<<"Predicting Top 10..."<<endl;
            for(std::map<int,Movie>::iterator it=allMovies.begin();it!=allMovies.end();it++){
                if (allUsers[user].getRatings()[it->second.gethId()]==0){
                similarity.insert(pair<int,float>(it->first,cos_similarity(allUsers[user].getProfile(),it->second.getProfile())));
                }
            }
            top_sim=getNeighbors(similarity,top);
            cout<<endl<<"The top 10 recommended movies are:"<<endl<<endl;
            for(std::map<int,float>::iterator it=top_sim.begin();it!=top_sim.end();it++){
                cout<<allMovies[it->first].getTitle()<<" (id:"<<it->first<<")"<<endl;
            }
    }
    else if (methode==2){
            allUsers[user].assignRatings(M_vector.getColumn(index));
            allUsers[user].setProfile(allMovies);
            cout<<"Predicting Top 10..."<<endl;
            for(std::map<int,Movie>::iterator it=allMovies.begin();it!=allMovies.end();it++){
                if (allUsers[user].getRatings()[it->second.gethId()]==0){
                similarity.insert(pair<int,float>(it->first,cos_similarity(allUsers[user].getProfile(),it->second.getProfile())));
                }
            }
            top_sim=getNeighbors(similarity,top);
            cout<<endl<<"The top 10 recommended movies are:"<<endl<<endl;
            for(std::map<int,float>::iterator it=top_sim.begin();it!=top_sim.end();it++){
                cout<<allMovies[it->first].getTitle()<<" (id:"<<it->first<<")"<<endl;
            }
    }
    else{
            allUsers[user].assignRatings(M_map.getColumn(index));
            allUsers[user].setProfile(allMovies);
            cout<<"Predicting Top 10..."<<endl;
            for(std::map<int,Movie>::iterator it=allMovies.begin();it!=allMovies.end();it++){
                if (allUsers[user].getRatings()[it->second.gethId()]==0){
                similarity.insert(pair<int,float>(it->first,cos_similarity(allUsers[user].getProfile(),it->second.getProfile())));
                }
            }
            top_sim=getNeighbors(similarity,top);
            cout<<endl<<"The top 10 recommended movies are:"<<endl<<endl;
            for(std::map<int,float>::iterator it=top_sim.begin();it!=top_sim.end();it++){
                cout<<allMovies[it->first].getTitle()<<" (id:"<<it->first<<")"<<endl;
            }



    }
    cout << "\nSelect an action :\n1/Reuse\n2/Quit\n";
    cin >> choice;
    if (choice==1)
        goto reuse;
    else
        cout << "GOOD BYE !";
}
