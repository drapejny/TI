import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;

public class LFSR {
    private int registerLength;
    private long register;
    private long taps;


    public LFSR(String startSequence, int... tapPositions) {
        for (int i = 0; i < tapPositions.length; i++) {
            long tap = 1;
            tap <<= tapPositions[i] - 1;
            taps |= tap;
        }
        registerLength = startSequence.length();
        register = new BigInteger(startSequence, 2).longValue();
    }

    public byte getKeyByte() {
        byte ketByte = (byte) (register >> (registerLength - 8));
        shiftRegister();
        return ketByte;
    }

    public void shiftRegister() {
        for (int i = 0; i < 8; i++) {
            long tapBits = register & taps;
            int onesCounter = 0;
            for (int j = 0; j < registerLength; j++) {
                if ((tapBits & 1) == 1)
                    onesCounter++;
                tapBits >>= 1;
            }
            register <<= 1;
            if (onesCounter % 2 == 1)
                register |= 1;
        }
    }
}
