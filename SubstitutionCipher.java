import java.util.Scanner;

public class SubstitutionCipher {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String a = "abcdefghijklmnopqrstuvwxyz";
        String b = "zyxwvutsrqponmlkjihgfedcba";

        System.out.println("Enter any string :");
        String str = sc.nextLine();
        String cipher = "";

        char c;

        for (int i = 0; i < str.length(); i++) {

            c = str.charAt(i);
            int j = a.indexOf(c);
            cipher = cipher + b.charAt(j);

        }
        System.out.println("The encrypted data is :" + cipher);
    }
}