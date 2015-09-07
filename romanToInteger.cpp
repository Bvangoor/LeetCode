class Solution {
public:
    int romanToInt(string s) {
        
char *array = (char *)s.c_str();
int count=0,i=0;
while (i<s.length()){
    switch(array[i]){
        case 'I' :
            if(((i+1)<s.length())&&(array[i+1]=='X')){
                count=count+9;
                i=i+2;
                break;
                }
            if(((i+1)<s.length())&&(array[i+1]=='V')){
                count=count+4;
                i=i+2;
                break;
                }
            count=count+1;
            i=i+1;
            break;
        case 'X' :
            if(((i+1)<s.length())&&(array[i+1]=='L')){
                count=count+40;
                i=i+2;
                break;
                }
            if(((i+1)<s.length())&&(array[i+1]=='C')){
                count=count+90;
                i=i+2;
                break;
                }
            count=count+10;
            i=i+1;
            break;
        case 'V' :
            count=count+5;
            i=i+1;
            break;
        case 'L' :
            count=count+50;
            i=i+1;
            break;
        case 'C' :
            if(((i+1)<s.length())&&(array[i+1]=='M')){
                count=count+900;
                i=i+2;
                break;
                }
            if(((i+1)<s.length())&&(array[i+1]=='D')){
                count=count+400;
                i=i+2;
                break;
                }
            count=count+100;
            i=i+1;
            break;
        case 'D' :
            count=count+500;
            i=i+1;
            break;
        case 'M' :
            count=count+1000;
            i=i+1;
            break;
        default :
            i=i+1;
            break;
    }
}
return count;
}
};
