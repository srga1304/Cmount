#include <stdio.h>
#include <stdlib.h>

int main() {
    // Открываем pipe для чтения вывода lsblk
    FILE *fp;
    char buffer[256];

    // -o NAME,MOUNTPOINT,LABEL = колонки имя, точка монтирования и метка
    fp = popen("lsblk -o NAME,MOUNTPOINT,LABEL", "r");
    if (fp == NULL) {
        perror("Ошибка запуска lsblk");
        return 1;
    }

    // Читаем построчно и выводим на экран
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // Закрываем pipe
    pclose(fp);
    return 0;
}

