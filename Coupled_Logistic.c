#include <stdio.h>

int main(void){
    // 利用する時系列の器を作成
    double x[1000];
    double y[1000];
    double rx = 0.0;
    double ry = 0.0;
    double betha_xy = 0.0;
    double betha_yx = 0.0;

    // パラメータを設定する
    printf("[ パラメータの設定をします ] \n");
    printf("rx : ");
    scanf("%lf", &rx);
    printf("ry : ");
    scanf("%lf", &ry);
    printf("betha_xy : ");
    scanf("%lf", &betha_xy);
    printf("betha_yx : ");
    scanf("%lf", &betha_yx);
    printf("#################\n");

    // パラメータを表示
    printf("設定したパラメータ : rx : %.2f, ry : %.2f, betha_xy : %.2f, betha_yx : %.2f \n", rx, ry, betha_xy, betha_yx);

    // 時間発展をさせる
    x[0] = 0.2;
    y[0] = 0.4;
    for(int i =0;i < 1000;i++){
        x[i+1] = x[i]*(rx - rx*x[i] - betha_xy*y[i]);
        y[i+1] = y[i]*(ry - ry*y[i] - betha_yx*x[i]);
    }
    
    
    return 0;
}