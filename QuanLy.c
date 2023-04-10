#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tuthien {
	int stt;
    char ten[50];
    char diachi [20];
    float sotien;
    struct tuthien* next;
} Tuthien;

Tuthien* head = NULL;

void clrscr() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
//Thêm thông tin người quyên góp
void add(Tuthien *tuthien) {
    Tuthien* new_tuthien = (Tuthien*)malloc(sizeof(Tuthien));
	new_tuthien->stt = 0;
    printf("Nhap ho va ten: ");
    fflush(stdin);
    gets(new_tuthien->ten);
    printf("Nhap dia chi: ");
    fflush(stdin);
    gets(new_tuthien->diachi);
    printf("Nhap so tien: ");
    scanf("%f", &new_tuthien->sotien);
    new_tuthien->next = NULL;

    if (head == NULL) {
        head = new_tuthien;
        new_tuthien->stt=1;
    } else {
        Tuthien* node = head;
        while (node->next != NULL) {
            node = node->next;
        }
        new_tuthien->stt = node->stt + 1;
        node->next = new_tuthien;
    }
    printf("Nhap thanh cong!\n");
}
// chỉnh sửa thông tin
void edit(Tuthien *tuthien) {
    int stt;
    printf("nhap stt nguoi can sua : ");
    scanf("%d", &stt);
    Tuthien* node = head;
    while (node != NULL) {
        if (node->stt == stt) {
            printf("Nhap ho ten thay the: ");
            getchar();
    		fgets(node->ten, 50, stdin);
    		node->ten[strcspn(node->ten, "\n")] = 0;
            printf("Nhap dia chi: ");
            fgets(node->diachi, 20, stdin);
    		node->diachi[strcspn(node->diachi, "\n")] = 0;
    		printf("Nhap so tien: ");
    		scanf("%f", &node->sotien);
            printf("Cap nhat thanh cong!\n");
            return;
        }
        node = node->next;
    }
    printf("Khong ton tai.\n");
}

void print(Tuthien *tuthien) {
    printf("Danh sach:\n");
    printf("+-----+---------------------------+---------------+------------------+\n");
    printf("| %-3s | %-25s | %-13s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "So tien");
    printf("+-----+---------------------------+---------------+------------------+\n");

    Tuthien* node = head;
    while (node != NULL) {
        printf("| %-3d | %-25s | %-13s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->sotien);
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+------------------+\n");
}

void xoa(Tuthien *tuthien){
    int stt;
    printf("Nhap STT nguoi can xoa: ");
    scanf("%d", &stt);

    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }

    if (head->stt == stt) {
        Tuthien* temp = head;
        head = head->next;
        free(temp);
        printf("Da xoa thanh cong!\n");
        return;
    }

    Tuthien* node = head;
    while (node->next != NULL) {
        if (node->next->stt == stt) {
            Tuthien* temp = node->next;
            node->next = node->next->next;
            free(temp);
            printf("Da xoa thanh cong!\n");
            return;
        }
        node = node->next;
    }

    printf("Khong tim thay STT can xoa.\n");
}
