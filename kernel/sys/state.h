#ifndef STATE_H
#define STATE_H
#include <stdint.h>

enum system_state {
    SYSTEM_BOOTING,
    SYSTEM_NORMAL,
    SYSTEM_IRQ,
    SYSTEM_ISR,
    SYSTEM_PANIC,
    SYSTEM_MONITOR,
    UDEV_INIT,
    UDEV_CODE,
};


// standardize locations for sysinfo
enum sysinfo_entry {
    SYSINFO_VIDEO_RESX,
    SYSINFO_VIDEO_RESY,
    SYSINFO_VIDEO_PITCH,
    SYSINFO_VIDEO_BPP,
    SYSINFO_VIDEO_PIXELWIDTH,
    SYSINFO_VIDEO_ADDR,

    SYSINFO_TEXT_FBFONT_START,
    SYSINFO_TEXT_FBFONT_END,

    SYSINFO_ICON_START,
    SYSINFO_ICON_END,

    // where malloc should begin
    SYSINFO_MALLOC_START,
    SYSINFO_MALLOC_NOMEM,

    SYSINFO_MEM_LOAD,
    SYSINFO_MEM_LENGTH,

    SYSINFO_TTY_MEMADDR,

    SYSINFO_BOOTLOADER_NAME,
    SYSINFO_BOOT_COMMANDLINE,
};

void set_info(uint32_t a, uint64_t v);
uint64_t get_info(uint32_t a);
void trigger_update();
void set_state(enum system_state ns);
enum system_state get_state();

#endif
