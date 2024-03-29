#include <stdio.h>

#define MIN_F 10  // 最小注射次数
#define MAX_F 180 // 最大注射次数
#define FADD 10   // 每次递增

// 定义注射器容量
#define SYRV_1ML 1
#define SYRV_3ML 3
#define SYRV_5ML 5

// 注射剂量结构体
typedef struct
{
    float medv; // 实际药液容量
    int syrv;   // 注射器容量
} Syringe_Case;

// 计算单次注射剂量
float calculate_singe(float medv, int num_injections)
{
    return medv / num_injections;
}

// 输出所有可能的组合及其单次注射剂量
void printf_allplan(Syringe_Case syringe[], int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = MIN_F; j <= MAX_F; j += FADD)
        {
            printf("实际药物容量/注射器容量: %.1f/%dml  注射次数: %d\n", syringe[i].medv, syringe[i].syrv, j);
            printf("单次注射量: %f ml\n\n", calculate_singe(syringe[i].medv, j));
        }
        printf("-------------------------------------------------------\n");
    }
}

int main()
{

    // 列举注射剂量
    Syringe_Case syringes[] = {
        {0.8, SYRV_1ML},
        {2.0, SYRV_3ML},
        {3.0, SYRV_3ML},
        {4.0, SYRV_5ML},
        {5.0, SYRV_5ML}
};

    int num = sizeof(syringes) / sizeof(syringes[0]);

    // 输出所有可能的组合及其单次注射剂量
    printf_allplan(syringes, num);

    return 0;
}
