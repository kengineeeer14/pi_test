#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd;

    /* GPIO17の操作ファイル生成 */
    fd = open("/sys/class/gpio/export", O_RDWR);
    write(fd, "17", 2);
    close(fd);
    sleep(1);

    /* GPIO17を出力に変更 */
    fd = open("/sys/class/gpio/gpio17/direction", O_RDWR);
    write(fd, "out", 3);
    close(fd);

    /* GPIO17の出力をON */
    fd = open("/sys/class/gpio/gpio17/value", O_RDWR);
    write(fd, "1", 1);
    close(fd);
    sleep(2);

    /* GPIO14の操作ファイル削除 */
    fd = open("/sys/class/gpio/unexport", O_RDWR);
    write(fd, "17", 2);
    close(fd);

    return(0);
}
