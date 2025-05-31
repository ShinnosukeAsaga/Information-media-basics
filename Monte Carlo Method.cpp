#include <iostream>   
#include <cstdlib>   
#include <ctime>      
#include <cmath>      
using namespace std;

int main() {
    const int total_points = 100000000;  // シミュレーションする点の総数（大きいほど精度が上がる）
    int points_inside_circle = 0;        // 円の内側に入った点の数をカウントする変数

    // 現在時刻を使って乱数の種を初期化（毎回異なる乱数列にするため）
    srand(static_cast<unsigned>(std::time(0)));

    for (int i = 0; i < total_points; ++i) {
        // 0〜1の範囲の乱数を生成してx, y座標とする
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;

        // 点 (x, y) が原点からの距離が1以下なら、単位円の内側にある
        if (x * x + y * y <= 1.0) {
            ++points_inside_circle;  // 円の内側にある点としてカウント
        }
    }

    // πの近似値を計算（円の面積 / 正方形の面積 = π / 4 より）
    double pi_estimate = 4.0 * points_inside_circle / total_points;

    // 近似されたπの値を表示
    cout << "近似されたπの値: " << pi_estimate << std::endl;

    return 0;  
}
