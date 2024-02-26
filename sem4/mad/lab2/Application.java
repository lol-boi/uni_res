import java.io.*;

class Mother{
    int x = 1;
    public void show() {
       System.out.println("Mother"); 
    }
/*    public static void show(){
        System.out.println("Mother");
    }*/
}

class Child extends Mother{
    public void show(){
        System.out.println("This is child class.");
    }
/*    public static void show() {
        System.out.println("This is child class."); 
    }*/
}

public class Application {
    public static void main(String[] args) {
        Mother m = new Mother();
        m.show();

        Child ch = new Child();
        ch.show(); 
       
        Mother m1 = new Child(); 
        m1.show();
    }    
}
