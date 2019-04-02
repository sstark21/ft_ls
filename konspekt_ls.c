#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
**      ls flags
**
** -a включать в список файлы с именем, начинающимся с точки (показывать скрытые файлы).
** -l выдавать (в одноколоночном формате) тип файла, права доступа к файлу, количество ссылок на файл, 
**    имя владельца, имя группы, размер файла (в байтах), временной штамп и имя файла.
** -r — производить сортировку в обратном порядке.
** -t — сортировать по показываемому временному штампу.
** -R — включить рекурсивную выдачу списка каталогов.
*/

/*________________________________________________________________________________________*/

/*
** функция readdir() возвращает указатель на специальную 
** структуру (тип struct dirent) для каждого элемента каталога. 
*/


struct dirent {
  ino_t          d_ino;       /* inode */
  off_t          d_off;       /* смещение на следующую директорию */
  unsigned short d_reclen;    /* длина данной записи */
  unsigned char  d_type;      /* тип файла; поддерживается не во всех системах */
  char           d_name[256]; /* имя файла */
};

/*________________________________________________________________________________________*/

/*
** stat возвращает информацию о файле file_name и заполняет буфер buf. 
** lstat идентична stat, но в случае символьных сылок она возвращает информацию о самой ссылке, 
** а не о файле, на который она указывает.
**
** В случае успеха возвращается ноль. При ошибке возвращается -1, 
** а переменной errno присваивается номер ошибки.
*/

 int stat(pathname, buffer);
    char *pathname;             /* path-имя существующего файла */
    struct stat *buffer;        /*указатель на строку, принимающую
                                    результаты */

struct stat {
    dev_t         st_dev;      /* устройство */
    ino_t         st_ino;      /* inode */
    mode_t        st_mode;     /* режим доступа 2*/
    nlink_t       st_nlink;    /* количество жестких ссылок 2*/
    uid_t         st_uid;      /* идентификатор пользователя-владельца 4*/
    gid_t         st_gid;      /* идентификатор группы-владельца */
    dev_t         st_rdev;     /* тип устройства 4*/
                               /* (если это устройство) */
    off_t         st_size;     /* общий размер в байтах  8*/ 
    blksize_t     st_blksize;  /* размер блока ввода-вывода 
                                  в файловой системе 4*/
    blkcnt_t      st_blocks;   /* количество выделенных блоков 8*/
    time_t        st_atime;    /* время последнего доступа */
    time_t        st_mtime;    /* время последней модификации */
    time_t        st_ctime;    /* время последнего изменения */
};

/*________________________________________________________________________________________*/

/*
** Функция getpwuid() возвращает указатель на структуру, содержащую поля строки из файла 
** /etc/passwd для записи, совпадающей с идентификатором пользователя uid.
** Структура passwd определена в файле <pwd.h>
**
** Функции getpwnam() и getpwuid() возвращают указатель на структуру passwd или NULL, 
** если искомая запись не найдена или произошла ошибка.  
*/

struct passwd {
        char    *pw_name;       /* имя пользователя */
        char    *pw_passwd;     /* пароль пользователя */
        uid_t   pw_uid;         /* id пользователя */
        gid_t   pw_gid;         /* id группы */
        char    *pw_gecos;      /* настоящее имя */
        char    *pw_dir;        /* домашний каталог */
        char    *pw_shell;      /* программа-оболочка */
};

/*________________________________________________________________________________________*/

/*
** Функция getgrgid() возвращает указатель на структуру, содержащую информацию 
** из файла /etc/group о группе, идентификатор которой совпадает с gid.
** Структура group определена в <grp.h>
*/

struct group {
        char    *gr_name;        /* название группы */
        char    *gr_passwd;      /* пароль группы */
        gid_t   gr_gid;          /* идентификатор группы */
        char    **gr_mem;        /* члены группы */
};

/*________________________________________________________________________________________*/

/* How to print date */

/*
#include <time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

char* formatdate(char* str, time_t val)
{
        strftime(str, 36, "%d.%m.%Y %H:%M:%S", localtime(&val));
        return str;
}

int main()
{
    int errno;
    const char* filename;
    filename = "stat.c";

    errno = 0;
    struct stat *file_info = malloc(sizeof(struct stat));
    if (lstat(filename, file_info) != 0) {
            perror("Error");
            exit(1);
    }

    char date[36];
    printf("Access: %s\n", formatdate(date, file_info->st_atime));
    printf("Modify: %s\n", formatdate(date, file_info->st_mtime));
    printf("Change: %s\n", formatdate(date, file_info->st_ctime));
    free(file_info);
    return 0;
}
*/

/* "%hu" is an unsigned short int which is 16 bit. */
/* printf("%lu\n", sizeof(int)); */