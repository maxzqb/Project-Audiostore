#ifndef HEAD_H
#define HEAD_H

// Структура для хранения информации о наушниках
typedef struct
{
    int h_id;           // ID наушников
    char h_name[40];    // Название наушников
    char h_type[30];    // Тип наушников
    char h_connect[30]; // Тип соединения
    double h_price;     // Цена наушников
} HEADPHONES;

#endif // HEAD_H
