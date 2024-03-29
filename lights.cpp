/*
 * Copyright (c) Tuomas Terho (tuomas@terho.net)
 * All rights reserved.
 */

#include "lights.h"

#include <Arduino.h>

lights_c::lights_c(input_c &switch_input, output_c &control_output,
                   output_c &indicator_output)
:       m_switch_input(switch_input), m_control_output(control_output),
        m_indicator_output(indicator_output)
{
}

void lights_c::set_power_on_impl()
{
        run_impl();
}

void lights_c::set_power_off_impl()
{
        m_control_output.set(false);
        m_indicator_output.set(true);
}

void lights_c::run_impl()
{
        bool state;

        state = m_switch_input.get();

        m_control_output.set(state);
        m_indicator_output.set(!state);
}

/* EOF */