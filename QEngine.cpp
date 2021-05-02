#include "QEngine.h"

std::shared_ptr<Engine> QEngine::getEngine()
{
    return engine;
}

void QEngine::setNewEngine()
{
    std::shared_ptr<Engine> newEngine = std::make_shared<Engine>();
    this->engine = newEngine;
}
