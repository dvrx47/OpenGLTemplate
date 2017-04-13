#include "keyboard.hpp"

bool GL_KEYS_BUF[256];
bool GL_SKEYS_BUF[128];

extern GLfloat Ox;
extern GLfloat Oy;
extern GLfloat Oz;

extern GLfloat Ax;
extern GLfloat Ay;
extern GLfloat Az;

GLfloat delta = 0.5;
GLfloat dkat = 0.1;


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
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        if(GL_SKEYS_BUF[ GLUT_KEY_RIGHT ])
            Ox -= delta;

        if(GL_SKEYS_BUF[ GLUT_KEY_LEFT ])
            Ox += delta;

        if(GL_SKEYS_BUF[ GLUT_KEY_UP ])
            Oy -= delta;

        if(GL_SKEYS_BUF[ GLUT_KEY_DOWN ])
            Oy += delta;

        if(GL_SKEYS_BUF[ GLUT_KEY_F1 ])
            Oz += delta;

        if(GL_SKEYS_BUF[ GLUT_KEY_F2 ])
            Oz -= delta;


        if(GL_SKEYS_BUF[ GLUT_KEY_F3 ])
            Ax += dkat;

        if(GL_SKEYS_BUF[ GLUT_KEY_F4 ])
            Ax -= dkat;

        if(GL_SKEYS_BUF[ GLUT_KEY_F5 ])
            Ay += dkat;

        if(GL_SKEYS_BUF[ GLUT_KEY_F6 ])
            Ay -= dkat;

        if(GL_SKEYS_BUF[ GLUT_KEY_F7 ])
            Az += dkat;

        if(GL_SKEYS_BUF[ GLUT_KEY_F8 ])
            Az -= dkat;
    }
}



