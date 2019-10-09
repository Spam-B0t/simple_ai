package spambot.simplebot;

import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;

public class Main {

    final static Scanner in = new Scanner(System.in);

    public static void main(String args[]){
        String botname="ai", username;
        int bdyear=2019, userage;
        
        greet(botname, bdyear);
        username = remindName();
        userage = guessAge();
        count();
        question();
    }
    
    
    
    static void greet(String botname, int bdyear) {
        System.out.println("Hello! My name is " + botname + ".");
        System.out.println("I was created in " + bdyear + ".");
    }
    
    static String remindName() {
        //Scanner in = new Scanner(System.in);
        System.out.println("Please, remind me your name.");
        String name = in.nextLine();
        System.out.println("What a great name you have, " + name + "!");
        
        return name;
    }
    
    static int guessAge(){
        //Scanner in = new Scanner(System.in);
        
        System.out.println("Let me guess your age.");
        System.out.println("Enter remainders of dividing your age by 3, 5 and 7.");
        
        int rem3=in.nextInt(), rem5=in.nextInt(), rem7=in.nextInt();
        int userage = (rem3 * 70 + rem5 * 21 + rem7 * 15) % 105;
        
        System.out.println("Your age is " + userage + "; that's a good time to start programming!");
        
        return userage;
    }
    
    static void count(){
        //Scanner in = new Scanner(System.in);
        System.out.println("Now I will prove to you that I can count to any number you want.");
        
        int n=in.nextInt();
        for(int i=0; i<=n; i++) System.out.println(""+i+'!');
    }
    
    static void question(){
      String questions[]={"2+2=", "What is java", "What is the answer to life, the universe and everything"};
      String answers[][]={{"4", "four", "-5 mod 9"}, {"coffee", "programing language"}, {"idk", "42"}};
      Random rand = new Random();
      int randNum = rand.nextInt(questions.length);
      
      System.out.println("Let's test your knowledge.");
      System.out.println(questions[randNum]+'?');
      String ans = in.nextLine();
      while(!Arrays.asList(answers[randNum]).contains(ans)){
          System.out.println("Please, try again.");
          ans = in.nextLine();
      }
      System.out.println("That's right! Nice job!");
      
    }
}
