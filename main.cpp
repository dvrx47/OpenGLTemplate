#include "setup.hpp"
#include "windowRender.hpp"
#include "keyboard.hpp"




GL_SETUP __SETUP__;

int main(int argc, char **argv){
    
	int mainWindow;

    glutInit(&argc, argv);

    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );

    mainWindow = glutCreateWindow( "Default Title");
    __SETUP__.loadSetup();

    
    glutDisplayFunc( &renderScene );
    
    glutReshapeFunc(&reshapeScenePersp);

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
