#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "adam/game_settings.h"
#include "adam/scene.h"
#include <memory>

class SceneManager {
  private:
    std::unique_ptr<Scene> m_currentScene = nullptr;
    std::unique_ptr<Scene> m_pendingScene = nullptr;
    std::unique_ptr<GameSettings> m_settings = std::make_unique<GameSettings>();

    void applyPendingScene();

  public:
    void changeScene(std::unique_ptr<Scene> newScene);
    void update(float deltaTime);
    void render();

    const std::unique_ptr<GameSettings> &getSettings() const {
        return this->m_settings;
    }
};

#endif // SCENE_H
