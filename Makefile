fs_ro: fs_ro.c
        gcc -fPIC -shared -o fs_ro.so fs_ro.c -I../../../include
