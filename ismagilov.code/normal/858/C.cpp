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

class TaskC {
public:
    void solve(std::istream &in, std::ostream &out) {
        string s;
        set<int> opech;
        in >> s;
        int kol = 0;
        bool same = 1;
        for (int i = 0; i < len(s); i++) {
            if ((s[i] != 'a') && (s[i] != 'e') && (s[i] != 'i') && (s[i] != 'o') && (s[i] != 'u')) {
                kol++;
                if (kol > 1) {
                    if (s[i - 1] != s[i]) {
                        same = 0;
                    }
                }
                if (!same && kol >= 3) {
                    opech.insert(i);
                    same = 1;
                    kol = 1;
                }
            } else {
                kol = 0;
                same = 1;
            }
        }
        for (int i = 0; i < len(s); i++) {
            if (opech.find(i) != opech.end()) {
                out << ' ';
            }
            out << s[i];
        }
    }
};


main() {
    ios_base::sync_with_stdio(0);
    TaskC solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}