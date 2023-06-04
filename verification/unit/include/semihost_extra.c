#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/arch/common/semihost.h>

// This is the semihosting command to execute a system command (isn't defined in semihost.c)
struct semihost_system_args
{
    const char* cmd;
    long        len;
} __packed;

long semihost_system(const char* cmd)
{
    struct semihost_system_args args = {
        .cmd = cmd,
        .len = strlen(cmd),
    };

    return semihost_exec(SEMIHOST_SYSTEM, &args);
}

int semihost_log(const char* fmt, ...)
{
    char buf[256];
    printk("semihost_log 1\n");
    va_list args;
    va_start(args, fmt);
    int len = vsnprintk(buf, sizeof(buf), fmt, args);
    va_end(args);
    printk("semihost_log 2\n");

    const char* path = "./test_log.bin";
    printk("semihost_log 3\n");
    long fd = semihost_open(path, SEMIHOST_OPEN_A);
    printk("semihost_log 4\n");
    long len_long = semihost_write(fd, buf, len);
    printk("semihost_log 5\n");
    semihost_close(fd);
    printk("semihost_log 6\n");
    int write_len = (int) len_long;
    return write_len;
}