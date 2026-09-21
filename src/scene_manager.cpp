#include "adam/scene_manager.h"

void SceneManager::changeScene(std::unique_ptr<Scene> newScene) {
    m_pendingScene = std::move(newScene);
}

void SceneManager::applyPendingScene() {
    if (!m_pendingScene) {
        return;
    }
    if (m_currentScene) {
        m_currentScene->cleanup();
    }
    m_currentScene = std::move(m_pendingScene);
    if (m_currentScene) {
        m_currentScene->init();
    }
}

void SceneManager::update(float deltaTime) {
    if (m_currentScene) {
        m_currentScene->update(deltaTime);
    }
    applyPendingScene();
}

void SceneManager::render() {
    if (m_currentScene) {
        m_currentScene->render();
    }
}
