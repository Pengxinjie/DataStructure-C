//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////ע��Լ������һλС��
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
//        printf("��ӣ�%.1f %.1fi\n", z, zz);
//        return;
//    }
//    printf("��ӣ�%.1f + %.1fi\n", z, zz);
//}
//
//void sub(ComplexType z1, ComplexType z2) {
//    float z = z1.realPart - z2.realPart;
//    float zz = z1.imagePart - z2.imagePart;
//    if (zz < 0)
//    {
//        printf("�����%.1f %.1fi\n", z, zz);
//        return;
//    }
//    printf("�����%.1f + %.1fi\n", z, zz);
//}
//
//void mul(ComplexType z1, ComplexType z2) {
//    float z = z1.realPart * z2.realPart;
//    float zz = z1.imagePart * z2.imagePart;
//    if (zz < 0)
//    {
//        printf("��ˣ�%.1f %.1fi\n", z, zz);
//        return;
//    }
//    printf("��ˣ�%.1f + %.1fi\n", z, zz);
//}
//
//void getRealPart(ComplexType z) {
//    printf("�ø�����ʵ���ǣ�%.1f\n",z.realPart);
//}
//
//void getImagelPart(ComplexType z) {
//    printf("�ø������鲿�ǣ�%.1f\n", z.imagePart);
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
//        printf("---------�˵�----------\n");
//        printf("| 1.���               |\n");
//        printf("| 2.���               |\n");
//        printf("| 3.���               |\n");
//        printf("| 4.ȡʵ��             |\n");
//        printf("| 5.ȡ�鲿             |\n");
//        printf("| 6.�˳�������         |\n");
//        printf("-----------------------  ��ѡ����Ҫ���ĸ���������");
//
//        int n;
//        scanf("%d", &n);
//        switch (n)
//        {
//        case 1:
//            printf("������������������\n");
//            printf("����1��");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            printf("����2��");
//            scanf("%f%f", &z2.realPart, &z2.imagePart);
//            add(z1, z2);
//            break;
//        case 2:
//            printf("������������������\n");
//            printf("����1��");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            printf("����2��");
//            scanf("%f%f", &z2.realPart, &z2.imagePart);
//            sub(z1, z2);
//            break;
//        case 3:
//            printf("������������������\n");
//            printf("����1��");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            printf("����2��");
//            scanf("%f%f", &z2.realPart, &z2.imagePart);
//            mul(z1, z2);
//            break;
//        case 4:
//            printf("������һ��������");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            getRealPart(z1);
//            break;
//        case 5:
//            printf("������һ��������");
//            scanf("%f%f", &z1.realPart, &z1.imagePart);
//            getImagelPart(z1);
//            break;
//        case 6:
//            bool = 0;
//            break;
//        default:
//            printf("��������");
//        }
//    }
//
//    printf("���˳�������");
//    return 0;
//}