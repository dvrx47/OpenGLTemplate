#include "setup.hpp"
#include "windowRender.hpp"
#include "keyboard.hpp"

GLfloat Ox = 0.0f;
GLfloat Oy = 0.0f;
GLfloat Oz = -50.0f;



GLfloat Ax = 0.0f;
GLfloat Ay = 0.0f;
GLfloat Az = 0.0f;


GL_SETUP __SETUP__;

int main(int argc, char **argv){
    
	int mainWindow;

    glutInit(&argc, argv);

    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );

    mainWindow = glutCreateWindow( "Default Title");
    __SETUP__.loadSetup();

    
    glutDisplayFunc( renderScene );

    glutIdleFunc( renderScene ); 
    
    glutReshapeFunc( reshapeScenePersp);

    glutKeyboardFunc(keyFunc);
    glutKeyboardUpFunc(keyUpFunc);
    glutSpecialFunc(specialKey);
    glutSpecialUpFunc(specialKeyUp);

    std::thread obslugaKlawiatury( obslugaZdarzenKlawiatury );  

    

    setupRC();

    glutMainLoop();
    //obslugaKlawiatury.join();
    glutDestroyWindow( mainWindow );


    return 0;
}
