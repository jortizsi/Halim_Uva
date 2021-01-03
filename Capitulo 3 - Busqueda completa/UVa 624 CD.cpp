#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > candidatesSongs;
vector<int> candidatesSums;

void getBestOption(vector<int> songsRecorded, int minutesTaken,int i,int* disksDuration,int disksAmount,int tapeCapacity){
    //Casp base, en el cual ya he procesado el subconjunto, o hemos revisado toda la lista de canciones
    if(i == disksAmount && minutesTaken <= tapeCapacity){
        candidatesSongs.push_back(songsRecorded);
        candidatesSums.push_back(minutesTaken);
    }else if(i<disksAmount){//Caso recursivo en el cual voy construyendo mis soluciones parciales.
        //1)Poner el iesimo elemento
        //2)llamar recursion para esa solucion parcial
        //3)quitar iesimo elemento
        //4)llamar recursion para esa solucion parcial
        //5)incrementar i
        //6)En cada llamada modificar el valor de minutesTaken
        int diski = disksDuration[i];
        songsRecorded.push_back(diski);
        i++;
        getBestOption(songsRecorded,minutesTaken+diski,i,disksDuration,disksAmount,tapeCapacity);
        songsRecorded.pop_back();
        getBestOption(songsRecorded,minutesTaken,i,disksDuration,disksAmount,tapeCapacity);
    }
}

int main(){
    int tapeCapacity;
    int disksAmount;
    while(scanf("%d %d",&tapeCapacity,&disksAmount)!= EOF){
        int* disksDuration = new int[disksAmount];
        for(int i = 0; i<disksAmount; i++){
            scanf("%d",&disksDuration[i]);
        }
        vector<int> songsRecorded;
        int minutesTaken = 0;
        int i = 0;
        getBestOption(songsRecorded,minutesTaken,i,disksDuration,disksAmount,tapeCapacity);
        int bestMinutesRecorded = -2147483648;
        int optimalindex = -1;
        for(int i = 0;i<candidatesSums.size();i++){
            if(candidatesSums.at(i)>bestMinutesRecorded){
                    bestMinutesRecorded = candidatesSums.at(i);
                    optimalindex = i;
            }
        }
        for(int i = 0; i<candidatesSongs.at(optimalindex).size();i++){
            cout<<candidatesSongs.at(optimalindex).at(i)<<" ";
        }
        cout<<"sum:"<<candidatesSums.at(optimalindex)<<"\n";
        //Limpiar canciones candidatas
        /*for(int i = 0;i<candidatesSongs.size();i++){
            for(int j = 0; j<candidatesSongs.at(i).size();j++){
                    candidatesSongs.at(i).clear();
            }
        }*/
        candidatesSums.clear();
        candidatesSongs.clear();
        songsRecorded.clear();
        delete[] disksDuration;
    }
    return 0;
}
