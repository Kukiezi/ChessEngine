#pragma once

#include "Engine/Engine.h"

class QEngine
{
public:

    static QEngine& getInstance()
    {
        static QEngine instance;
        return instance;
    }

    std::shared_ptr<Engine> getEngine();
private:
    QEngine(){};
    std::shared_ptr<Engine> engine = std::make_shared<Engine>();

public:
    QEngine(QEngine const&) = delete;
    void operator=(QEngine const&) = delete;
};

