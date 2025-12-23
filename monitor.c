#include <stdio.h>

#ifdef _WIN32
#define _WIN32_WINNT 0x0600
#include <windows.h>
#else
#include <unistd.h>
#endif

/* ------------ CPU USAGE ------------ */

#ifdef _WIN32
double get_cpu_usage() {
    static ULONGLONG pi = 0, pk = 0, pu = 0;
    FILETIME idle, kernel, user;

    GetSystemTimes(&idle, &kernel, &user);

    ULONGLONG i = ((ULONGLONG)idle.dwHighDateTime << 32) | idle.dwLowDateTime;
    ULONGLONG k = ((ULONGLONG)kernel.dwHighDateTime << 32) | kernel.dwLowDateTime;
    ULONGLONG u = ((ULONGLONG)user.dwHighDateTime << 32) | user.dwLowDateTime;

    ULONGLONG sys = (k - pk) + (u - pu);
    ULONGLONG idleT = i - pi;

    pi = i; pk = k; pu = u;

    if (sys == 0) return 0.0;
    return 100.0 * (sys - idleT) / sys;
}
#else
long long idle() {
    FILE *fp = fopen("/proc/stat", "r");
    long long u, n, s, i;
    fscanf(fp, "cpu %lld %lld %lld %lld", &u, &n, &s, &i);
    fclose(fp);
    return i;
}

long long total() {
    FILE *fp = fopen("/proc/stat", "r");
    long long u, n, s, i;
    fscanf(fp, "cpu %lld %lld %lld %lld", &u, &n, &s, &i);
    fclose(fp);
    return u + n + s + i;
}

double get_cpu_usage() {
    long long i1 = idle(), t1 = total();
    sleep(1);
    long long i2 = idle(), t2 = total();
    return 100.0 * (1.0 - (double)(i2 - i1) / (t2 - t1));
}
#endif

/* ------------ RAM USAGE ------------ */

#ifdef _WIN32
void get_ram_usage() {
    MEMORYSTATUSEX m;
    m.dwLength = sizeof(m);
    GlobalMemoryStatusEx(&m);

    printf("RAM: %lld / %lld MB\n",
        (m.ullTotalPhys - m.ullAvailPhys) / (1024 * 1024),
        m.ullTotalPhys / (1024 * 1024));
}
#else
void get_ram_usage() {
    FILE *fp = fopen("/proc/meminfo", "r");
    long t, f;
    fscanf(fp, "MemTotal: %ld kB\nMemFree: %ld kB", &t, &f);
    fclose(fp);

    printf("RAM: %ld / %ld MB\n", (t - f) / 1024, t / 1024);
}
#endif

int main() {
    while (1) {
        printf("CPU Usage: %.2f%%\n", get_cpu_usage());
        get_ram_usage();

    #ifdef _WIN32
        Sleep(1000);
    #else
        sleep(1);
    #endif

        printf("------------------\n");
    }
    return 0;
}
