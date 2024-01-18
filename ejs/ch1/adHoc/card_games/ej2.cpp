#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >>T;

    while(T--){
        string Jane, John;
        stack<char> fd_jane, fd_john; // podria haberlo hecho mas facil si hacia todos los decks deque.
        deque<char> fu_jane, fu_john;
        cin >> Jane >> John;

        for(int i=Jane.size()-1; i>=0; i--){ // si eran deque tambien, solo hacia falta hacer push_back()
            fd_jane.push(Jane[i]);
            fd_john.push(John[i]);
        }
        
        int turn = 0;
        while(turn < 1000){
            // john gana, jane no tiene mas cartas.
            if(fd_jane.empty() && fu_jane.empty()){
                cout<< "John wins.\n";
                break;
            }
            // jane gana, john no tiene mas cartas.
            if(fd_john.empty() && fu_john.empty()){
                cout<< "Jane wins.\n";
                break;
            }

            // john se queda sin cartas en mazo face down
            if(fd_john.empty()){
                while(!fu_john.empty()){
                    fd_john.push(fu_john.front());
                    fu_john.pop_front();
                }
                continue;
            }

            // jane se queda sin cartas en mazo face down
            if(fd_jane.empty()){
                while(!fu_jane.empty()){
                    fd_jane.push(fu_jane.front());
                    fu_jane.pop_front();
                }
                continue;
            }

            // default case, los ninguno de los masos face down esta vacio...
            // pasamos el top del face down deck al frente del face up deck de ambos jugadores
            fu_jane.push_front(fd_jane.top());
            fu_john.push_front(fd_john.top());
            fd_jane.pop();
            fd_john.pop();

            // snap case, trabajamos sobre los face up decks.
            if(fu_jane.front() == fu_john.front()){
                // mazo ganador = mazo perdedor + mazo ganador
                // 1 -> john wins, 0 -> jane wins
                if((rand()/141)%2){

                    while(!fu_jane.empty()){
                        fu_john.push_front(fu_jane.back()); // el maso fu del ganador se llena desde el principio
                        fu_jane.pop_back();  // el mazo fu del perdedor queda vacio
                    }
                    cout<< "Snap! for John: ";
                    for(char& ch : fu_john) cout<<ch;
                    cout<<"\n";
                } 
                else{
                    
                    while(!fu_john.empty()){
                        fu_jane.push_front(fu_john.back()); // el maso fu del ganador se llena desde el principio
                        fu_john.pop_back();  // el mazo fu del perdedor queda vacio
                    }
                    cout<< "Snap! for Jane: ";
                    for(char& ch : fu_jane) cout<<ch;
                    cout<<"\n";
                } 
            }
            turn++;
        }
        if(turn == 1000) cout<< "Keeps going and going ...\n";
        if(T > 0) cout<< "\n";
    }
    return 0;
}
