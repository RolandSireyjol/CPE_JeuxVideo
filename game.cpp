#include "game.h"

Game::Game(){
    // Création de la fenêtre et du système de rendu.
    device = createDevice(iv::EDT_OPENGL,
                                          ic::dimension2d<u32>(640, 480),
                                          16, false, false, false, &receiver);

    driver = device->getVideoDriver();
    is::ISceneManager* smgr = device->getSceneManager();
    scene_manager = SceneManager(smgr,driver);
    receiver.setSceneManager(&scene_manager);
}


void Game::run(){
    while(device->run())
    {
      scene_manager.iteration();
      driver->beginScene(true, true, iv::SColor(0,50,100,255));

      // Dessin de la scène :
      scene_manager.draw_scene();
      //
      driver->endScene();
    }
    device->drop();
}
