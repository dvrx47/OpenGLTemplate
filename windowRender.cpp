#include "windowRender.hpp"
#include "headers.hpp"



void renderScene(){
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    

    
    //===TEST===========
    glPushMatrix();
    glTranslatef( 0, 0, -50);

    GLfloat cube = 10.0f;
    glutWireCube( cube );
    glPopMatrix();
    //==================

    
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