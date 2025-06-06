#pragma once

#include "push-button.h"

class PushButtonMock : public PushButton
{
public:
    PushButtonMock(State state);

    State get_state() const;

    // Nur für Tests
    void set_state(State state);

private:
    State _state;
};
