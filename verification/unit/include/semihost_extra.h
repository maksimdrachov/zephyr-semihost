#ifndef SEMIHOST_EXTRA_H
#define SEMIHOST_EXTRA_H

long semihost_system(const char* cmd);

int semihost_log(const char* fmt, ...);

#endif  // SEMIHOST_EXTRA_H