import java.security.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.ReturnInstruction;

public class SHA1 {
    public static void main(String agr[])
    {
        MessageDigest md  = new MessageDigest();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your Msg :");
        String input = sc.nextLine();

        md.update(input.getBytes())
        byte[] output = md.digest();
        System.out.println();
        System.out.print("SHA1");
        System.out.print(" "+input);
        System.out.println(" "+bytesToHex(output));
        System.out.println(output);

    }

    public static String bytesToHex(byte[] b)
    {
        char hexDigit[] = {'0','1','2','3','4','5','6','7'.....'F'};

        StringBuffer buf = new StringBuffer();
        for (int i = 0; i < b.length ; i++) {

            buf.append(hexDigit[(b[j]>>4) & 0x0F]);
            buf.append(hexDigit[b[j] & 0x0F]);
        }
        Return buf.toString();
    }

}