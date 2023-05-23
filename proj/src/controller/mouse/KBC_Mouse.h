#ifndef _kbc_mouse_h_
#define _kbc_mouse_h_

#include <minix/sysutil.h>
#include "i8042.h"
#include <lcom/lcf.h>

int (read_KBC_Mouse_status)(uint8_t* status);

int (read_KBC_Mouse_output)(uint8_t port, uint8_t *output, uint8_t mouse);

int (write_KBC_Mouse_command)(uint8_t port, uint8_t commandByte);

#endif
