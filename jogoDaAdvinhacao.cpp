#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main (){ 
    cout << " ***************************************" << endl;
    cout << " ** Bem-vindos ao jogo da advinhação! **" << endl;
    cout << " ***************************************" << endl;

    cout << "Escolha o seu nível de dificuldade: " << endl; 
    cout << "Facil (F). Médio (M). Difícil (D)." << endl; 
    char dificuldade; 
    cin >> dificuldade; 

    int numero_de_tentativas; 
    if(dificuldade == 'F'){
        numero_de_tentativas = 15;
        cout << "Você tem: " << numero_de_tentativas << " tentativas" << endl;
    } else if(dificuldade == 'M'){
        numero_de_tentativas = 10; 
        cout << "Você tem: " << numero_de_tentativas << " tentativas" << endl;
    } else {
        numero_de_tentativas = 5;
        cout << "Você tem: " << numero_de_tentativas << " tentativas" << endl;
    }

    srand(time(NULL)); 
    const int NUMERO_SECRETO = rand() % 100;
 

    bool nao_acertou = true;
    int tentativas = 0; 
    double pontos = 1000.0;  

    for(tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){
        int chute;
        cout << "Tentativas: " << tentativas << endl;
        cout << "Qual o seu chute? ";
        cin >> chute; 

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;

        cout << "O valor do chute é " << chute << endl; 
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
            cout << "Parabéns, você acertou o número secreto!" << endl; 
            nao_acertou = false;
            break; 
        } 
        else if (maior) {
            cout << "Seu chute foi maior que o número secreto" << endl; 
        }
        else {
            cout << "Seu chute foi menor que o número secreto" << endl; 
        }
    }

    cout << "Fim de jogo!" << endl;
    if(nao_acertou){
        cout << "O número secreto era: " << NUMERO_SECRETO << endl;
        cout << "Você perdeu! Tente novamente" << endl; 
    } else {
        cout << "Você acertou o número secreto em: " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de:  " << pontos << " pontos" << endl;
    }
}