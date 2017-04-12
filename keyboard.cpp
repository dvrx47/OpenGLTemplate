#include "keyboard.hpp"

bool GL_KEYS_BUF[256];
bool GL_SKEYS_BUF[128];

void keyFunc(unsigned char key, int x, int y){
    GL_KEYS_BUF[key] = true;
}  

void keyUpFunc(unsigned char key, int x, int y){
    GL_KEYS_BUF[key] = false;
}

void specialKey(int key, int x, int y){
    GL_SKEYS_BUF[key] = true;
}

void specialKeyUp(int key, int x, int y){
    GL_SKEYS_BUF[key] = false;
}

void obslugaZdarzenKlawiatury(){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if( GL_SKEYS_BUF[ GLUT_KEY_RIGHT ] ){
            std::cout<<"1";
        }
    }
}