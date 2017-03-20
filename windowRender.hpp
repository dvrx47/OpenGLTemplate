#ifndef windowRender_hpp
#define windowRender_hpp
    #include "setup.hpp"

    extern GL_SETUP __SETUP__;

    void renderScene();
    void reshapeSceneOrtho(int w, int h);
    void reshapeScenePersp(int w, int h);

    void setupRC();

#endif