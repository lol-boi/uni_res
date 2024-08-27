import java.util.*;

class Solution2_1b{
    public static void main(String[] args){
        Vector<Integer> v = new Vector<>();   
        v.add(1);
        v.add(3);
        v.add(5);
        v.add(10);
        v.add(12412);
        v.add(11);
        int sum = 0;
        for(int count = v.size(); count>1; --count){
            if(v.size()== 1){
                break;
            }
            for(int j = 1; j<v.size(); j++){
                int xor = v.get(0) ^ v.get(j);
                while(xor != 0){
                    sum++;
                    xor  = xor & (xor-1);
                } 
            } 
            v.remove(0);
        }
        System.out.println(sum*2); 
    }
}
