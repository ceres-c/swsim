#pragma once

#include "pin.h"
#include "proactive.h"
#include <stdint.h>
#include <swicc/swicc.h>

/* Hold state of swSIM. */
typedef struct swsim_s
{
    pin_st pin[PIN_COUNT_MAX];
    swsim__proactive_st proactive;
} swsim_st;

/**
 * @brief Initialize the state of the swSIM (excluding the non-internal buffers
 * that have to be set before calling this function).
 * @param[in, out] sim_state This will be initialized.
 * @param[in, out] swicc_state This will be initialized.
 * @param[in] path_json Path to the JSON definition of the FS.
 * @param[in] path_swicc Where the generated swICC FS file will be written. When
 * this is NULL, the generated swICC file will not be written to disk.
 * @return 0 on success, -1 on failure.
 */
int32_t swsim_init(swsim_st *const swsim_state, swicc_st *const swicc_state,
                   char const *const path_json, char const *const path_swicc);
