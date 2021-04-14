public class Converting {
    public byte[] binStrToBytes(String s){
        byte[] bytes = new byte[s.length() / 8];
        int start = 0;
        int end = 8;
        int counter = 0;
        while(end <= s.length() ){
            bytes[counter] = Byte.parseByte(s.substring(start,end), 2);
            start += 8;
            end += 8;
        }
        return bytes;
    }
}
