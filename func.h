/*
Заголовочный файл func.h объявляет функции для:

- Загрузки данных из файлов
- Сортировки данных (по ID, цене)
- Вывода данных
- Дополнительно для Наушников — фильтрации данных по типу
- Сохранения готовых наборов в файл

Обеспечивает полный цикл работы с данными:
загрузка, обработка (сортировка, фильтрация), вывод и сохранение.
*/

#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <string.h>
#include "head.h"
#include "cable.h"
#include "dac.h"

// Загружает список наушников из файла в массив
int load_headphones(HEADPHONES arr[]);

// Загружает список кабелей из файла в массив
int load_cables(CABLE arr[]);

// Загружает список источников из файла в массив
int load_dacs(DAC arr[]);

// НАУШНИКИ
// Выводит информацию об одних конкретных наушниках
void print_headph(const HEADPHONES *hedp);

// Выводит список всех наушников из массива
void print_all_headphones(const HEADPHONES arr[], int n);

// Сортирует массив наушников по ID
void sort_headp_by_id(HEADPHONES arr[], int n);

// Сортирует массив наушников по цене
void sort_headp_by_price(HEADPHONES arr[], int n);

// Фильтрует и выводит только наушники определённого типа (IEM, Open, Closed)
void filt_headphones_by_type(const HEADPHONES arr[], int n);

// КАБЕЛИ
// Выводит информацию об одном конкретном кабеле
void print_cable(const CABLE *cab);

// Выводит список всех кабелей из массива
void print_all_cables(const CABLE arr[], int n);

// Сортирует массив кабелей по ID
void sort_cable_by_id(CABLE arr[], int n);

// Сортирует массив кабелей по цене
void sort_cable_by_price(CABLE arr[], int n);

// ИСТОЧНИКИ
// Выводит информацию об одном конкретном источнике
void print_dac(const DAC *dac);

// Выводит список всех источников из массива
void print_all_dacs(const DAC arr[], int n);

// Сортирует массив источников по ID
void sort_dac_by_id(DAC arr[], int n);

// Сортирует массив источников по цене
void sort_dac_by_price(DAC arr[], int n);

// СОХРАНЕНИЕ НАБОРА
// Сохраняет набор устройств (наушники, кабели, источники) с одинаковыми ID в указанный файл
// Для каждого набора подсчитывается общая цена
void save_set(FILE *set,
              const HEADPHONES headph[], int num_hp,
              const CABLE cables[], int num_cb,
              const DAC dacs[], int num_dc);

#endif // FUNC_H
