#pragma once
#include "Screen.h"

class StageMain {
protected:
    float deltaTime;

public:

    StageMain();
    virtual ~StageMain() = default;
    virtual void Update() { }
    virtual void Display() { }

    void SetDeltaTime(float _deltaTime) { deltaTime = _deltaTime; }
};
