#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, l, q, aux;
    int m = 1000000000+7;

    while( scanf("%d %d", &n, &l) == 2 ){
        vector< vector<int> > gSystem(l);
        for(int i = 0; i < l; i++){
            scanf("%d", &q);
            for(int j = 0; j < q; j++){
                scanf("%d", &aux);
                gSystem[i].push_back(aux-1);
            }
        }

        stack<int> pila;
        pila.push(0);
        int uniqueVisits[n] = {0};
        int generalVisits[n] = {0};
        int visited[n] = {0};
        int father[n] = {0};
        int valFather[n] = {0};

        int unRecorrido = 0, masRecorrido = 0;

        while( !pila.empty() ){
            int tope = pila.top(); pila.pop();

            int tam = gSystem[tope].size();

            for(int i = 0; i < tam; i++){
                int node = gSystem[tope][i];

                if( node > l-1 ){
                    masRecorrido = (masRecorrido+1)%m;
                    valFather[tope] = (valFather[tope]+1)%m;
                    if( !uniqueVisits[node] ){
                        uniqueVisits[node] = 1;
                        unRecorrido = (unRecorrido+1)%m;
                    }
                }
                else{
                    pila.push(node);
                    /*
                    if( visited[node] == 1 ){
                        masRecorrido = ((masRecorrido)%m+(valFather[node])%m)%m;
                    }
                    else{
                        visited[node] = 1;
                        if( father[node] == 0 )
                            father[node] = tope;
                        pila.push(node);
                    }
                    */
                }
            }
        }
        printf("%d %d\n", masRecorrido%m, unRecorrido%m);
    }


    return 0;
}