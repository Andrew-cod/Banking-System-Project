#include <stdio.h>
 
#ifdef _WIN32 // is _WIN32 defined?
//do something for windows like #include <windows.h>
void f() {
    printf("_WIN32\n");
}
#elif defined __unix__ // or is __unix__ defined?
//do something for unix like #include <unistd.h>
void f() {
    printf("__unix__\n");
}
#elif defined __APPLE__ // or is __APPLE__ defined?
//do something for mac
void f() {
    printf("__APPLE__\n");
}
#endif
 
int main() {
    f();
    return 0;
}