#ifndef setup_hpp
#define setup_hpp
#include "headers.hpp"

class GL_SETUP{
    bool bFullScreen;
	GLsizei initWindowWidth;
    GLsizei initWindowHeight;
    GLfloat windowWidth;
    GLfloat windowHeight;
    bool bDepth;
    bool bCull;
    bool bOutLine;
//ortho
    GLfloat rangeOrtho;

//perspective
    GLfloat closePersp;
    GLfloat farPersp;
    GLfloat angPersp;


public:
    GL_SETUP();
    void loadSetup();
    void setDepthTest( bool s );
    void setCull( bool s );
    void setOutLine( bool s );
    void setWindowSize(int width, int height);

    GLfloat getWindowWidth() const;
    GLfloat getWindowHeight() const;
    GLfloat getRangeOrtho() const;

    GLfloat getClosePersp() const;
    GLfloat getFarPersp() const;
    GLfloat getAngPersp() const;


    void setWindowWidth(GLfloat s);
    void setWindowHeight(GLfloat s);

};

#endif