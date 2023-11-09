#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int nums[8], contar, mJ[4][4], firstNum;
    firstNum = 1;
    bool loop = true;

    //Criação de uma matriz 4x4 com números aleatórios.
    for(int j = 0; j < 4; j++){
            for(int i = 0; i < 4; i++){
                mJ[i][j] = rand()%8 + firstNum;
            }
    }
    for(int i = 0; i < 8; i++){
        nums[i] = firstNum + i;
    }

    while(loop == true){
        loop = false;
        for(int c = 0; c < 8; c++){
            nums[c];
            contar = 0;
            for(int j = 0; j < 4; j++){
                    for(int i = 0; i < 4; i++){
                    mJ[i][j];
                    if(mJ[i][j] == nums[c]){
                        contar++;
                    }
                    if(contar > 2){
                        mJ[i][j] = rand()%8 + firstNum;
                        loop = true;
                    }
                }
            }
        }
    }
    int mG[4][4], mf,menu;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"                                                  JOGO DA MEMORIA"<<endl;
cout<<"                                                 DIGITE 1 PARA JOGAR"<<endl;
cout<<"                                           OU QUALQUER OUTRO BOTÃO PARA SAIR"<<endl;
    cin>>menu;
    while(menu==1){
    mf = rand()%4;

    switch(mf){
    //Sem modificação.
    case 0:
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                    mG[i][j] = mJ[i][j];
            }
    }
        break;
    //Transposta.
    case 1:
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                mG[j][i] = mJ[i][j];
            }
    }
        break;
    //Invertida linha.
    case 2:
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                mG[i][j] = mJ[3 - i][j];
            }
    }
        break;
    //Invertida coluna.
    case 3:
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                mG[i][j] = mJ[i][3 - j];
            }
    }
        break;
    }
int x[2], y[2];
    bool win = false;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            mJ[i][j] = 0;
        }
    }

    for(int n = 0; n < 24; n++){
            for(int p = 0; p < 3; p++){
            system("cls");
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
             cout<<"                                                ";
            cout<<"Jogadas realizadas: "<<n<<endl;
             cout<<"                                                      ";
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    cout<<mJ[i][j]<<" ";
                }
                cout<<endl;
                 cout<<"                                                      ";
            }
            cout<<endl;
            switch(p){
            default:
                 cout<<"                                                    ";
                cout<<"Peça "<<p<<":"<<endl;
                cin>>x[p]>>y[p];
                if(x[p] < 4 && y[p] < 4 && x[p] > -1 && y[p] > -1 && mJ[x[p]][y[p]] == 0){
                    mJ[x[p]][y[p]] = mG[x[p]][y[p]];
                }else{
                    cout<<"Jogada inválida."<<endl;
                    system("pause");
                    p--;
                }
                break;
            case 2:
                if(mJ[x[0]][y[0]] == mJ[x[1]][y[1]]){
                    cout<<"JOGADA OK"<<endl;
                }else{
                    cout<<"JOGADA NOK"<<endl;
                    mJ[x[0]][y[0]] = 0;
                    mJ[x[1]][y[1]] = 0;
                }
                break;
            }
        }
        system("pause");
        contar = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(mJ[i][j] == 0){
                    contar++;
                }
            }
        }
        if(contar == 0){
            n = 24;
            win = true;
        }
    }
    system("cls");
    if(win == true){
        cout<<"Vitória."<<endl;
    }else{
        cout<<"Derrota"<<endl;
    }

  }
    return 0;
    }
