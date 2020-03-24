//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////注：约定保留一位小数
//
//typedef struct ComplexType {
//    float realPart, imagePart;
//} ComplexType;
//
//void add(ComplexType z1, ComplexType z2) {
//    float z = z1.realPart + z2.realPart;
//    float zz = z1.imagePart + z2.imagePart;
//    if (zz < 0)
//    {
//        printf("相加：%.1f %.1fi\n", z, zz);
//        return;
//    }
//    printf("相加：%.1f + %.1fi\n", z, zz);
//}
//
//void sub(ComplexType z1, ComplexType z2) {
//    float z = z1.realPart - z2.realPart;
//    float zz = z1.imagePart - z2.imagePart;
//    if (zz < 0)
//    {
//        printf("相减：%.1f %.1fi\n", z, zz);
//        return;
//    }
//    printf("相减：%.1f + %.1fi\n", z, zz);
//}
//
//void mul(ComplexType z1, ComplexType z2) {
//    float z = z1.realPart * z2.realPart;
//    float zz = z1.imagePart * z2.imagePart;
//    if (zz < 0)
//    {
//        printf("相乘：%.1f %.1fi\n", z, zz);
//        return;
//    }
//    printf("相乘：%.1f + %.1fi\n", z, zz);
//}
//
//void getRealPart(ComplexType z) {
//    printf("该复数的实部是：%.1f\n",z.realPart);
//}
//
//void getImagelPart(ComplexType z) {
//    printf("该复数的虚部是：%.1f\n", z.imagePart);
//}
//
//int main2(void) {
//    int bool = 1;
//    ComplexType z1, z2;
//    z1.imagePart = 0;
//    z1.realPart = 0;
//    z2.imagePart = 0;
//    z2.realPart = 0;
//
//    while (bool)
//    {
//        printf("---------菜单----------\n");
//        printf("| 1.相加               |\n");
//        printf("| 2.相减               |\n");
//        printf("| 3.相乘               |\n");
//        printf("| 4.取实部             |\n");
//        printf("| 5.取虚部             |\n");
//        printf("| 6.退出本程序         |\n");
//        printf("-----------------------  请选择您要做的复数操作：");
//
//        int n;
//        scanf("%d", &n);
//        switch (n)
//        {
//        case 1:
//            printf("请先输入两个复数：\n");
//            printf("复数1：");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            printf("复数2：");
//            scanf("%f%f", &z2.realPart, &z2.imagePart);
//            add(z1, z2);
//            break;
//        case 2:
//            printf("请先输入两个复数：\n");
//            printf("复数1：");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            printf("复数2：");
//            scanf("%f%f", &z2.realPart, &z2.imagePart);
//            sub(z1, z2);
//            break;
//        case 3:
//            printf("请先输入两个复数：\n");
//            printf("复数1：");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            printf("复数2：");
//            scanf("%f%f", &z2.realPart, &z2.imagePart);
//            mul(z1, z2);
//            break;
//        case 4:
//            printf("请输入一个复数：");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            getRealPart(z1);
//            break;
//        case 5:
//            printf("请输入一个复数：");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            getImagelPart(z1);
//            break;
//        case 6:
//            bool = 0;
//            break;
//        default:
//            printf("输入有误！");
//        }
//    }
//
//    printf("已退出本程序！");
//    return 0;
//}