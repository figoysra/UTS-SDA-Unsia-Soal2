#include <iostream>
#include <string>

class Order {
public:
    std::string food;
    int price;
    int qty;
    int total;

    void getData() {
        std::cout << food << "@" << price << " * " << qty << " = " << total << std::endl;
    }
};

class Menu {
public:
    int no;
    std::string name;
    int price;
};

int main() {
    Menu menuList[] = {
            {1, "Soto", 90000},
            {2, "Rawon", 20000},
            {3, "Pecel", 20000},
            {4, "Bakso", 12500}
    };

    const int totalMenu = sizeof(menuList) / sizeof(menuList[0]);
    Order orders[10];
    int n, totalPrice = 0;

    std::cout << "=========================" << std::endl;
    std::cout << "    LIST MAKANAN" << std::endl;
    std::cout << "=========================" << std::endl;

    for (int i = 0; i < totalMenu; ++i) {
        std::cout << menuList[i].no << " ";
        std::cout << menuList[i].name << " ";
        std::cout << menuList[i].price << " ";
        std::cout << std::endl;
    }

    std::cout << "Masukan Jumlah Pesanan: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int menuNumber, menuQty;
        std::cout << "Nomor Menu: ";
        std::cin >> menuNumber;
        std::cout << "Jumlah: ";
        std::cin >> menuQty;

        const Menu& selectedMenu = menuList[menuNumber - 1];
        orders[i].food = selectedMenu.name;
        orders[i].price = selectedMenu.price;
        orders[i].qty = menuQty;
        orders[i].total = menuQty * selectedMenu.price;

        totalPrice += orders[i].total;
    }

    std::cout<<"total harga"<<std::endl;

    for (int i = 0; i < n; ++i) {
        orders[i].getData();
    }

    std::cout << "Total =  " << totalPrice << std::endl;

    return 0;
}