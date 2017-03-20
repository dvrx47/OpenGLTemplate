#include "setup.hpp"

GL_SETUP::GL_SETUP()
{
    initWindowWidth  = 600;
    initWindowHeight = 480;
    rangeOrtho  = 100.0f;

    closePersp = 1.0f;
    farPersp = 400.0f;
    angPersp = 60.0f;

    bDepth = false;
    bCull = false;
    bOutLine = false;
    bFullScreen = true;
    

}

void GL_SETUP::loadSetup(){

    if(bDepth)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);


    if(bCull)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);


    if(bOutLine)
        glPolygonMode(GL_BACK, GL_LINE);
    else
        glPolygonMode(GL_BACK, GL_FILL);

    if(bFullScreen)
        glutFullScreen();
    else
        glutInitWindowSize( initWindowWidth, initWindowHeight );
    
}

void GL_SETUP::setDepthTest( bool s ){
    bDepth = s;
}

void GL_SETUP::setCull( bool s ){
    bCull = s;
}

void GL_SETUP::setOutLine( bool s ){
    bOutLine = s;
}


void GL_SETUP::setWindowSize(int width, int height){
    windowWidth  = width;
    windowHeight = height; 
}

GLfloat GL_SETUP::getWindowWidth() const {
    return windowWidth;
}

GLfloat GL_SETUP::getWindowHeight() const {
    return windowHeight;
}

GLfloat GL_SETUP::getRangeOrtho() const {
    return rangeOrtho;
}

void GL_SETUP::setWindowWidth(GLfloat s){
    windowWidth = s;
}

void GL_SETUP::setWindowHeight(GLfloat s){
    windowHeight = s;
}


GLfloat GL_SETUP::getClosePersp() const{
    return closePersp;
}

GLfloat GL_SETUP::getFarPersp() const{
    return farPersp;
}

GLfloat GL_SETUP::getAngPersp() const{
    return angPersp;
}