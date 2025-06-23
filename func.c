/*
Файл func.c содержит реализацию всех функций, объявленных в func.h
*/

#include <stdio.h>
#include <string.h>
#include "func.h"

// Функции для НАУШНИКОВ
// Загрузка данных из файла headphones.txt в массив
int load_headphones(HEADPHONES arr[])
{
    FILE *hp = fopen("headphones.txt", "r");
    if (!hp)
    {
        printf("Ошибка открытия файла наушников");
        return 0;
    }
    int count = 0;
    while (fscanf(hp, "%d %s %s %s %lf",
                  &arr[count].h_id, arr[count].h_name,
                  arr[count].h_type, arr[count].h_connect, &arr[count].h_price) == 5)
    {
        count++;
    }
    fclose(hp);
    return count;
}

// Вывод информации об одних конкретных наушниках
void print_headph(const HEADPHONES *hedp)
{
    printf("----НАУШНИКИ----\n");
    printf("ID: %d\nНазвание: %s\nТип: %s\nСоединение: %s\nЦена: %.2f\n",
           hedp->h_id, hedp->h_name, hedp->h_type, hedp->h_connect, hedp->h_price);
    printf("----------------\n");
}

// Вывод информации обо всех наушниках из массива
void print_all_headphones(const HEADPHONES arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        print_headph(&arr[i]);
    }
}

// Сортировка массива наушников по ID
void sort_headp_by_id(HEADPHONES arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].h_id > arr[j + 1].h_id)
            {
                HEADPHONES temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Сортировка массива наушников по цене
void sort_headp_by_price(HEADPHONES arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].h_price > arr[j + 1].h_price)
            {
                HEADPHONES temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Фильтрация массива наушников по введённому типу
void filt_headphones_by_type(const HEADPHONES arr[], int n)
{
    char s_type[50];
    printf("Введите тип наушников (Open, Closed, IEM): ");
    scanf("%s", s_type);

    int found = 0;
    printf("\nНаушники типа %s:\n", s_type);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].h_type, s_type) == 0)
        {
            print_headph(&arr[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Нет наушников с таким типом.\n");
    }
}

// Сохранение готовых наборов (наушники, кабель, источник)
// Ищет позиции с одинаковыми ID и сохраняет в файл set.txt
void save_set(FILE *set, const HEADPHONES headph[], int num_hp,
              const CABLE cables[], int num_cb,
              const DAC dacs[], int num_dc)
{
    for (int id = 1; id < 10; id++)
    {
        const HEADPHONES *h = NULL;
        const CABLE *c = NULL;
        const DAC *d = NULL;

        for (int i = 0; i < num_hp; i++)
            if (headph[i].h_id == id)
                h = &headph[i];
        for (int i = 0; i < num_cb; i++)
            if (cables[i].cab_id == id)
                c = &cables[i];
        for (int i = 0; i < num_dc; i++)
            if (dacs[i].dac_id == id)
                d = &dacs[i];

        if (h && c && d)
        {
            double total = h->h_price + c->cab_price + d->dac_price;

            fprintf(set, "НАБОР ID: %d\n", id);
            fprintf(set, "Наушники: %s\n", h->h_name);
            fprintf(set, "Кабель: %s\n", c->cab_name);
            fprintf(set, "Источник: %s\n", d->dac_name);
            fprintf(set, "Общая стоимость: %.2f\n", total);
            fprintf(set, "-----------------------------\n");
        }
    }
}

// Функции для КАБЕЛЕЙ
// Загрузка данных из файла cables.txt в массив
int load_cables(CABLE arr[])
{
    FILE *cb = fopen("cables.txt", "r");
    if (!cb)
    {
        printf("Ошибка открытия файла кабелей");
        return 0;
    }
    int count = 0;
    while (fscanf(cb, "%d %s %s %lf",
                  &arr[count].cab_id, arr[count].cab_name,
                  arr[count].cab_connect, &arr[count].cab_price) == 4)
    {
        count++;
    }
    fclose(cb);
    return count;
}

// Вывод информации об одном кабеле
void print_cable(const CABLE *cab)
{
    printf("----КАБЕЛЬ----\n");
    printf("ID: %d\nНазвание кабеля: %s\nПодключение кабеля: %s\nЦена: %.2f\n",
           cab->cab_id, cab->cab_name, cab->cab_connect, cab->cab_price);
    printf("--------------\n");
}

// Вывод информации обо всех кабелях из массива
void print_all_cables(const CABLE arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        print_cable(&arr[i]);
    }
}

// Сортировка массива кабелей по ID
void sort_cable_by_id(CABLE arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].cab_id > arr[j + 1].cab_id)
            {
                CABLE temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Сортировка массива кабелей по цене
void sort_cable_by_price(CABLE arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].cab_price > arr[j + 1].cab_price)
            {
                CABLE temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Функции для ИСТОЧНИКОВ
// Загрузка данных из файла dacs.txt в массив
int load_dacs(DAC arr[])
{
    FILE *dc = fopen("dacs.txt", "r");
    if (!dc)
    {
        printf("Ошибка открытия файла источников");
        return 0;
    }
    int count = 0;
    while (fscanf(dc, "%d %s %s %lf",
                  &arr[count].dac_id, arr[count].dac_name,
                  arr[count].dac_type, &arr[count].dac_price) == 4)
    {
        count++;
    }
    fclose(dc);
    return count;
}

// Вывод информации об одном источнике
void print_dac(const DAC *dac)
{
    printf("----ИСТОЧНИК----\n");
    printf("ID: %d\nНазвание источника: %s\nТип источника: %s\nЦена: %.2f\n",
           dac->dac_id, dac->dac_name, dac->dac_type, dac->dac_price);
    printf("----------------\n");
}

// Вывод информации обо всех источниках из массива
void print_all_dacs(const DAC arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        print_dac(&arr[i]);
    }
}

// Сортировка массива источников по ID
void sort_dac_by_id(DAC arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].dac_id > arr[j + 1].dac_id)
            {
                DAC temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Сортировка массива источников по цене
void sort_dac_by_price(DAC arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].dac_price > arr[j + 1].dac_price)
            {
                DAC temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
