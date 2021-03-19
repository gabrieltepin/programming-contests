#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	double Ds, Dt, D;
	cin >> T;
	while(T--){
		cin >> Ds >> Dt >> D;
		if(Ds<=Dt)swap(Ds, Dt); // Ds>=Dt
		cout << fixed;
		if(D>Ds+Dt) cout << setprecision(7) << D - Ds - Dt << "\n";
		else if (D+Dt<Ds) cout << setprecision(7) << Ds - D - Dt << "\n";
		else cout << 0.0000000 << "\n";
	}
	return 0;
}