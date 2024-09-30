#include <stdio.h>

// Hàm hiển thị menu và trả về lựa chọn của người dùng
int printMenu(const char* options[], int numOptions) {
    int Luachon;

    printf("===== Menu =====\n");
    for (int i = 0; i < numOptions; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }

    // Nhập lựa chọn của người dùng
    printf("Vui lòng nhập lựa chọn của bạn (1-%d): ", numOptions);
    scanf("%d", &Luachon);

    // Kiểm tra xem lựa chọn có hợp lệ không
    while (Luachon < 1 || Luachon > numOptions) {
        printf("Lựa chọn không hợp lệ. Vui lòng nhập lại (1-%d): ", numOptions);
        scanf("%d", &Luachon);
    }

    return Luachon; // Trả về lựa chọn của người dùng
}

int main() {
    // Tạo mảng chứa các lựa chọn của menu
    const char* menuOptions[] = {
        "Kem",
        "Kẹo",
        "Bánh",
        "Thoát"
    };

    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
    int choice = printMenu(menuOptions, numOptions);

    // Hiển thị lựa chọn của người dùng
    printf("Bạn đã chọn: %s\n", menuOptions[choice - 1]);

    return 0;
}