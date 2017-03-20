#include "setup.hpp"
#include "windowRender.hpp"


GL_SETUP __SETUP__;

int main(int argc, char **argv){
    
	int mainWindow;

    glutInit(&argc, argv);

    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );

    mainWindow = glutCreateWindow( "Default Title");
    __SETUP__.loadSetup();

    
    glutDisplayFunc( &renderScene );
    
    glutReshapeFunc(&reshapeScenePersp);
    //glutKeyboardFunc(NULL); 
    //glutKeyboardUpFunc(NULL);

    setupRC();

    glutMainLoop();
    glutDestroyWindow( mainWindow );


    return 0;
}
