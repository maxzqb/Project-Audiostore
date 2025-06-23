#ifndef DAC_H
#define DAC_H

// Структура для хранения информации о источниках
typedef struct
{
    int dac_id;        // ID Источника
    char dac_name[30]; // Название источника
    char dac_type[30]; // Тип источника
    double dac_price;  // Цена источника
} DAC;

#endif // DAC_H
