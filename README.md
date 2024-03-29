#### 思路

先定义注射剂量结构体
```
typedef struct
{
    float medv; // 实际药液容量
    int syrv;   // 注射器容量
} Syringe_Case;
```
该结构体负责表示每种注射剂量（实际药液容量/注射器容量）
然后在主循环定义该结构体数组，录入每种注射剂量
```
Syringe_Case syringes[] = {
        {0.8, SYRV_1ML},
        {2.0, SYRV_3ML},
        {3.0, SYRV_3ML},
        {4.0, SYRV_5ML},
        {5.0, SYRV_5ML}
    };
```
最后写一个二层循环，外侧遍历该数组，内层遍历注射次数，求单次注射注射剂量
```
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
```
#### 运行截图
![image](https://github.com/cuberxh/syr/assets/114867144/a5a46eae-0615-4d14-a230-2e7a93fb8c04)
![Uploading image.png…]()




