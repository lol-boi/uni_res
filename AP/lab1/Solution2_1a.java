import java.util.*;

class Solution2_1a{
    public static void main(String[] args){      
        int[] array = {1,3,5,10,12412,11}; 
        int sum = 0; 
        for (int i = 0; i<array.length; ++i){
                for(int j =0; j<array.length; ++j){
                    int xor = array[i] ^ array[j];
                    while(xor != 0){
                        sum++;
                        xor = xor & (xor-1);
                    }
                }
        } 
        System.out.println(sum);
    }
}
