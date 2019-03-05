class Solution {
private :
    string lookup1[21] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
    string lookup2[11] = {"Zero","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety","Hundred"};
    string lookup3[3] = {"Thousand","Million","Billion"};
public:
    string aux(int num) {
        if (num == 0)
            return "";
        else {
            if (num >= 1000000000) {
                if (num%1000000000 > 0)
                    return lookup1[num/1000000000] + " " + lookup3[2] + " " + aux(num%1000000000);
                return lookup1[num/1000000000] + " " + lookup3[2];
            }
            else if (num >= 1000000) {
                if (num%1000000 > 0)
                    return aux(num/1000000) + " " + lookup3[1] + " " + aux(num%1000000);
                return aux(num/1000000) + " " + lookup3[1];
            }
            else if (num >= 1000) {
                if (num%1000 > 0)
                    return aux(num/1000) + " " + lookup3[0] + " " + aux(num%1000);
                return aux(num/1000) + " " + lookup3[0];
            }
            else if (num >= 100) {
                if (num%100 > 0)
                    return lookup1[num/100] + " " + lookup2[10] + " " + aux(num%100);
                return lookup1[num/100] + " " + lookup2[10];
            }
            else if (num > 20) {
                if (num % 10 > 0)
                    return lookup2[num/10] + " " + aux(num%10);
                return lookup2[num/10];
            }
            else 
                return lookup1[num];
        }
    }
    
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        else
            return aux(num);
    }
};
