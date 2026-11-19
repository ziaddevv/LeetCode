class Solution {
public:
    void getValues(string str, int& x, int& intger) {

        if (str[0] != '+' && str[0] != '-') {
            str = '+' + str;
        }
        int n = str.size();

        for (int i = 0; i < n;) {

            bool sign = false;

            if (str[i] == '-') {
                sign = false;
            } else {
                sign = true;
            }

            int temp    = i;

            int z = i + 1;
            bool isX = false;
            string value = "";
            for (; z < n && str[z] != '+' && str[z] != '-'; z++) {
                if (str[z] >= '0' && str[z] <= '9') {
                    value = value + str[z];
                }

                if (str[z] == 'x') {
                    isX = true;
                }
            }
            i = z;


            int v = 1;
            if (value.size() != 0) {
                v = stoi(value);
            }

            if (!sign) {
                v *= -1;
            }

            if (isX) {
                x += v;
            } else {
                intger += v;
            }
        }

    }
    string solveEquation(string equation) {
        string left = "";
        string right = "";
        bool eq = false;
        int n = equation.size();
        for (int i = 0; i < n; i++) {

            if (equation[i] == '=') {
                eq = true;
                continue;
            }
            if (eq == false) {
                left += equation[i];
            } else {
                right += equation[i];
            }
        }


        int x1 = 0;
        int intger1 = 0;

        getValues(left, x1, intger1);

        int x2 =0;
        int intger2 =0;
        
        getValues(right, x2, intger2);


        int a = x1-x2;

        int b = intger2-intger1;

        if (a==0 && b ==0)return "Infinite solutions";

        if((a==0 && b != 0)||(a!=0 && b !=0)&&(b%a!=0)) return "No solution" ;

 
        return "x=" + to_string(b/a);

        return "";
    }
};