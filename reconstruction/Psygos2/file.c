#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <malloc.h>

static FILE *curFilePtr;

/**
 * Initialize file IO.
 */
void File_Init() {
    curFilePtr = NULL;
}

/**
 * Returns address to file within group file,
 * such as a .ALL file.
 */
void *FileGroup_GetAddr(void *File, long Index) {
    return (void *) ((int) File + *(int *) ((int) File + Index * 8 + 4));
}

void File_Exec(char *n, long sp, long p1, long p2) {
    assert(0);
}

/**
 * Seek to the specified file.
 * In this case, we just open it as our
 * current internal handle.
 */
void File_Seek(const char *name) {
    if (curFilePtr != NULL) {
        fclose(curFilePtr);
        curFilePtr = NULL;
    }

    curFilePtr = fopen(name, "rb");
}

/**
 * Returns non-zero if the file exists.
 */
long File_IsExist(const char *name) {
    struct stat s;
    if (stat(name, &s) == 0) {
        return 1;
    }

    return 0;
}

/**
 * Read specified number of bytes into
 * the current open file.
 */
void *File_ReadBytes(long nbytes) {
    char *buf = calloc(nbytes, sizeof(char));
    fread(buf, sizeof(char), nbytes, curFilePtr);
    return buf;
}

/**
 * Reads the entire specified file into
 * a buffer.
 */
void *File_Read(char *name) {
    struct stat s;
    if (stat(name, &s) == 0) {
        return NULL;
    }

    FILE *file = fopen(name, "rb");
    if (file == NULL) {
        return NULL;
    }

    char *buf = calloc(s.st_size, sizeof(char));
    fread(buf, sizeof(char), s.st_size, file);
    fclose(file);

    return buf;
}
