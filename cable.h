#ifndef CABLE_H
#define CABLE_H

// Структура для хранения информации о кабелях
typedef struct
{
    int cab_id;           // ID Кабеля
    char cab_name[30];    // Название кабеля
    char cab_connect[40]; // Разъём кабеля (подключение)
    double cab_price;     // Цена кабеля
} CABLE;

#endif // CABLE_H
