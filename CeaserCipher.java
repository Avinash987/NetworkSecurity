import java.util.*;

public class CeaserCipher {
    public static StringBuffer encrypt(String text, int key) {
        StringBuffer result = new StringBuffer();
        for (int i = 0; i < text.length(); i++) {
            if (Character.isUpperCase(text.charAt(i))) {

                char ch = (char) (((int) text.charAt(i) + key - 65) % 26 + 65);
                result.append(ch);
            } else {
                char ch = (char) (((int) text.charAt(i) + key - 97) % 26 + 97);
                result.append(ch);
            }

        }
        return result;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String text = in.nextLine();
        int keySize = in.nextInt();
        System.out.println("Text            :" + text);
        System.out.println("Shift key size  :" + keySize);
        System.out.println("Cipher          :" + encrypt(text, keySize));
    }
}