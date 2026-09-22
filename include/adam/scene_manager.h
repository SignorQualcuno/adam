#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "adam/scene.h"
#include <memory>

class SceneManager {
  private:
    std::unique_ptr<Scene> m_currentScene = nullptr;
    std::unique_ptr<Scene> m_pendingScene = nullptr;

    void applyPendingScene();

  public:
    void changeScene(std::unique_ptr<Scene> newScene);
    void update(float deltaTime);
    void render();
};

#endif // SCENE_H
