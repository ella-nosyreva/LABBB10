#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float area_rhombus(float d1, float d2);
void definition_rhombus();
void draw_rhombus(int size, char symbol);

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;
    float d1, d2, area;
    int size;
    char symbol;

    do
    {
        printf("\n=== МЕНЮ (Фигура: Ромб) ===\n");
        printf("1. Рассчитать площадь\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Введите первую диагональ ромба: ");
            scanf("%f", &d1);
            printf("Введите вторую диагональ ромба: ");
            scanf("%f", &d2);
            area = area_rhombus(d1, d2);
            printf("Площадь ромба: %.2f\n", area);
            break;

        case 2:
            definition_rhombus();
            break;

        case 3:
            printf("Введите размер ромба (например, 4): ");
            scanf("%d", &size);
            printf("Введите символ для рисования: ");
            scanf(" %c", &symbol);
            draw_rhombus(size, symbol);
            break;

        case 0:
            printf("Выход из программы.\n");
            break;

        default:
            printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}

float area_rhombus(float d1, float d2)
{
    return (d1 * d2) / 2.0;
}

void definition_rhombus()
{
    printf("\nРомб — это параллелограмм, у которого все стороны равны.\n");
    printf("Площадь ромба равна половине произведения его диагоналей.\n");
}

void draw_rhombus(int size, char symbol)
{
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++) printf(" ");
        for (int j = 0; j < 2 * i + 1; j++) printf("%c", symbol);
        printf("\n");
    }

    for (int i = size - 2; i >= 0; i--)
    {
        for (int j = 0; j < size - i - 1; j++) printf(" ");
        for (int j = 0; j < 2 * i + 1; j++) printf("%c", symbol);
        printf("\n");
    }
    printf("\n");
}