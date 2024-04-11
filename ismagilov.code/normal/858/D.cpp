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

const int MAXN = 6e6;
const int INF = 1e18;
const int MOD = 1e9 + 7;


class TaskD {
public:
    void solve(std::istream &in, std::ostream &out) {
        unordered_set<int> numbers;
        unordered_set<int> numberser;
        unordered_map<int, int> kek;
        int n;
        in >> n;
        for (int i = 0; i < n; i++) {
            unordered_set<int> nu;
            int kk;
            in >> kk;
            int a[9];
            for (int j = 0; j < 9; j++) {
                a[8 - j] = kk % 10;
                kk /= 10;
            }
            int k;
            bool prav;
            for (int j = 0; j < 9; j++) {
                k = a[j];
                prav = 0;
                if (k == 0) {
                    k = 1000000000;
                    prav = 1;
                }
                if (numberser.find(k) == numberser.end()) {
                    nu.insert(k);
                }
                for (int d = j + 1; d < 9; d++) {
                    k += (k % 1000000000) * 9;
                    if (a[d] == 0) {
                        if (prav) {
                            k += 1000000000;
                        }
                    } else {
                        prav = 0;
                        k += a[d];
                    }
                    if (numberser.find(k) == numberser.end()) {
                        nu.insert(k);
                    }
                }
            }
            for (auto v : nu) {
                if (numbers.find(v) == numbers.end()) {
                    numbers.insert(v);
                } else {
                    numbers.erase(v);
                    numberser.insert(v);
                }
                kek[v] = i;
            }
        }
        pr<int, int> ans[n];
        for (int i = 0; i < n; i++) {
            ans[i] = mp(1000000000, -1);
        }
        for (auto v : numbers) {
            int v1 = v;
            int kol = v1 / 1000000000;
            v1 %= 1000000000;
            while (v1 > 0) {
                kol++;
                v1 /= 10;
            }
            int dd = kek[v];
            ans[dd] = min(ans[dd], mp(kol, v));
        }
        for (int j = 0; j < n; j++) {
            if (ans[j].sc == -1) {
                out << ans[j].sc;
            } else {
                for (int i = 0; i < ans[j].sc / 1000000000; i++) {
                    out << 0;
                }
                if (ans[j].sc % 1000000000 > 0) {
                    out << ans[j].sc % 1000000000;
                }
            }
            out << endl;
        }
    }
};


main() {
    ios_base::sync_with_stdio(0);
    TaskD solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}