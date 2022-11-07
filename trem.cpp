#include "trem.h"
#include <QtCore>


QSemaphore sem1(1);
QSemaphore sem2(1);
QSemaphore sem3(1);
QSemaphore sem4(1);
QSemaphore sem5(1);
QSemaphore sem6(1);
QSemaphore sem7(1);

//Construtor
Trem::Trem(int ID,int x,int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::setVelocidade(int velocidade) {
    this->velocidade = (int)1000 / velocidade;
}

//Funcao a ser executada após executar trem->START
void Trem::run(){
    while(true) {
        switch(ID) {
        case 1: // TREM 1
            if(x == 450 && y == 30){//Entrar ponto 1
                sem3.acquire();
                sem3.release();
                sem1.acquire();
            }

            if(x == 450 && y == 150){//Saindo ponto 1
                sem1.release();
            }

            if(x == 470 && y == 130){//Entrar ponto 3
                sem3.acquire();
            }

            if(x == 320 && y == 150){//Sair Ponto 3
                sem3.release();
            }

            if(x == 360 && y == 150){//Entrar ponto 2
                sem2.acquire();
            }
            if(x == 200 && y == 130){//Sair Ponto 2
                sem2.release();
            }

            //Movimentos tem 1
            if(y == 30 && x < 470){
                x += 10;
            }
            else if(x == 470 && y < 150) {
                y += 10;

            }
            else if(x > 200 && y == 150) {
                x -= 10;
            }
            else {
                y -= 10;
            }
            emit updateGUI(ID,x,y);  //Emite um sinal
            break;
        case 2: // TREM 2

            if(x == 740 && y == 130) {//Entrar ponto 5
                sem7.acquire();
                sem7.release();
                sem1.acquire();
                sem1.release();
                sem5.acquire();
            }

            if(x == 590 && y == 150){//Sair ponto 5
                sem5.release();
            }

            if(x == 630 && y == 150) {//Entrar ponto 4
                sem4.acquire();
            }

            if(x == 470 && y == 130){//Sair ponto 4
                sem4.release();
            }

            if(x == 490 && y == 150){//Entrar ponto 1
                sem1.acquire();
            }

            if(x == 490 && y == 30){//Sair ponto 1
                sem1.release();
            }

            //Movimentos trem 2
            if(y == 30 && x < 740){

                x += 10;
            }
            else if(x == 740 && y < 150) {

                y += 10;
            }
            else if(x > 470 && y == 150) {

                x -= 10;
            }
            else {
                y -= 10;

            }
            emit updateGUI(ID,x,y);  //Emite um sinal
            break;
        case 3: // TREM 3

            if(x == 180 && y == 150){//Entrar ponto 2
                sem6.acquire();
                sem6.release();
                sem2.acquire();
            }

            if(x == 340 && y == 170){//Sair ponto 2
                sem2.release();
            }

            if(x == 320 && y == 150){//Entrar ponto 6
                sem6.acquire();
            }

            if(x == 320 && y == 270){//Sair 6onto 6
                sem6.release();
            }

            //Movimentos trem 3
            if(y == 150 && x < 340){
                x += 10;
            }
            else if(x == 340 && y < 270) {
                y += 10;
            }
            else if(x > 70 && y == 270) {
                x -= 10;
            }
            else {
                y -= 10;
            }
            emit updateGUI(ID,x,y);  //Emite um sinal
            break;
        case 4: // TREM 4

            if(x == 360 && y == 270){//Entrar ponto 6
                sem2.acquire();
                sem2.release();
                sem3.acquire();
                sem3.release();
                sem6.acquire();
            }

            if(x == 360 && y == 150){//Sair ponto 6
                sem6.release();
            }

            if(x == 340 && y == 170){//Entrar ponto 3
                sem1.acquire();
                sem1.release();
                sem3.acquire();
            }

            if(x == 490 && y == 150) {//Sair ponto 3
                sem3.release();
            }

            if(x == 450 && y == 150){//Entrar ponto 4
                sem5.acquire();
                sem5.release();
                sem4.acquire();
            }

            if(x == 610 && y == 170) {//Sair ponto 4
                sem4.release();
            }

            if(x == 590 && y == 150){//Entrar ponto 7
                sem7.acquire();
            }

            if(x == 590 && y == 270){//Sair ponto 7
                sem7.release();
            }

            //Movimentos trem 4
            if(y == 150 && x < 610){
                x += 10;
            }
            else if(x == 610 && y < 270) {
                y += 10;
            }
            else if(x > 340 && y == 270) {
                x -= 10;
            }
            else {
                y -= 10;
            }
            emit updateGUI(ID,x,y);  //Emite um sinal
            break;
        case 5: // TREM 5

            if(x == 630 && y == 270){//Entrar ponto 7
                sem4.acquire();
                sem4.release();
                sem7.acquire();

            }

            if(x == 630 && y == 150){//Sair ponto 7
                sem7.release();
            }

            if(x == 610 && y == 170){//Entrar ponto 5
                sem5.acquire();
            }

            if(x == 760 && y == 150){//Sair ponto 5
                sem5.release();
            }

            //Movimentos trem 5
            if(y == 150 && x < 880){
                x += 10;
            }
            else if(x == 880 && y < 270) {
                y += 10;
            }
            else if(x > 610 && y == 270) {
                x -= 10;
            }
            else {
                y -= 10;
            }
            emit updateGUI(ID,x,y);  //Emite um sinal
            break;

        default:
            break;
        }
        msleep(velocidade);
    }
}
