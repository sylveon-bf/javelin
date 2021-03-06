#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>

#define stdio_tty_out 0x00
#define stdio_ser_out 0xa0
#define stdio_lpt_out 0xb0
#define stdio_dbg_out 0xff

typedef enum {
    IO_INPUT_OUTPUT,
    IO_INPUT,
    IO_OUTPUT,
} io_mode;

typedef struct io_struct_t {
    void (*write_byte)(char i, struct io_struct_t* c);
    char (*read_byte)(struct io_struct_t* c);
    void (*write_stream)(void* s, int l, struct io_struct_t* c);
    int (*read_stream)(void* s, int l, struct io_struct_t* c);
    int (*get_available)(struct io_struct_t* c);
    io_mode cmode;
} io_struct;

extern io_struct* tty_handle;
extern io_struct* ser_handle;
extern io_struct* lpt_handle;
extern io_struct* bochs_handle;

void vfprintf(io_struct* handle, const char* fmt, va_list varg);
void vsprintf(int output, const char* fmt, va_list varg);
static inline void vprintf(const char* fmt, va_list varg) { vsprintf(stdio_tty_out,fmt,varg); }

void printf(const char* fmt,...);
void fprintf(io_struct* handle, const char* fmt,...);

#endif