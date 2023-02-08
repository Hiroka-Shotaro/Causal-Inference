#include <stdio.h>

void get_params(double*, double*, double*, double*);
void CoupledLogistic(double*, double*, double, double, double, double);
void Get_vectors(double [999][2], double [999][2], double*, double*);

int main(void){
    // 利用する時系列の器を作成
    double x[1000]; // 時系列
    double y[1000]; // 時系列
    double rx = 0.0; // 自分からの影響度
    double ry = 0.0; // 自分からの影響度
    double betha_xy = 0.0; // 相手からの影響度
    double betha_yx = 0.0; // 相手からの影響度

    // パラメータを得る
    get_params(&rx, &ry, &betha_xy, &betha_yx);

    //　時系列の初期値を入力
    x[0] = 0.2;
    y[0] = 0.4;

    
    /// coupled_logistic式の時間発展の計算をする
    CoupledLogistic(x, y, rx, ry, betha_xy, betha_yx);
    
    // 時間遅れベクトルの初期化
    double Mx[999][2];
    double My[999][2];
    
    
    // 時間遅れベクトルの生成
    Get_vectors(Mx, My, x, y);


    return 0;
}

// coupled_logistic式のパラメータを設定する.
void get_params(double* rx, double* ry, double* betha_xy, double* betha_yx){

    /// パラメータを設定する
    printf("[ パラメータの設定をします ] \n");
    printf("rx : ");
    scanf("%lf", rx);
    printf("ry : ");
    scanf("%lf", ry);
    printf("betha_xy : ");
    scanf("%lf", betha_xy);
    printf("betha_yx : ");
    scanf("%lf", betha_yx);
    printf("#################\n");
    // パラメータを表示
    printf("設定したパラメータ : rx : %.2f, ry : %.2f, betha_xy : %.2f, betha_yx : %.2f \n", *rx, *ry, *betha_xy, *betha_yx);

}

// coubled_logistic式の時間発展を計算する
void CoupledLogistic(double* x, double* y, double rx, double ry, double betha_xy, double betha_yx){
    for(int i =0;i < 1000;i++){
        x[i+1] = x[i]*(rx - rx*x[i] - betha_xy*y[i]);
        y[i+1] = y[i]*(ry - ry*y[i] - betha_yx*x[i]);
    }

}

void Get_vectors(double Mx[999][2], double My[999][2], double* x, double* y){
    // 状態空間に時系列を埋め込む
    for(int i =1; i < 999;i++){
        /// Mxの状態空間に埋め込みを行う
        //*(Mx + (i*999))     = *(x + i);
        //*(Mx + (i*999) + 1) = *(x + i -1);
        Mx[i][0] = x[i];
        Mx[i][1] = x[i-1];
        /// Myの状態空間に埋め込みを行う
        //*(My + (i*999))     = *(y + i);
        //*(My + (i*999) + 1) = *(y + i -1);
        My[i][0] = y[i];
        My[i][1] = y[i-1];

    }
}