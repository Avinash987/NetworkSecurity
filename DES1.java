import java.util.Scanner;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.security.InvalidKeyException;
import java.security.spec.KeySpec;
import javax.crypto.*;
import javax.crypto.spec.DESKeySpec;
import sun.misc.BASE64Decoder;
import sun.misc.BASE64Encoder;

public class DES1 {

    private static final String UNICODE_FORMAT = "UTF8";
    public static final String ENCRYPTION_SCHEME = "DES";
    private KeySpec myKeySpec;
    private SecretKeyFactory mySecretKeyFactory;
    private Cipher cipher;
    byte[] keyAsBytes;
    private String myEncryptionKey;
    private String myEncryptionScheme;
    SecretKey key;

    public DES1(String myEncKey) throws Exception
    {
        myEncryptionKey = myEncKey;

        keyAsBytes = myEncryptionKey.getBytes(UNICODE_FORMAT);
        myKeySpec = new DESKeySpec(keyAsBytes);
        mySecretKeyFactory = SecretKeyFactory.getInstance(ENCRYPTION_SCHEME);
        cipher = Cipher.getInstance(ENCRYPTION_SCHEME);
        key = mySecretKeyFactory.generateSecret(myKeySpec);
    }

    public String encrypt(String unencryptedString)
    {
        String encryptedString = null;
        try
        {
            cipher.init(Cipher.ENCRYPT_MODE, key);
            byte[] plainText = unencryptedString.getBytes(UNICODE_FORMAT);
            byte[] encryptedText = cipher.doFinal(plainText);
            BASE64Encoder base64encoder = new BASE64Encoder();
            encryptedString = base64encoder.encode(encryptedText);
        }
         catch (InvalidKeyException | UnsupportedEncodingException | IllegalBlockSizeException | BadPaddingException e) {
        }
        return encryptedString;
    }

    public String decrypt(String encryptedString)
     {
        String decryptedText = null;
        try {
            cipher.init(Cipher.DECRYPT_MODE, key);
            BASE64Decoder base64decoder = new BASE64Decoder();
            byte[] encryptedText = base64decoder.decodeBuffer(encryptedString);
            byte[] plainText = cipher.doFinal(encryptedText);
            decryptedText = bytes2String(plainText);
        }
        catch (InvalidKeyException | IOException | IllegalBlockSizeException | BadPaddingException e) {
        }
        return decryptedText;
    }

    private static String bytes2String(byte[] bytes)
    {
        StringBuilder stringBuffer = new StringBuilder();
        for (int i = 0; i < bytes.length; i++)
        {
            stringBuffer.append((char) bytes[i]);
        }
        return stringBuffer.toString();
    }

    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the 8 bytes key for DES:");
        String Key = sc.nextLine();
        DES1 myEncryptor = new DES1(Key);
        System.out.println("Enter the String to be Encryprted:");

        String stringToEncrypt = sc.nextLine();
        String encrypted = myEncryptor.encrypt(stringToEncrypt);
        String decrypted = myEncryptor.decrypt(encrypted);
        System.out.println("String To Encrypt: " + stringToEncrypt);
        System.out.println("Encrypted Value : " + encrypted);
        System.out.println("Decrypted Value : " + decrypted);
    }
}