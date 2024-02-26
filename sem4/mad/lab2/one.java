import java.io.*;

class one{
    int x; 
    one(int x){
        this.x = x; 
    }
}


class two extends one{
    two(int x) {
        super(x); //rectified error 
    }    
}
