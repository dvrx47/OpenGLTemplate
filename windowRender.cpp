#include "windowRender.hpp"
#include "headers.hpp"

extern GLfloat Ox;
extern GLfloat Oy;
extern GLfloat Oz;

extern GLfloat Ax;
extern GLfloat Ay;
extern GLfloat Az;


void renderScene(){
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    

    
    
    glPushMatrix();
    glTranslatef( Ox, Oy, Oz);
    glRotatef( Ax, 1.0, 0.0, 0.0);
    glRotatef( Ay, 0.0, 1.0, 0.0);
    glRotatef( Az, 0.0, 0.0, 1.0);

    //===Tutaj kod do nauki===========
    
    GLfloat cube = 10.0f;
    glutWireCube( cube );

    //==================
    glPopMatrix();
    

    
    glutSwapBuffers();
}


void setupRC(){
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glColor3f( 0.0f, 1.0f, 0.0f);
      glShadeModel( GL_FLAT );
}


void reshapeSceneOrtho(GLsizei w, GLsizei h){
    if( h == 0 )
        h = 1;

    GLfloat aspect = (GLfloat)w/(GLfloat)h;
    
    glViewport( 0, 0, w, h );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    if( w <= h ){
        __SETUP__.setWindowWidth( __SETUP__.getRangeOrtho() );
        __SETUP__.setWindowHeight( __SETUP__.getRangeOrtho()/aspect );
        glOrtho(     -__SETUP__.getWindowWidth(),
                      __SETUP__.getWindowWidth(),
                     -__SETUP__.getWindowHeight(),
                      __SETUP__.getWindowHeight(),
                      1.0f, -1.0f
                );
    }
    else{
        __SETUP__.setWindowWidth( __SETUP__.getRangeOrtho() * aspect );
        __SETUP__.setWindowHeight( __SETUP__.getRangeOrtho() );
        glOrtho( -__SETUP__.getWindowWidth(),
                  __SETUP__.getWindowWidth(),
                 -__SETUP__.getWindowHeight(), 
                  __SETUP__.getWindowHeight(), 
                  1.0f, -1.0f
               );
    }
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();

}

//to samo co wyżej
void reshapeScenePersp(int w, int h){
    if( h == 0 )
        h = 1;

    GLfloat aspect = (GLfloat)w/(GLfloat)h;
    
    glViewport( 0, 0, w, h );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    gluPerspective( __SETUP__.getAngPersp(),
                    aspect, 
                    __SETUP__.getClosePersp(), 
                    __SETUP__.getFarPersp()
                  );

    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}