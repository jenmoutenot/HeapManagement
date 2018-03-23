#ifdef MYWAY
#define freemem(p) my_free(p)  //freemem = alias name
#else
#define freemem(p) free(p)
#endif

//function declarations here...maybe more
int my_free(p);
