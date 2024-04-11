/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

/**********.*****.**************************:-******-:*******************
**********......:*****************+@%@*+#@@@+.****.***********************
...------........-*+*********+%#####@@@##########*************************
********:........----------%@#####################@@-...............------
**********......:********@%#####@###################@#@=+***************::
*********.:****--******%##@#####@#######################@*+***************
********.*******:-**+@@####@#@@@#################@#########=**************
*******-*********:*@@@######@###############################=*************
*****--**********%%@##@########@#############################=:***********
****.************+##################@#@@#####################@************
***.*************%######################@@###################=***********-
*-:**************=##########@@%%%%=%@=%=%=%@################@@**********.*
.****************########%++***+++****+++=+===+++***+=%@######%*******:-**
****************+#######%+*::::::::::::***********:::::**@@###%******.:***
****************#######@%*:::::::::::::::*:*****:::::::::*@@##@*****.*****
****************######@%+*:::::::-::::::::::::::::::::::::=@##%****-******
.......-------:*######=::::::----------:::::::::::::::::::+###:**--*******
............:==:%####=:::::----:-:::::::::::::::::::::::::=@##:-.:********
************=@++*%##@::::*=%%%@@###@=***::::::::::::::::::=@#@*..*********
************=**+@+@#*:::**+++%@#@###%@%%+*::*+=======*::::*##-:**.********
*************:=%%:%*::::*+=%##%###=@@@%=*::*=%@@@%%@@#@%::+#@:****.*******
:**************==:=:::--::::*++++=%@@@%*:--*%#@####@#=+***@@%@*****.******
--**************:-*::--------::**+***:::---*+%%%%%%@@%+*::#*@%******.*****
*:-************---*::::-----------::--:---::::+++++**:::::%*%********-:***
**:.************++*:::::--------::**+------::::::::::::::*++**********--**
****.**************::::::-----::**==:-------+*:::::---:::**************:-*
*****.***********.*::::::::-:::***:*+@**::**=+*::::::::::****************-
******.*:*%@######+::::::::::::::::::++++=******::::::::******************
******:############*::::::::****::::::*+*:*:*:***::::::*******************
******#############***::*:*:*+==@@##=======:*+***:::*:********************
******#############:*+**********:*++**+**++=%=***:*::*********************
.....##############::*++**************+***:*********###+******************
***:##############@*:**+=***:::**++===++***********#####%.................
*:*###############******++=+*:::::::*:::::*::***#########=****************
**:################%*****++==++********::::*+++=##########+***************
*:%##################******++++==+=++++++++++++@############**************
######################@******+++++++++++++++++=%#############*************
########################+++++++++++++++++++++==@#############@***********.
#########################%+++++++++++++++++===%###############%********:-*
########################@=#=++++++++++++====%@##################******-**/

#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endd "\n"; return 0;
#define all(v) v.begin(), v.end()

using namespace std;

const int MAXN = 1e5;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int kok(bitset<20> mask, int input) {
    for (int i = 0; i < input; i++) {
        if (mask[i]) {
            bitset<20> kek;
            kek[i + 1] = 1;
            return kek.to_ulong();
        }
    }
    int kek = input;
    while (mask[kek]) {
        mask[kek] = 0;
        kek++;
    }
    mask[kek] = 1;
    return mask.to_ulong();
}

class Task {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, k;
        in >> n >> k;
        vc<int> dp(1 << k, 0);
        dp[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            in >> x;
            vc<int> kekes(1 << k, 0);
            pr<int, int> mem = mp(1, 2);
            if (x == 0) {
                ans *= 2;
                ans %= MOD;
            } else {
                mem = mp(x / 2, x / 2);
            }
            for (int kek = mem.fs; kek <= mem.sc; kek++) {
                for (int j = 0; j < (1 << k); j++) {
                    if (kok(j, kek) >= (1 << k)) {
                        ans += dp[j];
                        ans %= MOD;
                    } else {
                        kekes[kok(j, kek)] += dp[j];
                        kekes[kok(j, kek)] %= MOD;
                    }
                }
            }
            dp = kekes;
        }
        out << ans;
    }
};


main() {
    Task solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}