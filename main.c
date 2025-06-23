/*
Программа для работы с каталогом аудио магазина: наушники, кабели и источники.  
Позволяет сортировать, фильтровать, выводить и собирать готовые наборы устройств.  
Данные загружаются из текстовых файлов и сохраняются в список.
Выполнил студент 301ИС-22 Минаев Максим

Основные возможности программы:
1. Загрузка данных из файлов headphones.txt, cables.txt и dacs.txt.
2. Сортировка устройств по ID или цене.
3. Фильтрация наушников по типу (Open, Closed, IEM).
4. Вывод списка всех устройств или отдельных категорий.
5. Формирование готовых наборов (наушники + кабель + источник) и сохранение их в файл set.txt.
6. Простое и понятное меню для выбора функций программы.
*/

#include <stdio.h>
#include "func.h"
#include "func.c"

#define MAX_ITEMS 10

// Функция для вывода меню
void print_menu(void)
{
    printf("\nМеню:\n");
    printf("1. Сортировать наушники по ID\n");
    printf("2. Сортировать наушники по стоимости\n");
    printf("3. Фильтровать наушники по типу\n");
    printf("4. Сортировать кабели по ID\n");
    printf("5. Сортировать кабели по стоимости\n");
    printf("6. Сортировать источники по ID\n");
    printf("7. Сортировать источники по стоимости\n");
    printf("8. Вывести список наушников\n");
    printf("9. Вывести список кабелей\n");
    printf("10. Вывести список источников\n");
    printf("11. Сохранить готовые наборы\n");
    printf("0. Выход\n");
    printf("Выберите пункт меню: ");
}

/*
Основная функция программы.
Загружает данные из текстовых файлов для наушников, кабелей и источников.
Позволяет сортировать, фильтровать, выводить и сохранять данные через меню.
Сохраняет результат в set.txt.
*/
int main(void)
{
    HEADPHONES headphones[MAX_ITEMS];
    CABLE cables[MAX_ITEMS];
    DAC dacs[MAX_ITEMS];

    FILE *set = fopen("set.txt", "w");
    if (!set)
    {
        printf("Ошибка открытия файла set.txt");
        return 1;
    }

    int h = load_headphones(headphones);
    int c = load_cables(cables);
    int d = load_dacs(dacs);

    int choice;
    do
    {
        print_menu();
        if (scanf("%d", &choice) != 1)
        {
            printf("\nНеверный ввод!\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            // Сортировка наушников по ID и вывод результата
            sort_headp_by_id(headphones, h);
            printf("\nНаушники отсортированы по ID:\n");
            print_all_headphones(headphones, h);
            break;

        case 2:
            // Сортировка наушников по цене и вывод результата
            sort_headp_by_price(headphones, h);
            printf("\nНаушники отсортированы по цене:\n");
            print_all_headphones(headphones, h);
            break;

        case 3:
            // Фильтрация наушников по типу
            filt_headphones_by_type(headphones, h);
            break;

        case 4:
            // Сортировка кабелей по ID и вывод результата
            sort_cable_by_id(cables, c);
            printf("\nКабели отсортированы по ID:\n");
            print_all_cables(cables, c);
            break;

        case 5:
            // Сортировка кабелей по цене и вывод результата
            sort_cable_by_price(cables, c);
            printf("\nКабели отсортированы по цене:\n");
            print_all_cables(cables, c);
            break;

        case 6:
            // Сортировка источников по ID и вывод результата
            sort_dac_by_id(dacs, d);
            printf("\nИсточники отсортированы по ID:\n");
            print_all_dacs(dacs, d);
            break;

        case 7:
            // Сортировка источников по цене и вывод результата
            sort_dac_by_price(dacs, d);
            printf("\nИсточники отсортированы по цене:\n");
            print_all_dacs(dacs, d);
            break;

        case 8:
            // Вывод списка всех наушников
            print_all_headphones(headphones, h);
            break;

        case 9:
            // Вывод списка всех кабелей
            print_all_cables(cables, c);
            break;

        case 10:
            // Вывод списка всех источников
            print_all_dacs(dacs, d);
            break;

        case 11:
            // Сохранение собранных данных в set.txt
            save_set(set, headphones, h, cables, c, dacs, d);
            printf("\nНаборы сохранены в файл set.txt\n");
            break;

        case 0:
            // Выход из программы
            printf("\nВы вышли из программы.\n");
            break;

        default:
            printf("\nНеверный ввод.\n");
        }
    } while (choice != 0);

    fclose(set);
    return 0;
}
