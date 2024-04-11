#include <bits/stdc++.h>

using namespace std;

/*
 %%%%=%%=%=%%%%%%%%%%%%%%%%%%%%@@@%@@%%%%%%%%==%%@@@@@%%%%%%@%%%%%%%%%%%%%%%%%
%%%+%@@%%%%=%@%%%%%@@@@@@%@@@@@@%@@@@@%@%@%%%%%%@@@##@@@@%@@@@%%%%@@@%%%%%%%%
@%=+=@@@%%++%%%%%%%%%%%%%%%%%%@%=%%%%%%%%%%%%%%%%%@@@%%%%=%=@@@%%%%%==%=%%%%=
%%==%%@@%*+=%@@@@@%@@@@@@%@@@%@@%@@@@@@@%%@@@@%%%@@@@@@#@%%%@%@@%%%%%%%%%%%%%
@@==%@@%@%@%%%@@@@@@@@@@@%@@%%@%=@@@@@%%%%@@@@@@@@@@#@@@@@@@@@@@%%%@@%%%%%==%
@%%%%@@@%%@@@%@@@@@@@%%%@%%%%=+++===+====%==%@@@@@@=%@=%%=@@#@##@@@@%%%@@@%%%
@@==*@@@@@@@@@@@@@@@@@%%@===%===========++++=++=%@%==%%=@%@@@##@@#@@@%@%@%%%%
#@=+=++=%%@@@@@@@@@@@@@%====%%%=%====%=%%%====++=+%==@@=+=@@@##%%@@@%%%%%@@%@
===++*%@@#@@@@@@@@@@@@==@%%%%%%%@@@@@#@@@@@#%@#@%=+====+==@@@%+%%%%%=%%%@@@@#
%%=+==*@@%=@%@%%===@@@@#%@@@@@@@###@@##@@@@######%=====%%%@%+=+=%==%=%==@@@%%
=++++=++==+===+===%@@@@@@@################@######@%=+==%=%@+++====@%==+=%%%%%
@%=====+======+=+++%%%@@%%@%%=+******+===%%@@%%@@@@===%+%+++*%%%=%@@%==%%%==%
%%======%%=%==+==+%@@@%@@%=*::::::::::**********+%@%=========%%%%=++=====%=%#
%%%=%%%%=%====%%=====@@@@@+:::::::::::::******::*=@%==%%=%===@%%%=======%%%%@
%%=%=%%%%%====%%%%====%@@%+::::::::::::::********+@%==%%%==+%%%%%%%%=%%%%%%%=
%@%@@@%======%========%@@%*:::::::::::::::::::****=@%===%%%%%%===%%%%@=%%%=++
#@@@@%%==%%@%%=%==%=::=@@*:::::::::***:*******:::**@=:+%@%%%%%%%%%@@@@==+=+++
@@@@%%%%%%%%%=%@##@%%++%%::*==%%@@@@=***=%##@@%%=**%=%=%%%%%%=+==%@%%%%%%==%=
@%%@@@@%=@%%====%@@@=+===:*+%@@@#%%%=*:*%@%##@@@%+:====%%%%@@%+=%+%@%=%%+=%==
@@#@@@@@%#@@%@@@%%@@@+***::::*++==+**:::++====+**::++%%%===%@%%=%%%=+=%%%%===
@%%%@@@%%%%@%@%%%@@#@@+**::---::::::::::*::::::::::*=%@@%%%@%%%%@%@@@@@@%%%==
##@@@@@%@%@@@##@@@@@@@#=+:::---::*+::--::*+*::::::*+%%%%%=%@%%@@%@@@@#@@@%%%%
###@%%@@%%%%%%@##@@##@@#@*:*::**++*+=+*+=++++*****+=%%%%@%@%%@@@@@@@#@@@%%%=%
###@##@@@%%%@@####@#@##%%+****+++****+==+++++=+++*=%%=%%%@@##@@@@@%@@%%==%@@=
###@@#@@@@%%%@####@@%%@@%%****+=%%=========%=++++=%%%@@%%%@###@@@@@@@@@@@@%%%
####@@@@@@@@%@@%@====+==%%@=++++***+++=+=++++===@@%%%%=%%%@@##@@#@@###@@@@@@@
###@@@###@@@%%====++++==%%%%*+++*+==%%%%%=++====%=%%@%@@@#@@@@@%@@@#@@@@@@%%%
#########@@##%===++++=@=+==%**+++********++==++%%%%%%@@%%%@####@@@@#@##@@@%@@
#####@#@@#@%=++=++++++=%=%%%***++======%%%==+++@@==%@@@%%@@@@#%@@@@@#@@@@%@@@
###@#@###@@%====+==+++=%@%@=***+++==%%%%===+++=#@@%%%%=%@@#@##@@%@@@#@@@@@#@@
#@@%@@@###@@%==+===%%=%@@%@=*****++++===+++++=##@@@@%@@%==+=%@@@@@###@@@@%@%%
@@###@#%%=======%%%%%%%@@@@=*******+++++++*++%##@@@@%@@%@@%=====%@@@@@@@@%%%%
##@%#%===%%%%%%%%@#%%@@@@@@%*::::****++*****+@##@@@%%@@@%%@@@%=====%%%%%%%%%%
@@@===%%%%%%%%%@@##@@@@@@@#@@@%+:::::::::::*%##@@@@@@@@@%%@@@@@%%%%====%%%%%%
@===%%%%%%%@@@@###@#@@@#@@#@@@@@@@@@@@@@@@@@###@@@@@@@##@%@@@@@@%%%%%========
=%%%%%%@@@@@@@###@##@@@@@@#@@@@###@####@########@#@@@@@#@@@@#@@@@@@%%%%%%===+
%%%%@@@@@@@@####@##@@@@@@##@@@@@%@##@@@@@@@##@@#@@@@@@@#@@@@@@@@@%%@@@%%%====
@@@###@@@######@##@@@@@###@@@%@@@%%%@@@@@@@%@@@@@@@@@@@##@%##@@@@@@@@@#@@%+==
@@#####@######@##@@@@@@@+-*%=*+==%%%%%%%%@@@%@@@@@@@@@@@#@%@####@@#####@@%=++
@############@@##@@@@@@%@:%:-*++:-*%%%%%%%@@%@@@@@@@@@@@#@@@@####@######@%===
@###########@@##@@@@@@%@%%%--+%%*-:%%%%%%%%@@%@@@@@@@@@@@@@@@###########@%=+=
###############@@@@@@%@%%%%--:+%%%%%%%%%%%%@@@@@@@@@@@@@#@@@@###########@%%==
@##########@###@@@@@%@%%%%%%=*:---=%%%%%%%%%@@@@@@@@@@@@@@@@@###########@%==+
###############@@##@@@@%%%%%%%%%*-*%%%%%%%%%@@@@@@@@@@@@@@@@@###########@%%==
@#########@####@###@@@%%%%%-:=%%:-*%%%%%%%%%%@@@@@@@@@@@@#@@@###########@@%==
@########@########@:*%%@@@%--=%%:-*%%%%%%%%%%@@@@@@@@@@##@@@@###########@%%==
##################@%%@@@@@@%+*::-+%%%%@@%%%%%@@@@#@@@@##@#@@@############@%==
@#######@########%*++*++=%%%%@%@@@@@@@@@@@@@@@@###@@@##@@@@@@###########@@=+=
#################%**+:---%+----:@@%-----%:----*@@#@######@@@@@###########@==+
#######@########@%%:%*--@@@=----=%:---*%@%*--@@@@#######@@##@@###########@===
################@*@%@*-:@@@=----*+----+@@@:-:@@@#######@@@@@@@###########@===*/


main() {
    long long ans = 0;
    string a;
    cin >> a;
    for (int i = 0; i < a.length() - 1; i++){
        //cout << int(a[i] - '0') * 10 + int(a[i+1] - '0') << ' ';
        if ((int(a[i] - '0') * 10 + int(a[i+1] - '0')) % 4 == 0){
            ans += i + 1;
        }
        if (int(a[i] - '0') % 4 == 0){
            ans++;
        }
    }
    if (int(a[a.length() - 1] - '0') % 4 == 0){
        ans++;
    }
    cout << ans;
}