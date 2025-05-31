#include <iostream>
#include <random>
#include <cmath>
using namespace std;
int main() {
    const int trials = 1000000;  // 針を投げる回数
    const double needleLength = 1.0;
    const double lineSpacing = 2.0;  // L <= D を満たすように

    int count = 0;  // 線と交差した回数

   random_device rd;
   mt19937 gen(rd());
   uniform_real_distribution<> distX(0.0, lineSpacing / 2.0);  // 中心位置（最寄りの線からの距離）
   uniform_real_distribution<> distTheta(0.0, M_PI / 2.0);     // 角度（0〜π/2）

    for (int i = 0; i < trials; ++i) {
        double y = distX(gen);          // 中心から最寄り線までの距離
        double theta = distTheta(gen);  // 角度

        // sin(θ)によって針の半分の長さがどれだけ垂直方向に伸びるか
        double reach = (needleLength / 2.0) * sin(theta);

        if (y <= reach) {
            count++;
        }
    }

    
        double estimatedPi = (2.0 * needleLength * trials) / (lineSpacing * count);
        cout << "推定されるπの値: " << estimatedPi << endl;

    return 0;
}
