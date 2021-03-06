#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

/*
◦ write
◦ opendir
◦ readdir
◦ closedir 
◦ stat
◦ lstat
◦ getpwuid 
◦ getgrgid 
◦ listxattr -  выводит список названий расширенных атрибутов
◦ getxattr 
◦ time
◦ ctime
◦ readlink 
◦ malloc
◦ free
◦ perror
◦ strerror 
◦ exit
*/

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

        Функция opendir() открывает поток каталога и возвращает указатель на структуру типа DIR, 
которая содержит информацию о каталоге.
        Функция readdir() возвращает название следующего файла в каталоге. 
Иными словами, функ­ция readdir() читает оглавление каталога по одному файлу за раз. 
Параметр ptr должен указы­вать на поток каталога, открытый с помощью opendir().
        Функция closedir() в случае успеха возвращает 0 и —1 в противном случае. 
При неудаче переменная errno устанавливается равной EBADF (недействительный каталог). 
Функция opendir() возвращает NULL в том случае, если каталог не может быть открыт. 
При этом переменная errno устанавливается равной либо ENOENT (каталог не найден), либо ENOMEM (недостаточно памя­ти). 
Функция readdir() возвращает NULL, когда достигается конец каталога.
*/

struct dirent
{
        ino_t d_ino;             /* inode */
        off_t d_off;             /* смещение на следующую директорию */
        unsigned short d_reclen; /* длина данной записи */
        unsigned char d_type;    /* тип файла; поддерживается не во всех системах */
        char d_name[256];        /* имя файла */
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
char *pathname;      /* path-имя существующего файла */
struct stat *buffer; /*указатель на строку, принимающую
                                    результаты */

struct stat
{
        dev_t st_dev;         /* устройство */
        ino_t st_ino;         /* inode */
        mode_t st_mode;       /* режим доступа 2*/
        nlink_t st_nlink;     /* количество жестких ссылок 2*/
        uid_t st_uid;         /* идентификатор пользователя-владельца 4*/
        gid_t st_gid;         /* идентификатор группы-владельца */
        dev_t st_rdev;        /* тип устройства 4*/
                              /* (если это устройство) */
        off_t st_size;        /* общий размер в байтах  8*/
        blksize_t st_blksize; /* размер блока ввода-вывода */
                            	/*в файловой системе 4*/
        blkcnt_t st_blocks;   /* количество выделенных блоков 8*/
        struct timespec st_atimespec;   /* время последнего доступа */
        struct timespec st_mtimespec;   /* время последней модификации */
        struct timespec st_сtimespec;   /* время последнего изменения */
};

struct timespec
{
	time_t tv_sec;	/* ordinary sec from 1970.01.01 */
	time_t tv_nsec;	/* nanosec */
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

struct passwd
{
        char *pw_name;   /* имя пользователя */
        char *pw_passwd; /* пароль пользователя */
        uid_t pw_uid;    /* id пользователя */
        gid_t pw_gid;    /* id группы */
        char *pw_gecos;  /* настоящее имя */
        char *pw_dir;    /* домашний каталог */
        char *pw_shell;  /* программа-оболочка */
};

/*________________________________________________________________________________________*/

/*
** Функция getgrgid() возвращает указатель на структуру, содержащую информацию 
** из файла /etc/group о группе, идентификатор которой совпадает с gid.
** Структура group определена в <grp.h>
*/

struct group
{
        char *gr_name;   /* название группы */
        char *gr_passwd; /* пароль группы */
        gid_t gr_gid;    /* идентификатор группы */
        char **gr_mem;   /* члены группы */
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

/*________________________________________________________________________________________*/

/* #include <sys/ioctl.h>  выбирать кол-во колонок в зависимости от разрешения терминала*/ 

/*________________________________________________________________________________________*/


#include <stdarg.h>

int	sumsum(int num, ...)
{
	int sum = 0;
	int count = 0;
	va_list argptr;

	va_start(argptr, num);
	while (count < num)
	{
		sum += va_arg(argptr, int);
		count++;
	}
	va_end(argptr);
	return (sum);
}

int main (int ac, char **av)
{
	int total;
	total = sumsum(5, 3, 5, 7, 6, 4);
	printf("total = %d\n", total);
}

/*

** void va_start( va_list ap, parm_n );
** ap — Экземпляр типа va_list
** parm_n — Именованный аргумент, которые предшествует первому переменному аргументу.
** va_start - требует поддержки, того чтобы parm_n перезагружал operator&.
** va_arg - Макрос, получающий следующий аргумент из функции с переменным числом аргументов.
** va_end - Макрос, завершающий проход по аргументам функции с переменным числом аргументов.

*/

/*  My flags

%p - доступ chmod
%l - кол-во жестких ссылок
%u - имя создателя
%y - год изменения
%s - размер
%m - месяц
%d - дата
%t - время
%n - имя файла

*/

/*
_______________________________________________________________________________________________
1. если у файла нет разрешения на чтение chmod 000, то и прочитать инфу о нем ls -l не получится
2. несуществующие файлы должны вызывать системный отказ
3. в /dev при ls -l в поле где обычно размер файла (major and minor device number)
4. в той же папке /dev есть типы файла b и c 
5. ls -R /usr должны показывать все файлы без утечек и без ошиюок внезависимости от размера 
6. ls -l /dev/fd/ (https://unix.stackexchange.com/questions/74454/somethings-special-about-dev-fd-3)
7. флаги могут быть как отдельно -a -l - R так и вместе -alR
8. ioctl - размер экрана
9. переделать ft_memalloc с exit;
10. total - https://stackoverflow.com/questions/7401704/what-is-that-total-in-the-very-first-line-after-ls-l
11. intra - https://forum.intra.42.fr/topics/16298/messages
12. ft_ls -a /dev/fd - https://unix.stackexchange.com/questions/74454/somethings-special-about-dev-fd-3
13. stererror - https://www.youtube.com/embed/jyULNpjgC8Y
14. errors 
15. dwisoky - чувак который сделал лс
______________________________________________________________________________________________
*/