/*
 *
 * Problema UVa 673 - Parentheses Balance
 *
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int main(){
    int cases, i;
    string line;
    char aux;
    bool error;
    scanf("%d\n", &cases);

    while(cases--){
        error = false;
        stack<char> pila;
        getline(cin, line);

        for(i = 0; i < line.size(); i++){
            if( line[i] == '(' || line[i] == '[')
                pila.push( line[i] );
            else{
                if( pila.empty() ){
                    error = true;
                    break;
                }else{
                    aux = pila.top();
                    if( ( line[i] == ')' && aux == '(' ) || ( line[i] == ']' && aux == '[' ) )
                        pila.pop();
                    else{
                        error = true;
                        break;
                    }
                }
            }
        }

        if( error == true || !pila.empty() ){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }

    return 0;
}
