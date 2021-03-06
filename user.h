struct stat;
struct rtcdate;

struct spinlock1 {
  uint locked;
};

struct condvar
{
    int active;
    struct spinlock1 lock;
};


// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int trace_syscalls(int);
int get_children(int);
int get_grandchildren(int);
int getpid_parent(void);
int change_queue(int, int);
int set_ticket(int, int);
int set_ratio_process(int, int, int, int);
int set_ratio_system(int, int, int);
int print_processes_datails();
int semaphore_initialize(int, int, int);
int semaphore_release(int);
int semaphore_aquire(int);

int cv_wait(struct condvar*);
int cv_signal(struct condvar*);

int reader(int);
int writer(int);
int init_rwp(void);



// ulib.c
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *memmove(void*, const void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint strlen(const char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);
void delay(int number_of_clocks);

void init_lock(struct spinlock1 *lk);
void lock(struct spinlock1 *lk);
void unlock(struct spinlock1 *lk);
