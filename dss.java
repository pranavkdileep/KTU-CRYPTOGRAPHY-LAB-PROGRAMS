import java.security.*;

import java.security.spec.*; import java.util.Base64;

public class DSASignature Example {

public static void main(String[] args) throws Exception {

// Generate keypair KeyPairGenerator keyGen = KeyPairGenerator.getInstance("DSA"); SecureRandom random = SecureRandom.getInstanceStrong(); keyGen.initialize(1024, random); KeyPair keyPair = keyGen.generateKeyPair();

String message = "Hello, World!";

// Create signature Signature signature = Signature.getInstance("SHA256withDSA"); signature.initSign(keyPair.getPrivate());

signature.update(message.getBytes()); byte[] digitalSignature = signature.sign();

// Display the digital signature System.out.println("Digital Signature: Base64.getEncoder().encodeToString(digitalSignature));

// Verification

Signature verifier = Signature.getInstance("SHA256withDSA");

verifier.init Verify(keyPair.getPublic());

verifier.update(message.getBytes());

boolean verified = verifier.verify(digitalSignature); System.out.println("Signature verified: " + verified);

}
}
